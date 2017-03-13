#include "mainwindow.h"
#include "taglayout.hpp"
#include "explorerlayout.hpp"

#include <QLabel>
#include <QProgressBar>
#include <QPushButton>

MainWindow::MainWindow()
{
    //initialisation de la liste de tags
    _xd = new xmldom();
    _xd->xmlOpen();
    _xd->xmlReader();

    _taglay = new taglayout(_xd);
    _explolay = new explorerlayout();

    QHBoxLayout *hlayout = new QHBoxLayout;

    hlayout->addWidget(_taglay);
    hlayout->addWidget(_explolay);
    this->setLayout(hlayout);

    this->setFixedSize(1400, 900);

    //connect(this, SIGNAL(aboutToQuit()), xd, SLOT(xmlSaver()));
}

MainWindow::~MainWindow()
{
    _taglist = _taglay->getTagList();
    qDebug() << _taglist;
    _xd->saveTagListToXML(_taglist);
}


