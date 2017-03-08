#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    //initialisation de la liste de tags
    xmldom *xd = new xmldom();
    xd->xmlOpen();
    xd->xmlReader();
    _taglist = xd->getTagList();

    QHBoxLayout *layout = new QHBoxLayout;



}

MainWindow::~MainWindow()
{
}


