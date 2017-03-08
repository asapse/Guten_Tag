#ifndef EXPLORERLAYOUT_HPP
#define EXPLORERLAYOUT_HPP

#include <QVBoxLayout>
#include <QFileSystemModel>
#include <QTableView>

class explorerlayout : public QVBoxLayout
{
    public:
        explorerlayout(QWidget *parent);
    private:
        QFileSystemModel *_qfilemodel;
        QTableView *_qtableview;
    public slots:
};

#endif // EXPLORERLAYOUT_HPP
