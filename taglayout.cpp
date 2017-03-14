#include "taglayout.hpp"

taglayout::taglayout(xmldom *xd) : QWidget()
{
    this->setGeometry(10, 10, 100,500);
    _taglist = xd->getTagList();
    _vlayout = new QVBoxLayout;
    _del = new QPushButton("Supprimer");
    _add = new QPushButton("Ajouter");

    //add here new widgets, then add them to the layout
    _recherche = new QLineEdit();
    _recherche->setStyleSheet("background-color:white;");
    _recherche->setPlaceholderText("Rechercher tag");

    _gridlayout = new QGridLayout;
    _gridlayout->setGeometry(QRect(0,0,0,0));
    //_gridlayout->setVerticalSpacing(135);
    _gridlayout->addWidget(_recherche);

    print_Tags();

    _hlay = new QHBoxLayout;
    _hlay->addWidget(_add);
    _hlay->addWidget(_del);

    _gridlayout->addLayout(_hlay, _taglist.size()+1,0);
    this->setLayout(_gridlayout);

    _dial = new addtagdialog(&_taglist);
    connect(_add, SIGNAL(clicked()), _dial,SLOT(open()));
    connect(_dial, SIGNAL(tag_added()), this,SLOT(slot_print_Tags()));
}


//affiche les tags
void taglayout::print_Tags()
{
    for(int i=0; i<_taglist.size(); i++)
    {
        QPushButton *but = createButton(_taglist.value(i));
        _vlayout->addWidget(but);
    }
    _gridlayout->addLayout(_vlayout,1,0);
}

void taglayout::slot_print_Tags()
{
    QPushButton *but = createButton(_taglist.last());
    _vlayout->addWidget(but);
}

QPushButton *taglayout::createButton(tag *item)
{
    QPushButton *b = new QPushButton(item->getName());
    QColor col = item->getColor();
    b->setStyleSheet(QString("background-color: %1").arg(col.name()));
    b->setCursor(Qt::PointingHandCursor);
    b->setMinimumWidth(68);
    b->setMinimumHeight(60);
    return b;
}

QVector<tag*> taglayout::getTagList()
{
    return _taglist;
}
