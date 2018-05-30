#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logindlg.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setText(tr("新窗口"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

