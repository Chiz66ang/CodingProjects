#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.resize(550,400);
    w.setWindowTitle("Calculator");
    w.show();


    return a.exec();
}
