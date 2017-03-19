/**
  * @file mainwindow.hpp
  * @authors Espasa Kévin, Bonnaud Jonathan
  * @brief classe principale
**/
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
        QAction *_exitAct;
        QAction *_aboutAct;
        QAction *_delTagAct;
        void createActions();
        void createMenus();
    public:
        /**
         * @brief construteur de la classe
         */
        MainWindow();
        /**
          * @brief destructeur de la classe
          **/
        ~MainWindow();
    public slots:
        /**
         * @brief slot associé au boutton about
         */
        void about();
};

#endif // MAINWINDOW_H
