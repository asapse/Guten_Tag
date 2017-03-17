#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <xmldom.hpp>
#include <taglayout.hpp>
#include <explorerlayout.hpp>
#include <QDebug>
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QKeySequence>
#include <QContextMenuEvent>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    private:
        taglayout *_taglay;
        explorerlayout *_explolay;
        xmldom *_xd;
        QVector<tag*>* _taglist;
        QMenu *_tagMenu;
        QMenu *_helpMenu;
        QAction *_newTagAct;
        QAction *_aboutAct;
        QAction *_delTagAct;
        void about();
        void createActions();
        void createMenus();
    public:
        MainWindow();
        ~MainWindow();
    protected:
    #ifndef QT_NO_CONTEXTMENU
        void contextMenuEvent(QContextMenuEvent *event) override;
    #endif // QT_NO_CONTEXTMENU
};

#endif // MAINWINDOW_H
