#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    btn = new QPushButton(this); // 생성자에서 버튼과 라벨을 생성, 각 객체의 위치를 지정해줬다.
    btn->setText("Click Me");
    btn->setGeometry(100,100,100,40);

    connect(btn, &QPushButton::clicked, this, &MainWindow::OnBtnClick); //버튼을 클릭했을 때 이 객체에 있는 OnBtnClick 함수를 연결한다.

    lb = new QLabel(this);
    lb->setText("0");
    lb->setGeometry(100,150,100,40);

}

MainWindow::~MainWindow()
{

}

void MainWindow::OnBtnClick()
{
    int num = lb->text().toInt(); //lb에서 설정해놓은 문자열을 가져와 정수로 바꾸어라.
    QString sNum = QString::number(++num);
    lb->setText(sNum);
}
