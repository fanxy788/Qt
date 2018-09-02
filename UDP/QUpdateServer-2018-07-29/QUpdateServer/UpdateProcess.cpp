#include "UpdateProcess.h"
#include <QFile>

UpdateProcess::UpdateProcess()
{
    busy = false;
    total = 0;
    recved = 0;
    srcIp4 = 0;
    saveFileName = QString("./recved.bin");
}

UpdateProcess::~UpdateProcess()
{
    if(fout.isOpen()){
        fout.close();
    }
}

bool UpdateProcess::appendData(const char *data, unsigned int len, bool done)
{
    if(!fout.isOpen()){
        fout.setFileName(saveFileName);
        if (!fout.open(QIODevice::WriteOnly | QIODevice::Truncate))
            return false;
          stream = new QDataStream(&fout);
    }

    if(!stream){
        return false;
    }

    bool ok = (len == (unsigned int)stream->writeRawData(data, len));
    if(ok){
        this->recved += len;
        if(done){
            // 文件完成
            delete stream;
            stream = NULL;

            fout.close();
            busy = false;
        }
    }
    return ok;
}
