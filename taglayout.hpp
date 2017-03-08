#ifndef TAGLAYOUT_HPP
#define TAGLAYOUT_HPP

#include "tag.hpp"

#include <QLineEdit>

class taglayout : public QWidget
{
public:
    taglayout(QVector<tag*> *taglist);
private:
    QLineEdit *_recherche;
public slots:
};

#endif // TAGLAYOUT_HPP
