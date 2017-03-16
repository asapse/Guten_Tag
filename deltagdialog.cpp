#include "deltagdialog.hpp"

deltagdialog::deltagdialog(QVector<tag*> *taglist) : QDialog()
{
    _taglist = taglist;
    _vlayout =  new QVBoxLayout;
    _hlaytop = new QHBoxLayout;
    _hlaybot = new QHBoxLayout;
    _valid = new QPushButton("Valider");
    _anul = new QPushButton("Annuler");
    _valid->setDefault(true);

    this->setWindowTitle("Supprimer Tag");

    _listCheckbox = new QListWidget;
    QListWidgetItem *listCheckboxItem= new QListWidgetItem( "CheckBox", _listCheckbox );
    listCheckboxItem->setCheckState( Qt::Unchecked );

    _hlaytop->addWidget(listCheckbox);
    _hlaybot->addWidget(_anul);
    _hlaybot->addWidget(_valid);
    _vlayout->addLayout(_hlaytop);
    _vlayout->addLayout(_hlaybot);
    this->setLayout(_vlayout);

    //connect(_valid, SIGNAL(clicked()), this, SLOT(accept_del_tag()));

    connect(_anul, SIGNAL(clicked()), this, SLOT(close()));
}

