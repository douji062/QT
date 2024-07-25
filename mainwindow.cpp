#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->newAction,&QAction::triggered,this,&MainWindow::newActionSlot);//没有右击转到槽所以使用槽函数的方式进行
    connect(ui->openAction,&QAction::triggered,this,&MainWindow::openActionSlot);
    connect(ui->saveAction,&QAction::triggered,this,&MainWindow::saveActionSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newActionSlot()
{
    ui->textEdit->clear();
    this->setWindowTitle("新建文本文档.txt");
}

void MainWindow::openActionSlot()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("选择一个文件"),
                                 QCoreApplication::applicationDirPath(),"*.cpp");
    if(fileName.isEmpty()){
        QMessageBox::warning(this,"警告","请选择一个文件");
    }else{
        //qDebug()<<fileName;
        QFile file(fileName);
        file.open(QIODevice::ReadOnly);
        QByteArray ba = file.readAll();
        ui->textEdit->setText(QString(ba));
        file.close();
    }
}

void MainWindow::saveActionSlot()
{
    QString fileName = QFileDialog::getOpenFileName(this,"选择一个文件",QCoreApplication::applicationDirPath());//选择当前路径
    if(fileName.isEmpty()){
        QMessageBox::warning(this,"警告","请选择一个文件");

    }else{
        QFile file(fileName);
        file.open(QIODevice::WriteOnly);///*d'f打开方式选择只读
        QByteArray ba;
        ba.append(ui->textEdit->toPlainText());//创建一个QByteArray对象并把textEdit的内容放进去
        file.write(ba);//储存文件
        file.close();//关闭
    }
}

//常见QT事件 键盘按下和松开；鼠标事件；拖放；滚轮；绘屏；定时；键盘焦点；进入和离开；widget移动；widget大小和改变；widget显示；窗口事件（是否为当前窗口）
//消息处理函数是虚函数要进行重载
//事件封装成QEvent类，使用需要重写event函数（事件总入口）
//QMouseEvent等专门的类
//QKeyEvent


void MainWindow::keyPressEvent(QKeyEvent *k){
    if(k->modifiers()==Qt::ControlModifier && k->key()==Qt::Key_S)//control＋s
    {
        saveActionSlot();
    }
}//事件怎么完成，重写虚函数


void MainWindow::mousePressEvent(QMouseEvent *m){
    QPoint pt = m->pos();
    qDebug()<<pt;

    if(m->button()==Qt::LeftButton)
    {
        qDebug()<<"左键被按下";
    }else if(m->button()==Qt::RightButton)
    {
        qDebug()<<"右键被按下";
    }
}
