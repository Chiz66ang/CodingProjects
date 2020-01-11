#include "mainwindow.h"
#include <QApplication>
#include <cmath>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.resize(500,500);

    /*
    Rotation Matrix
    회전행열을 이용하여 한점(5,0)을 90도 회전하는 내용.
    cos -sin * [x]
    sin  cos   [y]
    -----------------
    cosT * x + (-sinT) * y = [x']
    sinT * x + cosT * y    = [y']

    for(int i =0; i <=360; i++)
    {
    float x = cos(3.14F/180 * i) * 5 - sin(3.14F/180 * i)* 0;
    float y = sin(3.14F/180 * i) * 5 + cos(3.14F/180 * i)* 0;
    QString sX = QString::number(x);
    QString sY = QString::number(y);

    w.setWindowTitle("X:"+ sX + "   Y:"+sY);
    }
     */

    /* RotationMatrix라는 클래스를 생성하고 객체를 생성한 후에
    ratate(point, angle) 함수를 호출하면 전달된 point, angle라디안 만큼
    회전한 새로운 point를 리턴하도록 해보세요.
    이를 사용하여 화면 중앙에 지름 200픽셀의 원을 그려보세요.
    */


    return a.exec();
}
