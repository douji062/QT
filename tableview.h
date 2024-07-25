#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QWidget>
#include<QSqlTableModel>

namespace Ui {
class tableview;
}

class tableview : public QWidget
{
    Q_OBJECT

public:
    explicit tableview(QSqlTableModel *m,QWidget *parent = nullptr);
    ~tableview();

private:
    Ui::tableview *ui;
    QSqlTableModel *model;
};

#endif // TABLEVIEW_H
