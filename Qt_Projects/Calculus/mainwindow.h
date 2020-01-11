#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int timer;
    float x,y, posy, spdy,G,t;
    int64_t startMS;
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void paintEvent(QPaintEvent* e);
    void timerEvent(QTimerEvent* e);
    void gameLoop();
};

#endif // MAINWINDOW_H
