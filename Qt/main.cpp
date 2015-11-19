#include "mainwindow.h"
#include "polygonwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    polygonwindow w;
    w.show();

    return a.exec();
}
