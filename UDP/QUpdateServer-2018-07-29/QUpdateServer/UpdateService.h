#ifndef UPDATESERVICE_H
#define UPDATESERVICE_H

#include <QThread>
#include <QString>
#include <QTimer>
#include <QtNetwork/QUdpSocket>
#include "debug.h"
#include "UpdateProcess.h"

#pragma pack(1)
#define UPDATE_UDP_SERVER_PORT  (9311)
#define UPDATE_UDP_CLIENT_PORT  (9312)
#define UMSG_HEAD               (0x1234)

enum{
    UMSG_TYPE_DATA,
    UMSG_TYPE_ACK
};

enum{
    UMSG_CODE_SUCCEED,
    UMSG_CODE_FAILED
};

#define MsgUpdateFlagsFull  (1<<0)
typedef struct _MsgUpdateHdr{
    ////////////////////////////////////////
    // 固定头 0x1234
    unsigned short head;
    // data 0x1, 客户端向服务器发送升级数据
    // ack  0x2, 服务器向客户端发送ack
    unsigned char type;
    unsigned char flags;
    // 0: 成功
    // 1: 接收失败，需重传
    unsigned short retCode;
    ////////////////////////////////////////
    // 文件总大小
    unsigned int totalBytes;
    // 当前数据偏移
    unsigned int dataOffset;
    // 当前数据长度
    unsigned int dataLen;
}MsgUpdateHdr;
#pragma pack()

class UpdateService : QObject
{
    Q_OBJECT
public:
    UpdateService(QObject* parent=0);
    ~UpdateService();
public:
private:
    QUdpSocket* _udp;
    UpdateProcess process;
    void handlePendingDatagrams(QByteArray &datagram, uint32_t ip4, quint16 port);
private slots:
    void readPendingDatagrams();
    void stateChanged(QAbstractSocket::SocketState state);
};

#endif // UPDATESERVICE_H
