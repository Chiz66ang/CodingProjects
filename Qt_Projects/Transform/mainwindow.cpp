#include "mainwindow.h"
#include "rotationmatrix.h"
#include <QPainter>
#include <QPen>
#include <QRectF>
#include <QImage>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    idx = 0;
    timer_id = startTimer(30);
}

MainWindow::~MainWindow()
{

}


void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QPointF prev(100,0);
    auto iter = pts.begin();
    auto end = pts.end();
    for (; iter!=end;iter++)
    {
        painter.drawLine
           (
            prev.x()+width()/2,
            prev.y()+height()/2,
            iter->x()+width()/2,
            iter->y()+height()/2
           );
        prev.setX(iter->x());
        prev.setY(iter->y());
    }
}

void MainWindow::timerEvent(QTimerEvent *e)
{
    gameloop();
}

void MainWindow::gameloop()
{
   if(idx==360) killTimer(timer_id);
   QPointF p = rot.rotate(QPointF(100,0), idx++);
   pts.push_back(p);
   repaint();
}
