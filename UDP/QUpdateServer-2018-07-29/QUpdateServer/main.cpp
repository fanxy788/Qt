#include <QApplication>
#include "UpdateService.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow main;
    UpdateService service(&a);
    main.show();
    return a.exec();
}
