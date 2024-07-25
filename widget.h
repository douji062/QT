#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QProcess>
#include <QMessageBox>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT//宏定义

public:
    explicit Widget(QWidget *parent = nullptr);//有参构造函数
    ~Widget();//析构函数

private slots:
    void on_commitButton_clicked();//槽函数
    void on_cancelButton_clicked();

private:
    Ui::Widget *ui;//定义指针
};

#endif // WIDGET_H
