#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <xmldom.hpp>
#include <taglayout.hpp>
#include <explorerlayout.hpp>
#include <QDebug>

class MainWindow : public QWidget
{
    Q_OBJECT
    private:
        taglayout *_taglay;
        explorerlayout *_explolay;
        xmldom *_xd;
        QVector<tag*>* _taglist;
    public:
        MainWindow();
        ~MainWindow();
};

#endif // MAINWINDOW_H
