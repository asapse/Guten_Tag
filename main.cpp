#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setFixedSize(600, 300);



    QPushButton firstbut("First button", &w);
    firstbut.setToolTip("appuyez ici");
    firstbut.setCursor(Qt::PointingHandCursor);
    firstbut.show();

    QPushButton quit("Quitter", &w);
    quit.setCursor(Qt::PointingHandCursor);
    quit.setGeometry(100,100, 60, 40);
    quit.show();

    QObject::connect(&quit, SIGNAL(clicked()), &a, SLOT(quit()));

    w.show();

    return a.exec();
}
