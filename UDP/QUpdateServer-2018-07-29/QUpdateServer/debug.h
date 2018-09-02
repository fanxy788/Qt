#ifndef DEBUG_H
#define DEBUG_H

#include <QDateTime>
#include <QString>
#include <QDebug>

#define DEBUG (1)
#if DEBUG
#define g_debug()   qDebug()    << QTime::currentTime().toString("hh:mm:ss.zzz") << "[DBG][" << __FUNCTION__ << "]"
#else
#define g_debug()   if(false)\
                        qDebug() << QTime::currentTime().toString("hh:mm:ss.zzz") << "[DBG][" << __FUNCTION__ << "]"
#endif

#define USE_LOG4QT                      (0)
#define USE_QLOG                        (1)

#if USE_QLOG
#define g_fatal()   qFatal()    << QTime::currentTime().toString("hh:mm:ss.zzz") << "[FAT][" << __FUNCTION__ << "]"
#define g_error()   qCritical() << QTime::currentTime().toString("hh:mm:ss.zzz") << "[ERR][" << __FUNCTION__ << "]"
#define g_info()    qDebug()    << QTime::currentTime().toString("hh:mm:ss.zzz") << "[INF][" << __FUNCTION__ << "]"
#define g_warn()    qWarning()  << QTime::currentTime().toString("hh:mm:ss.zzz") << "[WAR][" << __FUNCTION__ << "]"
#endif

// 常规位操作定义
#define SET(where, flags)       (where) |= (flags)
#define CLR(where, flags)       (where) &= ~(flags)
#define ISSET(where, flags)     ((where) & (flags))
#define ISNOTSET(where,flags)   (!(where & flags))



#endif // DEBUG_H
