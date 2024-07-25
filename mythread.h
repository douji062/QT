#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QDebug>

class myThread : public QThread//不用继承QObject因为Qthread也继承QObject
{
    Q_OBJECT//写了才能使用信号与槽
public:
    explicit myThread(QTcpSocket *s);
    void run();//线程处理函数

signals:
    void sendToWidget(QByteArray b);

public slots:
    void clintInfoSlot();

private:
    QTcpSocket *socket;
};

#endif // MYTHREAD_H
