#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowFlag(Qt::FramelessWindowHint);

    this->installEventFilter(new DragWidgetFilter(this));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_radioButton_clicked()
{
    if(ui->radioButton->isChecked())
    {
        ui->login_pushButton->setStyleSheet("background-color: rgb(0, 141, 255);");
        ui->login_pushButton->setEnabled(true);
    }
    else
    {
        ui->login_pushButton->setStyleSheet("backgroun d-color: rgb(158, 218, 255);");
        ui->login_pushButton->setEnabled(false);
    }
}


void Widget::on_login_pushButton_clicked()
{
    qDebug() << "登录";
}


void Widget::on_close_toolButton_clicked()
{
    this->close();
}

