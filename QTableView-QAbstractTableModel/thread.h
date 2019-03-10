#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QDebug>


class Thread : public QThread
{
    Q_OBJECT
public:
    explicit Thread(QObject *parent = 0)
        :QThread(parent)
    {
        qDebug() << "thread:" << QThread::currentThreadId();
    }

protected:
    virtual void run() Q_DECL_OVERRIDE
    {
        qDebug() << "thread run:" << QThread::currentThreadId();
        int value = 0;
        while(value < 100)
        {
            msleep(50);
            ++value;
            emit resultReady(value);
            qDebug() << "value " << value;
        }
    }

signals:
    void resultReady(int);
};

#endif // THREAD_H
