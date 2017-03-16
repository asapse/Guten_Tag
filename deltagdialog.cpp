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
    _tab = new QList<int>();

    this->setWindowTitle("Supprimer Tag");

    _listCheckbox = new QListWidget;

    _hlaytop->addWidget(_listCheckbox);
    _hlaybot->addWidget(_anul);
    _hlaybot->addWidget(_valid);
    _vlayout->addLayout(_hlaytop);
    _vlayout->addLayout(_hlaybot);
    this->setLayout(_vlayout);

    connect(_valid, SIGNAL(clicked()), this, SLOT(accept_del_tag()));
    connect(_anul, SIGNAL(clicked()), this, SLOT(close()));
}

#include <iostream>
void deltagdialog::print_list_checkbox()
{
    _listCheckbox->clear();
    for(int i=0; i<_taglist->size();i++)
    {
        QListWidgetItem *listCheckboxItem = new QListWidgetItem( _taglist->at(i)->getName(), _listCheckbox );
        listCheckboxItem->setCheckState( Qt::Unchecked );
    }
}


void deltagdialog::accept_del_tag()
{
    _tab->clear();
    for(int i=0;i<_taglist->size();i++)
    {
        if(_listCheckbox->item(i)->checkState() == Qt::Checked)
        {
            _tab->append(i-_tab->length());
        }
    }
    for(int i=0; i<_tab->length();i++)
    {
        _taglist->remove(_tab->at(i));
        _listCheckbox->removeItemWidget(_listCheckbox->item(_tab->at(i)));
        _listCheckbox->clear();
       this->print_list_checkbox();
    }
    emit tag_deleted();
}


QList<int> *deltagdialog::getTab()
{
    return _tab;
}
