#ifndef TAGLAYOUT_HPP
#define TAGLAYOUT_HPP

#include "tag.hpp"
#include "xmldom.hpp"
#include "addtagdialog.hpp"

#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QObject>
#include <QListWidget>

class taglayout : public QWidget
{
    Q_OBJECT
    public:
        taglayout(xmldom *xd);
        void print_Tags();
        QVector<tag*> getTagList();
        QPushButton *createButton();
    private:
        QLineEdit *_recherche;
        QVector<tag*> _taglist;
        QVBoxLayout *_vlayout;
        QPushButton *_del;
        QPushButton *_add;
        QHBoxLayout *_hlay;
        addtagdialog *_dial;
        QGridLayout *_gridlayout;
    public slots:
        void slot_print_Tags();
};

#endif // TAGLAYOUT_HPP
