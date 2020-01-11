#include "mainwindow.h"
#include <QApplication>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.resize(550, 400);
    w.setWindowTitle(QString::fromLocal8Bit("첫 윈도우 프로그램"));
    w.show();

    return a.exec();
}
