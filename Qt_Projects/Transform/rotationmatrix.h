#ifndef ROTATIONMATRIX_H
#define ROTATIONMATRIX_H
#include <QPoint>


class RotationMatrix
{
   public:
    RotationMatrix();

    QPointF rotate (QPointF p, float deg);

};

#endif // ROTATIONMATRIX_H
