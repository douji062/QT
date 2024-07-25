#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlTableModel>
#include <tableview.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_insertPushButton_clicked();

    void on_findPushButton_clicked();

private:
    Ui::Widget *ui;
    QSqlDatabase db;
};

#endif // WIDGET_H
