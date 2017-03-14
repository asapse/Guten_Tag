#ifndef TAGLAYOUT_HPP
#define TAGLAYOUT_HPP

#include "tag.hpp"
#include "xmldom.hpp"
#include "addtagdialog.hpp"
#include "explorerlayout.hpp"

#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QObject>
#include <QApplication>
#include <QListWidget>

class taglayout : public QWidget
{
    Q_OBJECT
    public:
        taglayout(xmldom *xd, explorerlayout *el);
        void print_Tags();
        QVector<tag*> getTagList();
        QPushButton *createButton(tag *tag);
        void addFile(QString tagname, QString file);
    private:
        QLineEdit *_recherche;
        QVector<tag*> _taglist;
        QVBoxLayout *_vlayout;
        QPushButton *_del;
        QPushButton *_add;
        QHBoxLayout *_hlay;
        addtagdialog *_dial;
        QGridLayout *_gridlayout;
        QListView *_listview;
        explorerlayout * _explayout;

    public slots:
        void slot_print_Tags();
        void findTag();
        void on_tagbutton_clicked();

};

#endif // TAGLAYOUT_HPP
