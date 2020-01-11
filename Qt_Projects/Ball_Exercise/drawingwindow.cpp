#include "drawingwindow.h"
#include <QPainter>
#include <QPen>
#include <QDateTime>

DrawingWindow::DrawingWindow(QWidget *parent)
    : QMainWindow(parent)
{
    rb = new Ball(50, 100, 100, QColor("#ff0000"));
    gb = new Ball(50, 300, 200, QColor("#00ff00"));

    btn = new QPushButton(this);
    btn->setText("Color Change");
    btn->setGeometry(230,0,100,40);
    connect(btn, &QPushButton::clicked, this, &DrawingWindow::OnBtnClick);
    timer_id = startTimer(30);
}

DrawingWindow::~DrawingWindow()
{
}

void DrawingWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    rb->draw(&painter);
    gb->draw(&painter);
}

void DrawingWindow::OnBtnClick()
{
    repaint();
}

void DrawingWindow::gameLoop()
{
    rb->width = gb->width = width();
    rb->height = gb->height = height();
    rb->move();
    gb->move();
    repaint();
}

void DrawingWindow::timerEvent(QTimerEvent *e)
{
    gameLoop();
}
