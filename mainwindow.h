#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <xmldom.hpp>
#include <taglayout.hpp>
#include <explorerlayout.hpp>

class MainWindow : public QWidget
{
    Q_OBJECT
private:
    QVector<tag*> _taglist;
    taglayout *_taglay;
    explorerlayout *_explolay;
public:
    MainWindow();
    ~MainWindow();
};

#endif // MAINWINDOW_H
