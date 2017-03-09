#ifndef TAGLAYOUT_HPP
#define TAGLAYOUT_HPP

#include "tag.hpp"

#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class taglayout : public QWidget
{
public:
    taglayout(QVector<tag*> *taglist);
    void print_Tags();
private:
    QLineEdit *_recherche;
    QVector<tag*> *_taglist;
    QVBoxLayout *_vlayout;
public slots:
};

#endif // TAGLAYOUT_HPP
