#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    num1 = new QTextEdit(this);
    num1->setGeometry(100,150,50,30);

    num2 = new QTextEdit(this);
    num2->setGeometry(200,150,50,30);

    lb = new QLabel(this);
    lb->setText("+");
    lb->setGeometry(170,160,10,10);

    btn = new QPushButton(this);
    btn->setText("=");
    btn->setGeometry(270,150,30,30);

    connect(btn, &QPushButton::clicked, this, &MainWindow::add);

    res = new QLabel(this);
    res->setText("0");
    res->setGeometry(320, 150, 30,30);
}

MainWindow::~MainWindow()
{

}

void MainWindow::add()
{
    int n1 = num1->toPlainText().toInt(); //입력한 문자를 문자로 바꿔주는 것.
    int n2 = num2->toPlainText().toInt();
    int num = n1 + n2;
    res->setText(QString::number(num)); //int를 문자열로 바꿔주는 것.

}
