#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QAction>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->action_open, SIGNAL(triggered()), this, SLOT(slot_open()));
    connect(ui->action_exit, SIGNAL(triggered()), this, SLOT(slot_exit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_open()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open File"),
                                                    "/home/yixiaoyang/",
                                                    tr("Text Files (*.h *.cpp *.txt)"));
    QFile file(fileName);
    if(file.open(QFile::ReadOnly)){
        QByteArray bytes = file.readAll();
        ui->textBrowser->setText(bytes);
    }else{
        QMessageBox:: critical(this,
                               QString::fromUtf8("文件打开错误"),
                               QString::fromUtf8("无法找到文件"),
                               QMessageBox::Ok | QMessageBox::Cancel | QMessageBox::SaveAll,
                               QMessageBox::Ok);
    }
}

void MainWindow::slot_exit()
{
    this->close();
}
