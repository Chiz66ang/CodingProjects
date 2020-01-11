#include "mainwindow.h"
#include <QPainter>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    G=300;
    x=200;
    posy = 300;
    y=posy;
    spdy = -500;
    timer = startTimer(30);
    startMS = QDateTime::currentMSecsSinceEpoch();
}

MainWindow::~MainWindow()
{

}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawEllipse(x,y,100,100);
}

void MainWindow::timerEvent(QTimerEvent *e)
{
    gameLoop();
}

void MainWindow::gameLoop()
{
    int64_t duration = QDateTime::currentMSecsSinceEpoch() - startMS;
    t = duration/1000.0F;
    y = 0.5*G*(t*t) + spdy*t + posy;

    repaint();
}
