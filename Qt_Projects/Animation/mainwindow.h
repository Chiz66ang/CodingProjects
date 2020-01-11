#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QImage>
#include <QMainWindow>
#include <QPaintEvent>
#include <QTimerEvent>
#include <QShowEvent>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString fileName;
    QImage img;
    int timer_id;
    int srcX;
    int srcY;

    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void paintEvent(QPaintEvent* e);
    void timerEvent(QTimerEvent* e);
    void showEvent(QShowEvent* e);

    void gameLoop();
};

#endif // MAINWINDOW_H
