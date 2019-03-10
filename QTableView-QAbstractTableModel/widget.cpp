#include "widget.h"
#include "ui_widget.h"
#include "tablemodel.h"
#include <QTableView>
#include "thread.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QTableView *pTableView = new QTableView(this);
    pModel = new TableModel(this);
    // 设置单行选中、最后一列拉伸、表头不高亮、无边框等
    pTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    pTableView->horizontalHeader()->setStretchLastSection(true);
    pTableView->horizontalHeader()->setHighlightSections(false);
    pTableView->verticalHeader()->setVisible(false);
    pTableView->setShowGrid(false);
    pTableView->setFrameShape(QFrame::NoFrame);
    pTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    pTableView->setModel(pModel);

//    // 加载数据、更新界面
//    QList<FileRecord> recordList;
//    for (int i = 0; i < 5; ++i)
//    {
//        FileRecord record;
//        record.bChecked = false;
//        record.strFilePath = QString("E:/Qt/image_%1.png").arg(i + 1);
//        recordList.append(record);
//    }

//    pModel->updateData(recordList);

    pTableView->setStyleSheet("background:gray;color:black;");
    startThread();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::startThread()
{
    qDebug() << "main thread :" << QThread::currentThreadId();
    //新建线程跟主线程在一个线程中
    Thread *m_thread = new Thread(this);
    connect(m_thread, SIGNAL(resultReady(int)), this, SLOT(updateTable(int)));
    // 线程结束后，自动销毁
    connect(m_thread, SIGNAL(finished()), m_thread, SLOT(deleteLater()));
    m_thread->start();

}

void Widget::updateTable(int n)
{
    // 加载数据、更新界面

    FileRecord record;
    record.bChecked = false;
    record.strFilePath = QString("E:/Qt/image_%1.png").arg(n);
    recordList.append(record);

    pModel->updateData(recordList);
}
