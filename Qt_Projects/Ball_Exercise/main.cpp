#include "drawingwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DrawingWindow w;

    w.resize(550,400);
    w.setWindowTitle("Drawing Test");

    w.show();

    return a.exec();
}
