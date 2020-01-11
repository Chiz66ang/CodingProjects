#ifndef BALL_H
#define BALL_H

#include <QColor>
#include <QPainter>

class Ball
{
public:
    int radius, width, height;
    float x,y, spdX, spdY;
    QColor color;
    int64_t curr, prev;

    Ball();
    Ball(int radius, float x, float y, QColor color);
    void move();
    void draw(QPainter *painter);
};

#endif // BALL_H
