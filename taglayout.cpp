#include "taglayout.hpp"

#include <QVBoxLayout>

taglayout::taglayout() : QWidget()
{
    this->setStyleSheet("background-color:grey;");
    this->setGeometry(10, 10, 100,500);
    QVBoxLayout *vlayout = new QVBoxLayout;

    //add here new widgets, then add them to the layout
    QLineEdit *recherche = new QLineEdit();
    recherche->setStyleSheet("background-color:white;");
    recherche->setPlaceholderText("Rechercher tag");

    vlayout->addWidget(recherche);

    this->setLayout(vlayout);
}
