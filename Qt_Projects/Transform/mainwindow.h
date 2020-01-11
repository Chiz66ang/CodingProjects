#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "rotationmatrix.h"

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QVector<QPointF>pts;
    RotationMatrix rot;
    int idx, timer_id;
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void paintEvent(QPaintEvent* e);
    void timerEvent(QTimerEvent* e);
    void gameloop ();
};

#endif // MAINWINDOW_H
