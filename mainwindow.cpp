#include "mainwindow.h"
#include "taglayout.hpp"
#include "explorerlayout.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    //initialisation de la liste de tags
    xmldom *xd = new xmldom();
    xd->xmlOpen();
    xd->xmlReader();
    _taglist = xd->getTagList();

    QHBoxLayout *layout = new QHBoxLayout;
    taglayout *taglay = new taglayout();
    explorerlayout *explolay = new explorerlayout();

    layout->addLayout(taglay);
    layout->addLayout(explolay);

    this->setFixedSize(1400, 900);
    this->setWindowTitle("Guten Tag");
    //this->setWindowIcon(QIcon("icone.png"));

}

MainWindow::~MainWindow()
{
}


