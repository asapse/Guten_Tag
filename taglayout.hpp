#ifndef TAGLAYOUT_HPP
#define TAGLAYOUT_HPP

#include "tag.hpp"
#include "xmldom.hpp"

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
public slots:
    int open_add_tag();
    int accept_add_tag(QString *s, QColor *c);
};

#endif // TAGLAYOUT_HPP
