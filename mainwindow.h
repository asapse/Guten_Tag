#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <xmldom.hpp>

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QVector<tag*> _taglist;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H
