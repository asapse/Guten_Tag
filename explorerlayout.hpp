#ifndef EXPLORERLAYOUT_HPP
#define EXPLORERLAYOUT_HPP

#include <QFileSystemModel>
#include <QTableView>

class explorerlayout : public QWidget
{
    public:
        explorerlayout();
    private:
        QFileSystemModel *_qfilemodel;
        QTableView *_qtableview;
    public slots:
};

#endif // EXPLORERLAYOUT_HPP
