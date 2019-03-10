#include "widget.h"
#include <QApplication>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile file("style.qss");
    if(file.open(QFile::ReadOnly))
    {
        a.setStyleSheet(file.readAll());
        file.close();
    }
    else
    {
        qDebug() << "open file failed";
        qDebug() << file.error();
        qDebug() << file.errorString();
    }


    Widget w;
    w.show();

    return a.exec();
}
