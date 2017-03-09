#include "taglayout.hpp"

taglayout::taglayout(QVector<tag*> *taglist) : QWidget()
{
    _taglist = taglist;
    this->setGeometry(10, 10, 100,500);
    QVBoxLayout *vlayout = new QVBoxLayout;
    _vlayout = vlayout;

    //add here new widgets, then add them to the layout
    QLineEdit *recherche = new QLineEdit();
    recherche->setStyleSheet("background-color:white;");
    recherche->setPlaceholderText("Rechercher tag");

    vlayout->addWidget(recherche);

    print_Tags();

    QHBoxLayout *hlay = new QHBoxLayout;

    vlayout->addLayout(hlay);

    QPushButton *add = new QPushButton("Ajouter");
    QPushButton *del = new QPushButton("Supprimer");

    hlay->addWidget(add);
    hlay->addWidget(del);

    this->setLayout(vlayout);
}


void taglayout::print_Tags()
{
    for(int i=0; i<_taglist->size(); i++)
    {
        QPushButton *b = new QPushButton(_taglist->value(i)->getName());
        QColor col = _taglist->value(i)->getColor();
        b->setStyleSheet(QString("background-color: %1").arg(col.name()));

        _vlayout->addWidget(b);
    }
}
