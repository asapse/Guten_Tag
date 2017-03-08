#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    xmldom *xd = new xmldom();
    xd->xmlOpen();
    xd->xmlReader();
    _taglist = xd->getTagList();
}

MainWindow::~MainWindow()
{
}


