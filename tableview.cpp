#include "tableview.h"
#include "ui_tableview.h"

tableview::tableview(QSqlTableModel *m,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tableview)
{
    ui->setupUi(this);
    model = m;
    ui->tableView->setModel(model);
}

tableview::~tableview()
{
    delete ui;
}
