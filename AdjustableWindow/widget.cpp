#include "widget.h"

SlidingWindow::SlidingWindow(QWidget *parent)
    : QWidget(parent, Qt::FramelessWindowHint)
    , bPressFlag(false)
{
    resize(660, 460);
    splitter = new QSplitter(Qt::Horizontal, this);
    splitter->setHandleWidth(1);
    splitter->setStyleSheet("QSplitter::handle{background:#FFFFFF}");
    contentFrame = new QFrame(splitter);
    contentFrame->setStyleSheet("background:#000000");
    contentFrame->resize(475, height());
    contentFrame->setMinimumWidth(405);
    listFrame = new QFrame(splitter);
    listFrame->setStyleSheet("background:#323232");
    listFrame->resize(660 - 475, height());
    listFrame->setMaximumWidth(660 - 405);
    connect(splitter, SIGNAL(splitterMoved(int,int)), this, SLOT(slotSplitterMoved(int,int)));

    leftIcon = QIcon(":/new/left.png");
    rightIcon = QIcon(":/new/right.png");

    pushButton = new QPushButton(this);
    pushButton->setFocusPolicy(Qt::NoFocus);
    pushButton->hide();
    pushButton->setFixedSize(13, 42);
    pushButton->setIconSize(pushButton->size());
    pushButton->setStyleSheet("border:none;");
    pushButton->setIcon(rightIcon);
    pushButton->move(contentFrame->width() - pushButton->width()-2, (contentFrame->height() - pushButton->height())/2);
    connect(pushButton,SIGNAL(clicked()),this,SLOT(slotClickedBtn()));

    contentFrame->setMouseTracking(true);
    listFrame->setMouseTracking(true);
    contentFrame->installEventFilter(this);
    listFrame->installEventFilter(this);
}

SlidingWindow::~SlidingWindow()
{

}

void SlidingWindow::resizeEvent(QResizeEvent *event)
{
    splitter->setGeometry(0, 0, width(), height());
    //move((QApplication::desktop()->width() - width())/2,  (QApplication::desktop()->height() - height())/2);
    QWidget::resizeEvent(event);
}

bool SlidingWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseMove) {
        QMouseEvent *mouseMove = static_cast<QMouseEvent*>(event);
        QRect rect = pushButton->frameGeometry();
        if (rect.contains(mouseMove->pos())) {
            pushButton->show();
        }
        else {
            pushButton->hide();
        }
    }
    return QWidget::eventFilter(obj, event);
}

void SlidingWindow::setBtnPos()
{
    pushButton->move(contentFrame->width() - pushButton->width(), (contentFrame->height() - pushButton->height())/2);
}

void SlidingWindow::setBtnIcon()
{
    if (listFrame->width() != 0) {
        pushButton->setIcon(rightIcon);
    }
    else {
        pushButton->setIcon(leftIcon);
    }
}

void SlidingWindow::slotClickedBtn()
{
    QList <int> sizeList;
    sizeList.clear();
    if (listFrame->width() != 0) {
        sizeList.append(660);
        sizeList.append(0);
    }
    else {
        sizeList.append(475);
        sizeList.append(660 - 475);
    }
    splitter->setSizes(sizeList);

    setBtnIcon();
    setBtnPos();
    pushButton->hide();
}

void SlidingWindow::slotSplitterMoved(int pos, int index)
{
    Q_UNUSED(pos)
    Q_UNUSED(index)
    setBtnIcon();
    setBtnPos();
}

void SlidingWindow::mousePressEvent ( QMouseEvent * event)
{
    bPressFlag = true;
    dragPosition = event->pos();
    QWidget::mousePressEvent(event);
}

void SlidingWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (bPressFlag) {
        QPoint relaPos(QCursor::pos() - dragPosition);
        move(relaPos);
    }
    QWidget::mouseMoveEvent(event);
}

void SlidingWindow::mouseReleaseEvent(QMouseEvent *event)
{
    bPressFlag = false;
    QWidget::mouseReleaseEvent(event);
}
