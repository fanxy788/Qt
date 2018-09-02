#ifndef UPDATEPROCESS_H
#define UPDATEPROCESS_H
#include <QFile>
#include <QDataStream>
#include <QString>

class UpdateProcess
{
public:
    UpdateProcess();
    ~UpdateProcess();
public:
    unsigned int total;
    unsigned int recved;
    unsigned int srcIp4;
    bool busy;
    QString saveFileName;
private:
    QDataStream* stream;
    QFile fout;

public:
    /**
     * @brief appendData
     * @param data 数据缓冲区
     * @param len 有效数据长度
     * @param done 是否写完数据
     * @return
     */
    bool appendData(const char* data, unsigned int len, bool done=false);
};

#endif // UPDATEPROCESS_H
