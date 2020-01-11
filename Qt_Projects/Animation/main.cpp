#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Animation Test");
    w.resize(200,150);
    w.show();

    return a.exec();
}
