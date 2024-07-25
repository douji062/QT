#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
//    this->setMaximumSize(200,280);
//    this->setMinimumSize(200,280);
    this->setWindowTitle("计算器");

    QFont f("仿宋",10);
    ui->mainLineEdit->setFont(f);

    //改变按钮背景色
    ui -> equalButton ->setStyleSheet("background:lightblue");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_Button_1_clicked()
{
    expression += "1";
    ui -> mainLineEdit ->setText(expression);
}

void Widget::on_Button_2_clicked()
{
    expression += "2";
    ui -> mainLineEdit ->setText(expression);
}

void Widget::on_Button_3_clicked()
{
    expression += "3";
    ui -> mainLineEdit ->setText(expression);
}

void Widget::on_Button_4_clicked()
{
    expression += "4";
    ui -> mainLineEdit ->setText(expression);
}

void Widget::on_Button_5_clicked()
{
    expression += "5";
    ui -> mainLineEdit ->setText(expression);
}

void Widget::on_Button_6_clicked()
{
    expression += "6";
    ui -> mainLineEdit ->setText(expression);
}

void Widget::on_Button_7_clicked()
{
    expression += "7";
    ui -> mainLineEdit ->setText(expression);
}

void Widget::on_Button_8_clicked()
{
    expression += "8";
    ui -> mainLineEdit ->setText(expression);
}

void Widget::on_Button_9_clicked()
{
    expression += "9";
    ui -> mainLineEdit ->setText(expression);
}

void Widget::on_addButton_clicked()
{
    expression += "+";
    ui -> mainLineEdit ->setText(expression);
}

void Widget::on_subButton_clicked()
{
    expression += "-";
    ui -> mainLineEdit ->setText(expression);
}

void Widget::on_mulButton_clicked()
{
    expression += "*";
    ui -> mainLineEdit ->setText(expression);
}

void Widget::on_divButton_clicked()
{
    expression += "/";
    ui -> mainLineEdit ->setText(expression);
}

void Widget::on_Button_0_clicked()
{
    expression += "0";
    ui -> mainLineEdit ->setText(expression);
}

void Widget::on_leftButton_clicked()
{
    expression += "(";
    ui -> mainLineEdit ->setText(expression);

}

void Widget::on_rightButton_clicked()
{
    expression += ")";
    ui -> mainLineEdit ->setText(expression);
}

void Widget::on_equalButton_clicked()
{
    QStack<int> s_num;
    QStack<char> s_opt;
    char opt[128] = {0};
    int i = 0, tmp = 0, num1, num2;

    // Convert QString to char*
    QByteArray ba;
    ba.append(expression); // QString -> QByteArray

    strcpy(opt, ba.data()); // data can convert QByteArray to const char*

    while (opt[i] != '\0' || !s_opt.isEmpty()) {
        if (opt[i] >= '0' && opt[i] <= '9') {
            tmp = tmp * 10 + opt[i] - '0';
            i++;
            if (opt[i] < '0' || opt[i] > '9') {
                s_num.push(tmp);
                tmp = 0;
            }
        } else {
            if (s_opt.isEmpty() || Priority(opt[i]) > Priority(s_opt.top()) ||
                (s_opt.top() == '(' && opt[i] != ')')) {
                s_opt.push(opt[i]);
                i++;
            } else if (s_opt.top() == '(' && opt[i] == ')') {
                s_opt.pop();
                i++;
            } else {
                while (!s_opt.isEmpty() && (Priority(opt[i]) <= Priority(s_opt.top()))) {
                    char ch = s_opt.pop();
                    if (!s_num.isEmpty()) {
                        num1 = s_num.pop();
                    } else {
                        // Handle error: not enough operands
                        return;
                    }
                    if (!s_num.isEmpty()) {
                        num2 = s_num.pop();
                    } else {
                        // Handle error: not enough operands
                        return;
                    }
                    switch (ch) {
                        case '+':
                            s_num.push(num2 + num1);
                            break;
                        case '-':
                            s_num.push(num2 - num1);
                            break;
                        case '*':
                            s_num.push(num2 * num1);
                            break;
                        case '/':
                            s_num.push(num2 / num1);
                            break;
                    }
                }
                if (opt[i] != '\0') {
                    s_opt.push(opt[i]);
                    i++;
                }
            }
        }
    }

    // Process any remaining operators in the stack
    while (!s_opt.isEmpty()) {
        char ch = s_opt.pop();
        if (!s_num.isEmpty()) {
            num1 = s_num.pop();
        } else {
            // Handle error: not enough operands
            return;
        }
        if (!s_num.isEmpty()) {
            num2 = s_num.pop();
        } else {
            // Handle error: not enough operands
            return;
        }
        switch (ch) {
            case '+':
                s_num.push(num2 + num1);
                break;
            case '-':
                s_num.push(num2 - num1);
                break;
            case '*':
                s_num.push(num2 * num1);
                break;
            case '/':
                s_num.push(num2 / num1);
                break;
        }
    }

    if (!s_num.isEmpty()) {
        ui->mainLineEdit->setText(QString::number(s_num.top()));
        expression.clear();
    } else {
        // Handle error: final result missing
        return;
    }
}



void Widget::on_clearButton_clicked()
{
    expression.clear();
    ui->mainLineEdit->clear();
}

void Widget::on_deleteButton_clicked()
{
    expression.chop(1);
    ui->mainLineEdit->setText(expression);
}

int Widget::Priority(char ch){
    switch (ch) {
    case '*':return 2;
    case '/':return 2;
    case '+':return 1;
    case '-':return 1;
    default:return 0;



    }
}
