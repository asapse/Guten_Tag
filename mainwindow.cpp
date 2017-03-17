#include "mainwindow.h"
#include "taglayout.hpp"
#include "explorerlayout.hpp"

MainWindow::MainWindow() : QMainWindow()
{
    QWidget *mainwindow = new QWidget;

    //initialisation de la liste de tags
    _xd = new xmldom();
    _xd->xmlOpen();
    _xd->xmlReader();

    _explolay = new explorerlayout(_xd);

    _taglay = new taglayout(_xd, _explolay);

    QHBoxLayout *hlayout = new QHBoxLayout;

    hlayout->addWidget(_taglay);
    hlayout->addWidget(_explolay);
    mainwindow->setLayout(hlayout);

    createActions();
    createMenus();

    this->setFixedSize(1400, 900);
    this->setGeometry(QRect(250,50,0,0));
    this->setCentralWidget(mainwindow);
}

MainWindow::~MainWindow()
{
    _taglist = _taglay->getTagList();
    _xd->saveTagListToXML();
}

void MainWindow::createActions()
{
    _newTagAct = new QAction(tr("&NewTag"), this);
    _newTagAct->setShortcuts(QKeySequence::AddTab);
    _newTagAct->setStatusTip(tr("Create a new tag"));
    connect(_newTagAct, SIGNAL(triggered(bool)), _taglay->getDial(), SLOT(open()));

    _delTagAct = new QAction(tr("&DeleteTags"), this);
    _delTagAct->setStatusTip(tr("Delete tags"));
    _delTagAct->setShortcuts(QKeySequence::Delete);
    connect(_delTagAct, SIGNAL(triggered(bool)), _taglay->getDelDial(), SLOT(open()));
    connect(_delTagAct, SIGNAL(triggered(bool)), _taglay->getDelDial(),SLOT(print_list_checkbox()));

    _aboutAct = new QAction(tr("&AboutUs"), this);
    _aboutAct->setStatusTip(tr("About us"));
    connect(_aboutAct, SIGNAL(triggered(bool)), this, SLOT(about()));
}

void MainWindow::createMenus()
{
    _tagMenu = menuBar()->addMenu(tr("&MenuTag"));
    _tagMenu->addAction(_newTagAct);
    _tagMenu->addAction(_delTagAct);

    _helpMenu = menuBar()->addMenu(tr("&Help"));
    _helpMenu->addAction(_aboutAct);
}

#ifndef QT_NO_CONTEXTMENU
void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{/*
   //POUR LE CLICK DROIT
    QMenu menu(this);

    menu.exec(event->globalPos());*/
}
#endif // QT_NO_CONTEXTMENU


