#include "UpdateService.h"
#include <QFile>

UpdateService::UpdateService(QObject *parent)
    :QObject(parent)
{
    _udp = new QUdpSocket(parent);

    // @Note: An incoming datagram should be read when you receive the readyRead()
    //        signal, otherwise this signal will not be emitted for the next
    //        datagram.
    connect(_udp, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
    _udp->bind(QHostAddress::Any, UPDATE_UDP_SERVER_PORT);
    g_debug() << "update service started at port" << UPDATE_UDP_SERVER_PORT;
}

UpdateService::~UpdateService()
{
    if(_udp){
        _udp->deleteLater();
    }
}

void UpdateService::handlePendingDatagrams(QByteArray &datagram, uint32_t ip4, quint16 port)
{
    char* data = datagram.data();
    unsigned int data_len = datagram.size();
    if(data_len <= sizeof(MsgUpdateHdr)){
        g_error() << "data too short" << data_len;
        return ;
    }
    MsgUpdateHdr* head = (MsgUpdateHdr*)data;

    char* content = data+sizeof(MsgUpdateHdr);
    unsigned int content_len = head->dataLen;

    if (head->head != UMSG_HEAD)
    {
        g_error() << "head";
        return ;
    }

    if(head->type != UMSG_TYPE_DATA){
        g_error() << "type";
        return ;
    }

    if(data_len != content_len+sizeof(MsgUpdateHdr)){
        g_error() << "data len" << data_len << content_len;
        return ;
    }

    if(process.busy){
        if(process.srcIp4 != ip4){
            g_error() << "reject other update request.";
            return ;
        }else{
            if(process.total != head->totalBytes){
                g_error() << "total bytes not matched";
                return ;
            }
        }
    }else{
        process.total = head->totalBytes;
        process.recved = 0;
        process.srcIp4 = ip4;
        process.busy = true;
    }

    // 处理数据和发送回复
    bool done = ISSET(head->flags, MsgUpdateFlagsFull);
    MsgUpdateHdr response;
    response = *head;
    response.type = UMSG_TYPE_ACK;
    if(process.appendData(content, content_len, done)){
        response.retCode = UMSG_CODE_SUCCEED;
        //g_debug() << "recved" << process.recved << process.total;
        if(done){
            g_debug() << "recved file done";
        }
    }else{
        response.retCode = UMSG_CODE_FAILED;
    }
    // 发送回复
    QUdpSocket sock;
    qint64 sentLen = sock.writeDatagram((char*)&response,
                       sizeof(MsgUpdateHdr),
                       QHostAddress(ip4),
                       port);
    if(sentLen != sizeof(MsgUpdateHdr)){
        g_error() << "sent";
    }
}

void UpdateService::readPendingDatagrams()
{
    while (_udp->hasPendingDatagrams()) {
        QByteArray datagram;
        QHostAddress host;
        quint16 port;
        uint32_t ip4addr;
        while (_udp->hasPendingDatagrams()) {
            datagram.resize(_udp->pendingDatagramSize());
            _udp->readDatagram(datagram.data(), datagram.size(), &host, &port);
            ip4addr = host.toIPv4Address();
            handlePendingDatagrams(datagram, ip4addr, port);
        }
    }
}

void UpdateService::stateChanged(QAbstractSocket::SocketState state)
{
    if(state == QAbstractSocket::BoundState){
        // clean the data
        while (_udp->hasPendingDatagrams()) {
            _udp->readAll();
        }
    }
}
