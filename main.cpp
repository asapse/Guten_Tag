#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyleSheet("QPushButton:hover { background-color: white }");
    MainWindow w;
    w.show();

    return a.exec();
}
