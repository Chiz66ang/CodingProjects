#include "drawingwindow.h"
#include <QPainter>
#include <QPen>
#include <QDateTime>

DrawingWindow::DrawingWindow(QWidget *parent)
    : QMainWindow(parent)
{
    index = 0;
    x = 0.0F; y = 0.0F;
    xspeed = 100.0F; yspeed = 100.0F;
    color[0] = QColor("#ff0000");
    color[1] = QColor("#00ff00");
    color[2] = QColor("#0000ff");
    btn = new QPushButton(this);
    btn->setText("Chg colour");
    btn->setGeometry(230,0,100,40);

    connect(btn, &QPushButton::clicked, this, &DrawingWindow::Changecolour);
    timer_id = startTimer(30);//50ms마다 타미어 이벤트 발생
    prev = QDateTime::currentMSecsSinceEpoch();
}

DrawingWindow::~DrawingWindow()
{

}
//버튼을 클릭할 때마다 Red, Green, Blue 색으로 바뀌도록 해본다.
void DrawingWindow::paintEvent(QPaintEvent *e) //call back 함수.
{
    QPainter painter(this); //그려주는 객체
    painter.setRenderHint(QPainter::Antialiasing); // 선이 각지는 것을 방지.
    //painter.setPen(QPen(QBrush("#000000"),1)); //선: pen, 넓은 면적: brush. 색, 굵기(픽셀)
    // painter.drawLine(0,0,100,100); //0.0좌표의 점과 100,100좌표의 점을 잇는 선을 그린다.
    //painter.setPen(QPen(QBrush("#ff0000"),1));
    //painter.setBrush(QBrush(color[index]));
    //painter.drawRect(move_index,move_index,200,100);
    //painter.setBrush(QBrush("#00ff00")); //면에 색을 채우기 위함.
    //painter.drawRect(0,200,200,100);
    //painter.eraseRect(e->rect()); //이벤트가 발생한 영역의 크기(윈도우 창의 크기만큼)를 지우시오.

    painter.setBrush(QBrush(QColor("#D4f790"))); //RGB 빛 혼합법
    painter.drawEllipse(x,y,70,70); //폭과 높이가 같은 정원.
}

void DrawingWindow::Changecolour()
{
    x+= 5.5F;
    y+= 5.5F;
    //index++;
    //if(index==3) index=0;
    repaint();

}

void DrawingWindow::gameLoop()
{
    if (y >= height()-70) //return; //외부에서 타이머가 돌아가지만 덧그리지는 않는다.
    {
        //killTimer(timer_id); //timer를 종료하고 싶을 때는 killTimer를 쓰지만 이러려면 start timer할 때 변수로 받아뒀다가 쓰면 된다.
        y = height() -70;
        yspeed = -yspeed;
    }

    else if (x >= width()-70)
    {
        x = width()-70;
        xspeed = -xspeed;
    }

    else if (y <= 0)
    {
        y = 0.0F;
        yspeed = -yspeed;
    }

    else if (x <= 0)
    {
        x = 0.0F;
        xspeed = -xspeed;
    }

    curr = QDateTime::currentMSecsSinceEpoch();
    float deltaTime = (curr-prev)/1000.0F; //curr - prev 프레임간 걸린 시간.

    x += xspeed*deltaTime;
    y += yspeed*deltaTime;

    prev = curr;
    repaint();

}

void DrawingWindow::timerEvent(QTimerEvent *e)
{
    gameLoop();
}
