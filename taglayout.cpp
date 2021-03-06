#include "taglayout.hpp"

taglayout::taglayout(xmldom *xd, explorerlayout* el) : QWidget()
{
    this->setGeometry(10, 10, 100,500);
    _taglist = xd->getTagList();
    _xd = xd;
    _explayout = el;

    _vlayout = new QVBoxLayout;
    _del = new QPushButton();
    _add = new QPushButton();
    _add->setIcon(QPixmap(":file/add.png"));
    _add->setIconSize(QSize(55,45));
    _del->setIcon(QPixmap(":file/remove.png"));
    _del->setIconSize(QSize(55,45));

    //add here new widgets, then add them to the layout
    _recherche = new QLineEdit();
    _recherche->setStyleSheet("background-color:white;");
    _recherche->setPlaceholderText("Rechercher tag");
    _recherche->move(10,10);
    _gridlayout = new QGridLayout;
    _vlayout->addWidget(_recherche);
    _vlayout->setAlignment(_recherche,Qt::AlignTop);
    _tabwidget = new QTabWidget(this);
    QWidget *tabtag = new QWidget(_tabwidget);
    tabtag->setLayout(_gridlayout);
    _tabwidget->addTab(tabtag, "tag");

    _filtergridlayout = new QGridLayout;
    QWidget *tabfiltre = new QWidget(_tabwidget);
    tabfiltre->setLayout(_filtergridlayout);
    _tabwidget->addTab(tabfiltre, "filtre");

    print_Tags();

    _hlay = new QHBoxLayout;
    _hlay->addWidget(_add);
    _hlay->addWidget(_del);
    _vlayout->addWidget(_tabwidget);
    _vlayout->setAlignment(_hlay,Qt::AlignHCenter);

    _vlayout->addLayout(_hlay);
    _vlayout->setAlignment(_hlay,Qt::AlignBottom);

    this->setLayout(_vlayout);

    _dial = new addtagdialog(_xd->getTagList());
    _deldial = new deltagdialog(_xd->getTagList());

    connect(_add, SIGNAL(clicked()), _dial,SLOT(open()));
    connect(_del, SIGNAL(clicked()), _deldial,SLOT(open()));
    connect(_del, SIGNAL(clicked()), _deldial,SLOT(print_list_checkbox()));
    connect(_dial, SIGNAL(tag_added()), this,SLOT(slot_print_Tags()));
    connect(_deldial, SIGNAL(tag_deleted()), this,SLOT(slot_del_Tags()));

    connect(_recherche, SIGNAL(textChanged(QString)), this, SLOT(findTag()));
    connect(_tabwidget, SIGNAL(currentChanged(int)), _explayout, SLOT(hideListFiles(int)));
}

addtagdialog *taglayout::getDial()
{
    return _dial;
}

deltagdialog *taglayout::getDelDial()
{
    return _deldial;
}

//affiche les tags
void taglayout::print_Tags()
{      
    for(int i=0; i<_xd->getTagList()->size(); i++)
    {
        QPushButton *but = createButton(_xd->getTagList()->value(i));
        QPushButton *but2 = createButton(_xd->getTagList()->value(i));
        connect(but2,SIGNAL(pressed()), this, SLOT(on_filterbutton_clicked()));
        connect(but, SIGNAL(clicked()), this, SLOT(on_tagbutton_clicked()));
        _gridlayout->addWidget(but, i%11, i/11);
        _filtergridlayout->addWidget(but2, i%11, i/11);
    }

}

void taglayout::slot_print_Tags()
{
    QPushButton *but = createButton(_xd->getTagList()->last());
    QPushButton *but2 = createButton(_xd->getTagList()->last());
    bool iscreate = false;
    connect(but2,SIGNAL(pressed()), this, SLOT(on_filterbutton_clicked()));
    connect(but, SIGNAL(clicked()), this, SLOT(on_tagbutton_clicked()));
    for(int i=0; i<_gridlayout->columnCount(); ++i){
        for(int j=0; j<_gridlayout->rowCount(); ++j){
            if(_gridlayout->itemAtPosition(j,i) == NULL){
                //std::cout<<"i "<<i<<"\ j "<<j<<std::endl;
                _gridlayout->addWidget(but,j, i);
                _filtergridlayout->addWidget(but2,j,i);

                 iscreate = true;
            }
        }
    }
    if(iscreate == false){
        if((_xd->getTagList()->size()%11)==0)
        {
            _gridlayout->addWidget(but,10, (_xd->getTagList()->size()/11)-1);
            _filtergridlayout->addWidget(but2,10, (_xd->getTagList()->size()/11)-1);
        }
        else {
            _gridlayout->addWidget(but,((_xd->getTagList()->size())%11)-1, _xd->getTagList()->size()/11);
            _filtergridlayout->addWidget(but2,((_xd->getTagList()->size())%11)-1, _xd->getTagList()->size()/11);
         }
    }
}

void taglayout::slot_del_Tags()
{
    QList<int> *list = _deldial->getTab();
    for(int i=0;i<list->size(); i++)
    {
        _gridlayout->itemAt(list->at(i))->widget()->hide();
        _gridlayout->removeWidget(_gridlayout->itemAt(list->at(i))->widget());
        _filtergridlayout->itemAt(list->at(i))->widget()->hide();
        _filtergridlayout->removeWidget(_filtergridlayout->itemAt(list->at(i))->widget());
    }
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

QVector<tag*>* taglayout::getTagList()
{
    return _xd->getTagList();
}

void taglayout::findTag()
{
    QString searchString = _recherche->text();
    for(int i=0;i<_taglist->size(); i++)
    {
        //chercher si le tag existe
        if(!_taglist->at(i)->getName().compare(searchString)==0 && !_taglist->at(i)->getName().contains(searchString))
        {
            _gridlayout->itemAt(i)->widget()->hide();
            _filtergridlayout->itemAt(i)->widget()->hide();
        }
        else {
            _gridlayout->itemAt(i)->widget()->show();
            _filtergridlayout->itemAt(i)->widget()->show();
        }
        //if(_recherche->text().compare("")==0) _gridlayout->itemAt(i)->widget()->show();
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
    for(int i = 0; i<_taglist->size();++i){
        if(_taglist->at(i)->getName().compare(tagname)==0){
            if(!_taglist->at(i)->getVector().contains(file)){
                 _taglist->at(i)->addFile(file);
            }else{
                _taglist->at(i)->deleteFile(file);
            }
        }
    }
}

void taglayout::on_filterbutton_clicked(){
    QPushButton* button = qobject_cast<QPushButton*>(sender());
   _explayout->filter(button);
}
