#include "taglayout.hpp"

taglayout::taglayout(xmldom *xd, explorerlayout* el) : QWidget()
{
    this->setGeometry(10, 10, 100,500);
    _taglist = xd->getTagList();

    _explayout = el;

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
        _gridlayout->addWidget(but, i%11, i/11);
        connect(but, SIGNAL(clicked()), this, SLOT(on_tagbutton_clicked()));
    }

}

void taglayout::slot_print_Tags()
{
    QPushButton *but = createButton(_taglist.last());
    _gridlayout->addWidget(but,(_taglist.size()-1)%11, _taglist.size()/11);
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

void taglayout::on_tagbutton_clicked()
{
    if(_explayout->getIndexTableView().size()>0)
    {
       for(int i=0; i<_explayout->getIndexTableView().size(); ++i){
           QString path = _explayout->getPath()+"/"+_explayout->getIndexTableView().at(i).data().toString();
           QPushButton* button = qobject_cast<QPushButton*>(sender());
           addFile(button->text(), path);
       }
    }
}

void taglayout::addFile(QString tagname, QString file)
{
    for(int i = 0; i<_taglist.size();++i){
        if(_taglist.at(i)->getName().compare(tagname)==0){
            if(!_taglist.at(i)->getVector().contains(file)){
                 _taglist.at(i)->addFile(file);
            }else{
                QMessageBox::warning(this,"Le fichier est déjà taggé","le fichier/dossier "+ file+" est déjà taggé en "+tagname);
            }
        }
    }
}
