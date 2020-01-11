#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton> //버튼 생성을 위해 추가할 것들
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QPushButton* btn;
    QLabel* lb;
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void OnBtnClick(); //헤더에 함수 선언 (버튼을 누르면 label의 숫자가 하나씩 올라가는)
};

#endif // MAINWINDOW_H
