#include "rotationmatrix.h"
#include <cmath>

RotationMatrix::RotationMatrix()
{

}


QPointF RotationMatrix::rotate(QPointF p, float deg)
{
    float x = cos(3.14F/180 * deg) * p.x() - sin(3.14F/180 * deg) * p.y();
    float y = sin(3.14F/180 * deg) * p.x() + cos(3.14F/180 * deg) * p.y();
    return QPointF(x,y);

}
