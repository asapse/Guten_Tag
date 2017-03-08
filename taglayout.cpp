#include "taglayout.hpp"
using namespace std;
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

taglayout::taglayout(QVector<tag*> *taglist) : QWidget()
{
    this->setStyleSheet("background-color:grey;");
    this->setGeometry(10, 10, 100,500);
    QVBoxLayout *vlayout = new QVBoxLayout;

    //add here new widgets, then add them to the layout
    QLineEdit *recherche = new QLineEdit();
    recherche->setStyleSheet("background-color:white;");
    recherche->setPlaceholderText("Rechercher tag");

    vlayout->addWidget(recherche);

    vlayout->addWidget(new QLabel("TAGS"));

    for(int i=0; i<taglist->size(); i++)
    {
        QPushButton *b = new QPushButton(taglist->value(i)->getName());
        QColor col = taglist->value(i)->getColor();
        b->setStyleSheet(QString("background-color: %1").arg(col.name()));

        vlayout->addWidget(b);
    }

    QHBoxLayout *hlay = new QHBoxLayout;

    vlayout->addLayout(hlay);

    QPushButton *add = new QPushButton("Ajouter");
    QPushButton *del = new QPushButton("Supprimer");

    hlay->addWidget(add);
    hlay->addWidget(del);

    this->setLayout(vlayout);
}
