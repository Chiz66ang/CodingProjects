#ifndef DRAWINGWINDOW_H
#define DRAWINGWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QPushButton>
#include "ball.h"

class DrawingWindow : public QMainWindow
{
    Q_OBJECT

public:
    QPushButton *btn;
    int timer_id;
    Ball *rb, *gb;

    DrawingWindow(QWidget *parent = 0);
    ~DrawingWindow();

    void paintEvent(QPaintEvent *e);
    void timerEvent(QTimerEvent *e);

    void OnBtnClick();
    void gameLoop();
};

#endif // DRAWINGWINDOW_H
