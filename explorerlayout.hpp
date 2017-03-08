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
    public slots:
        void on_qtableview_doubleClicked(const QModelIndex &index);
        void on_path_returnPressed();
};

#endif // EXPLORERLAYOUT_HPP
