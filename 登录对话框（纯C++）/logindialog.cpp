#include "logindialog.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent):
    QDialog(parent)
{
    usrLabel = new QLabel(this);
    usrLabel->move(70, 80);
    usrLabel->setText(tr("用户名："));
    usrLineEdit = new QLineEdit(this);
    usrLineEdit->move(140, 80);
    usrLineEdit->setPlaceholderText(tr("请输入用户名"));

    pwdLabel = new QLabel(this);
    pwdLabel->move(70, 130);
    pwdLabel->setText(tr("密码："));
    pwdLineEdit = new QLineEdit(this);
    pwdLineEdit->move(140, 130);
    pwdLineEdit->setPlaceholderText(tr("请输入密码"));
    //设置密码显示样式
    pwdLineEdit->setEchoMode(QLineEdit::Password);

    loginBtn = new QPushButton(this);
    loginBtn->move(50, 200);
    loginBtn->setText(tr("登录"));
    exitBtn = new QPushButton(this);
    exitBtn->move(210, 200);
    exitBtn->setText(tr("退出"));

    connect(loginBtn, SIGNAL(clicked()), this, SLOT(login()));
    connect(exitBtn, SIGNAL(clicked()), this, SLOT(close()));
}

LoginDialog::~LoginDialog()
{

}

void LoginDialog::login()
{
    //判断用户名和密码是否正确
    //错误弹出警告对话框
    if(usrLineEdit->text().trimmed() == tr("yafei")
            && pwdLineEdit->text() == tr("123456"))
    {
        accept();
    }else{
        QMessageBox::warning(this, tr("警告"),
                             tr("用户名或密码错误"),
                             QMessageBox::Yes);
        //清空内容并定位光标
        usrLineEdit->clear();
        pwdLineEdit->clear();
        usrLineEdit->setFocus();
    }
}
