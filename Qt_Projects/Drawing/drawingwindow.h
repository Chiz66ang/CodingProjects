#ifndef DRAWINGWINDOW_H
#define DRAWINGWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QPushButton>

class DrawingWindow : public QMainWindow
{
    Q_OBJECT

public:
    QColor color[3];
    int index;
    int timer_id;
    float x, y, xspeed, yspeed;
    int64_t curr; //엄청나게 긴 자료형
    int64_t prev;
    QPushButton* btn;
    DrawingWindow(QWidget *parent = 0);
    ~DrawingWindow();

    void paintEvent(QPaintEvent* e);
    void timerEvent(QTimerEvent* e);

    void Changecolour();
    void gameLoop();
};

#endif // DRAWINGWINDOW_H
