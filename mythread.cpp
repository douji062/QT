#include "mythread.h"

myThread::myThread(QTcpSocket *s)
{
    socket = s;
}


void myThread::run()
{

    connect(socket,&QTcpSocket::readyRead,this,&myThread::clintInfoSlot);//处理客户端信息

}
//没有ui操作是因为不能在其他类里操作界面（ui是UI:Widget私有成员变量）
//所以采用qDebug的方式打印出来
//或者直接处理成信号然后发送到Widget然后在widget界面再用ui操作显示
void myThread::clintInfoSlot(){
    //qDebug()<<socket->readAll();

    //qt可以自定义信号
    QByteArray ba = socket->readAll();
    emit sendToWidget(ba);//发送信号
}
