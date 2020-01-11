#include "drawingwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DrawingWindow w;
    w.resize(600,500);
    w.show();

    return a.exec();
}
