#include "mainwindow.h"
#include "taglayout.hpp"
#include "explorerlayout.hpp"

#include <QLabel>
#include <QProgressBar>
#include <QPushButton>

MainWindow::MainWindow()
{
    //initialisation de la liste de tags
    xmldom *xd = new xmldom();
    xd->xmlOpen();
    xd->xmlReader();

    taglayout *tagcontent = new taglayout(xd);
    explorerlayout *explorercontent = new explorerlayout();

    QHBoxLayout *hlayout = new QHBoxLayout;

    hlayout->addWidget(tagcontent);
    hlayout->addWidget(explorercontent);
    this->setLayout(hlayout);

    this->setFixedSize(1400, 900);

    //connect(this, SIGNAL(aboutToQuit()), xd, SLOT(xmlSaver()));
}

MainWindow::~MainWindow()
{
}


