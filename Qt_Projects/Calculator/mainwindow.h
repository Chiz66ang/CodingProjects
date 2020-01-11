#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QWidget>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QPushButton* btn;
    QLabel* lb;
    QLabel* res;
    QTextEdit* num1;
    QTextEdit* num2;
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void add();
};

#endif // MAINWINDOW_H
