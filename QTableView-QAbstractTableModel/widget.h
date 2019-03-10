#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "thread.h"
#include "tablemodel.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void startThread();

private slots:
    void updateTable(int);

private:
    Ui::Widget *ui;
    TableModel *pModel;
    QList<FileRecord> recordList;
};

#endif // WIDGET_H
