#ifndef EXPLORERLAYOUT_HPP
#define EXPLORERLAYOUT_HPP

#include <QWidget>
#include <QObject>
#include <QFileSystemModel>
#include <QTableView>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QString>
#include <QDir>
#include <QMessageBox>
#include <QPushButton>
#include <iostream>
#include <QHeaderView>
#include <QCompleter>
#include <QDirModel>
#include <QTreeView>

class explorerlayout : public QWidget
{
    Q_OBJECT
    public:
        explorerlayout();
    private:
        QFileSystemModel *_qfilemodel;
        QTableView *_qtableview;
        QLineEdit *_path ;
        QVBoxLayout *_vlayout;
        QPushButton *_backbutton;
        QHBoxLayout * _pathlayout;
        QCompleter * _completer;
        QTreeView * _qtreeview;
    public slots:
        void on_qtableview_doubleClicked(const QModelIndex &index);
        void on_path_returnPressed();
        void on_backbutton_clicked();
        void on_qtableview_clicked(const QModelIndex &index);
};

#endif // EXPLORERLAYOUT_HPP
