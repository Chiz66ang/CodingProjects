#include "mainwindow.h"
#include <QPainter>
#include <QRectF>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    img.load("D:/test/kirbyss2.png");
    srcX =0;
    srcY =0;
    timer_id = startTimer(90);
}

MainWindow::~MainWindow()
{

}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    //painter.drawImage(10,20, img);
    QRectF target(70,50,92,73.5); //위도우 창 위치와 이미지의 크기.
    QRectF source(srcX,srcY,92,73.5); //이미지상의 좌표.
    painter.drawImage(target,img,source);

}

void MainWindow::timerEvent(QTimerEvent *e)
{
    gameLoop();
}

void MainWindow::showEvent(QShowEvent *e)
{

}

void MainWindow::gameLoop()
{
    srcX += 92;
    if(srcX >= 919)
    {
        srcX = 0;
        srcY += 73.5;
    }

    if (srcY >= 292)
    {
        srcX =0;
        srcY =0;
    }
    repaint();
}
