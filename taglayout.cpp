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
    _recherche->move(10,10);
    _gridlayout = new QGridLayout;
    _vlayout->addWidget(_recherche);
    _vlayout->setAlignment(_recherche,Qt::AlignTop);
    print_Tags();

    _hlay = new QHBoxLayout;
    _hlay->addWidget(_add);
    _hlay->addWidget(_del);

    _vlayout->addLayout(_gridlayout);
    _vlayout->setAlignment(_hlay,Qt::AlignHCenter);

    _vlayout->addLayout(_hlay);
    _vlayout->setAlignment(_hlay,Qt::AlignBottom);

    this->setLayout(_vlayout);

    _dial = new addtagdialog(&_taglist);

    connect(_add, SIGNAL(clicked()), _dial,SLOT(open()));
    connect(_dial, SIGNAL(tag_added()), this,SLOT(slot_print_Tags()));

    //connect(_recherche, SIGNAL)
}


//affiche les tags
void taglayout::print_Tags()
{      
    for(int i=0; i<_taglist.size(); i++)
    {
        QPushButton *but = createButton(_taglist.value(i));
        if(i<11){
            _gridlayout->addWidget(but,i,0);
        }else if(i<22){
            _gridlayout->addWidget(but,i-11,1);
        } else if(i<33){
            _gridlayout->addWidget(but,i-22,2);
        }
    }

}

void taglayout::slot_print_Tags()
{
    QPushButton *but = createButton(_taglist.last());
    _gridlayout->addWidget(but,_taglist.size()%12, _taglist.size()/12);
}

QPushButton *taglayout::createButton(tag *item)
{
    QPushButton *b = new QPushButton(item->getName());
    QColor col = item->getColor();
    b->setStyleSheet(QString("background-color: %1").arg(col.name()));
    b->setCursor(Qt::PointingHandCursor);
    b->setMinimumWidth(68);
    b->setMinimumHeight(60);
    QFont font = b->font();
    font.setPointSize(16);
    b->setFont(font);
    return b;
}

QVector<tag*> taglayout::getTagList()
{
    return _taglist;
}

void taglayout::findTag()
{
    QString searchString = _recherche->text();
    for(int i=0;i<_taglist.size(); i++)
    {
        //chercher si le tag existe
    }
}
