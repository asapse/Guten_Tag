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

    QMessageBox::information(this,"Ajout d'un tag","Nouveau tag cree.");
    return;
}

void addtagdialog::add_tag_to_list()
{
    //créer 10 couleurs de base et choisir entre ces 10
    QColor couleurs[] = {QColor(255,51,51), QColor(255,153,51), QColor(255,255,51), QColor(153,255,51),
                 QColor(51,255,153), QColor(51,255,255), QColor(51,153,255),
                 QColor(51,51,255), QColor(153,51,255), QColor(255,51,153)};

    int r = rand() % 9;
    _taglist->push_back(new tag(_lineditag->text(),couleurs[r]));
}

