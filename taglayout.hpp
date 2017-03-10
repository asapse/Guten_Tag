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

class taglayout : public QWidget
{
    public:
        taglayout(xmldom *xd);
        void print_Tags();
    private:
        QLineEdit *_recherche;
        QVector<tag*> _taglist;
        QVBoxLayout *_vlayout;
        QPushButton *_del;
        QPushButton *_add;
        QHBoxLayout *_hlay;
        addtagdialog *_dial;
    public slots:
};

#endif // TAGLAYOUT_HPP
