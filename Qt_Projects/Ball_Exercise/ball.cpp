#include "ball.h"
#include <QDateTime>
#include <cstdlib>
#include <ctime>

Ball::Ball()
{
}

Ball::Ball(int radius, float x, float y, QColor color)
{
    this->radius = radius;
    this->x = x;
    this->y = y;
    this->color = color;

    srand(time(NULL));
    int tmpX = rand()%50+51;
    int tmpY = rand()%50+51;
    int tmpDir = rand()%2;
    if(!tmpDir) {
        tmpX = -tmpX;
    }else{
        tmpY = -tmpY;
    }

    this->spdX = tmpX;
    this->spdY = tmpY;
    prev = QDateTime::currentMSecsSinceEpoch();
}

void Ball::move()
{
    if(y>=(height-100)) {
        y = height-100;
        spdY = -spdY;
    }else if(y<=0) {
        y = 0;
        spdY = -spdY;
    }else if(x<=0) {
        x = 0;
        spdX = -spdX;
    }else if(x>=(width-100)){
        x = width-100;
        spdX = -spdX;
    }

    curr = QDateTime::currentMSecsSinceEpoch();
    float deltaTime = (curr-prev)/1000.0F;

    x += spdX*deltaTime;
    y += spdY*deltaTime;

    prev = curr;
}

void Ball::draw(QPainter *painter)
{
    painter->setBrush(QBrush(color));
    painter->drawEllipse(x,y,radius*2,radius*2);
}
