#include "mainwindow.h"
#include "taglayout.hpp"
#include "explorerlayout.hpp"

MainWindow::MainWindow()
{
    this->setGeometry(QRect(250,50,0,0));
    //initialisation de la liste de tags
    _xd = new xmldom();
    _xd->xmlOpen();
    _xd->xmlReader();

    _explolay = new explorerlayout(_xd);

    _taglay = new taglayout(_xd, _explolay);

    QHBoxLayout *hlayout = new QHBoxLayout;

    hlayout->addWidget(_taglay);
    hlayout->addWidget(_explolay);
    this->setLayout(hlayout);

    this->setFixedSize(1400, 900);
}

MainWindow::~MainWindow()
{
    _taglist = _taglay->getTagList();
    _xd->saveTagListToXML();
}


