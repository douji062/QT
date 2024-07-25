#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)//通过初始化列表来初始化指针
{
    ui->setupUi(this);

    connect(ui -> cmdlineEdit,SIGNAL(returnPressed()),this,SLOT(on_commitButton_clicked()));//连接信号与槽 谁发出信号 发出什么信号 谁处理信号 怎么处理

    connect(ui -> cancelButton,&QPushButton::clicked,this,&Widget::on_cancelButton_clicked);

    connect(ui ->browseButton,&QPushButton::clicked,[this](){

        QMessageBox::information(this,"信息","点击浏览");
    });

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_commitButton_clicked()
{
    //获取lineedit
    QString program = ui->cmdlineEdit->text();
    //创建process对象
    QProcess *myProcess = new QProcess(this);
    myProcess->start(program);
}



void Widget::on_cancelButton_clicked()
{
    this -> close();
}
