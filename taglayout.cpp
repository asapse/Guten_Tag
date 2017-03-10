#include "taglayout.hpp"

taglayout::taglayout(xmldom *xd) : QWidget()
{
    this->setGeometry(10, 10, 100,500);
    _taglist = xd->getTagList();
    _vlayout =  new QVBoxLayout;
    //_vlayout->setObjectName("Tags");
    _del = new QPushButton("Supprimer");
    _add = new QPushButton("Ajouter");

    //add here new widgets, then add them to the layout
    _recherche = new QLineEdit();
    _recherche->setStyleSheet("background-color:white;");
    _recherche->setPlaceholderText("Rechercher tag");

    _vlayout->addWidget(_recherche);

    print_Tags();

    _hlay = new QHBoxLayout;
    _hlay->addWidget(_add);
    _hlay->addWidget(_del);

    _vlayout->addLayout(_hlay);
    this->setLayout(_vlayout);

    _dial = new addtagdialog(xd);
    connect(_add, SIGNAL(clicked()), _dial,SLOT(open()));
    connect(_dial, SIGNAL(tag_added()), this,SLOT(update())); //update doesn't do what i want
                                                              //how to print_tags() again
}


//affiche les tags
void taglayout::print_Tags()
{
    for(int i=0; i<_taglist.size(); i++)
    {
        QPushButton *b = new QPushButton(_taglist.value(i)->getName());
        QColor col = _taglist.value(i)->getColor();
        b->setStyleSheet(QString("background-color: %1").arg(col.name()));
        b->setCursor(Qt::PointingHandCursor);

        _vlayout->addWidget(b);
    }
}
