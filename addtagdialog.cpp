#include "addtagdialog.hpp"

addtagdialog::addtagdialog(QVector<tag*> *taglist) : QDialog()
{
    _taglist = taglist;
    _vlayout =  new QVBoxLayout;
    _hlaytop = new QHBoxLayout;
    _hlaybot = new QHBoxLayout;
    _valid = new QPushButton("Valider");
    _anul = new QPushButton("Annuler");
    _valid->setDefault(true);

    this->setWindowTitle("Ajouter Tag");

    _lineditag = new QLineEdit();
    _lineditag->setPlaceholderText("Tag Name");

    _hlaytop->addWidget(_lineditag);
    _hlaybot->addWidget(_anul);
    _hlaybot->addWidget(_valid);
    _vlayout->addLayout(_hlaytop);

    //créer 10 couleurs de base et choisir entre ces 10
    _colors = new QMap<QString, QColor>();
    _colors->insert("rouge", QColor(255,105,97));
    _colors->insert("jaune", QColor(253,253,150));
    _colors->insert("vert", QColor(3,192,60));
    _colors->insert("vert fonce", QColor(85,158,131));
    _colors->insert("bleu", QColor(27,133,184));
    _colors->insert("rose", QColor(255,209,220));
    _colors->insert("orange", QColor(255,179,71));
    _colors->insert("marron", QColor(160,130,105));
    _colors->insert("violet", QColor(150,111,214));
    _colors->insert("gris", QColor(211,211,211));
    _colors->insert("bleu fonce", QColor(119,158,203));

    _cb = new QComboBox;
    for(int i=0; i<_colors->size();i++)
    {
        _cb->addItem(_colors->keys().at(i));
        QPixmap pixmap(100,100);
        pixmap.fill(_colors->value(_colors->keys().at(i)));
        QIcon ico = QIcon(pixmap);
        _cb->setItemIcon(i, ico);

    }
    _vlayout->addWidget(_cb);

    _vlayout->addLayout(_hlaybot);
    this->setLayout(_vlayout);

    connect(_valid, SIGNAL(clicked()), this, SLOT(accept_add_tag()));
    //connect(_lineditag, SIGNAL(returnPressed()), this, SLOT(accept_add_tag()));
    connect(_valid, SIGNAL(clicked()), _lineditag, SLOT(clear()));

    connect(_anul, SIGNAL(clicked()), this, SLOT(close()));
    connect(_anul, SIGNAL(clicked()), _lineditag, SLOT(clear()));
}

void addtagdialog::accept_add_tag()
{
    if(_lineditag->text() == ""){
        QMessageBox::warning(this,"Erreur","Champ vide.");
        return;
    }

    if(_taglist->size() >= 44){
        QMessageBox::warning(this,"Erreur","Vous avez atteind le nombre maximum de tags.");
        return;
    }
    for(int i=0; i<_taglist->size(); i++)
    {
        if(_lineditag->text() == _taglist->value(i)->getName()){
            //afficher l'erreur
            QMessageBox::warning(this,"Erreur a l'ajout d'un tag","Ce nom de tag existe deja.");
            return;
        }
    }
    //ajouter le tag à la liste
    add_tag_to_list();
    emit tag_added();

    //QMessageBox::information(this,"Ajout d'un tag","Nouveau tag cree.");
    return;
}

void addtagdialog::add_tag_to_list()
{
    _taglist->push_back(new tag(_lineditag->text(),_colors->value( _cb->itemText(_cb->currentIndex()) )));
}

