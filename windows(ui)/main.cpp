#include "mainwindow.h"
#include <QApplication>
#include "logindlg.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    LoginDlg dlg;
    if(dlg.exec() == QDialog::Accepted)
    {
        w.show();
        return a.exec();
    }
    else
        return 0;

}
