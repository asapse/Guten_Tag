#include "explorerlayout.hpp"

#include <QLineEdit>
#include <QVBoxLayout>

explorerlayout::explorerlayout(): QWidget()
{
    this->setStyleSheet("background-color:grey;");

    _qfilemodel = new QFileSystemModel();
    _qtableview = new QTableView();

    QVBoxLayout *vlayout = new QVBoxLayout;

    //add here new widgets, then add them to the layout
    QLineEdit *recherche = new QLineEdit("/chemin/vers/dossier");
    recherche->setStyleSheet("background-color:white;");
    recherche->setReadOnly(true);

    vlayout->addWidget(recherche);

    this->setLayout(vlayout);
}
