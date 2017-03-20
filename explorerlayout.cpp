#include "explorerlayout.hpp"

explorerlayout::explorerlayout(xmldom *xdom): QWidget()
{
    _xdom = xdom;
    _vlayout = new QVBoxLayout;
    _vlayout->setSizeConstraint(QLayout::SetNoConstraint);
    _pathlayout = new QHBoxLayout;

    _qfilemodel = new QFileSystemModel(this);

    _qtableview = new QTableView(this);
    _qtableview->setModel(_qfilemodel);
    _qtableview->setRootIndex(_qfilemodel->setRootPath("D:/Documents/"));
    _qtableview->adjustSize();
    _qtableview->verticalHeader()->setVisible(false);
    _qtableview->horizontalHeader()->setStretchLastSection(true);
    _qtableview->setColumnWidth(0,250);

    _path = new QLineEdit();
    _path->setStyleSheet("background-color:white;");
    _path->setText(_qfilemodel->rootPath());

    _backbutton = new QPushButton("<", this);
    _backbutton->setMaximumWidth(50);

    _completer = new QCompleter(this);
    _completer->setModel(_qfilemodel);
    _path->setCompleter(_completer);

    _listwidget = new QListWidget();
    _listwidget->setMaximumHeight(150);
    _pathlayout->addWidget(_backbutton);
    _pathlayout->addWidget(_path);
    _listfiles = new QListWidget();
    _listfiles->hide();
    _vlayout->addLayout(_pathlayout);
    _vlayout->addWidget(_listfiles);
    _vlayout->addWidget(_qtableview);
    _vlayout->addWidget(_listwidget);

    this->setLayout(_vlayout);
    connect(_qtableview, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(on_qtableview_doubleClicked(QModelIndex)));
    connect(_path, SIGNAL(returnPressed()), this, SLOT(on_path_returnPressed()));
    connect(_backbutton, SIGNAL(clicked()), this, SLOT(on_backbutton_clicked()));
    connect(_qtableview, SIGNAL(clicked(QModelIndex)), this, SLOT(on_qtableview_clicked(QModelIndex)));
}

void explorerlayout::on_qtableview_doubleClicked(const QModelIndex &index)
{
    if(index.column() == 0){
        _qtableview->setRootIndex(_qfilemodel->setRootPath(_qfilemodel->rootPath()+"/"+index.data().toString()));
        _path->setText(_qfilemodel->rootPath());
    }
}

void explorerlayout::on_path_returnPressed()
{
    if(QDir(_path->text()).exists())
        _qtableview->setRootIndex(_qfilemodel->setRootPath(_path->text()));
    else
        QMessageBox::warning(this,"Erreur à l'ouverture du chemin","Le chemin n'existe pas. Vérifiez que le nom est le bon.");
}


void explorerlayout::on_backbutton_clicked()
{
    QDir *qd = new QDir(_path->text());
    qd->cdUp();
    _qtableview->setRootIndex(_qfilemodel->setRootPath(qd->absolutePath()));
    _path->setText(qd->absolutePath());
}

void explorerlayout::on_qtableview_clicked(const QModelIndex &index)
{
    _listwidget->clear();
    QString path = _qfilemodel->rootPath()+"/"+index.data().toString();
    int j=0;
    for(int i=0; i<_xdom->getTagList()->size(); ++i){
        if(_xdom->getTagList()->at(i)->getVector().contains(path)){
            _listwidget->addItem(_xdom->getTagList()->at(i)->getName());
            _listwidget->item(j)->setBackgroundColor(_xdom->getTagList()->at(i)->getColor());
            ++j;
        }
    }
}


QTableView* explorerlayout::getTableView(){
    return _qtableview;
}

QModelIndexList explorerlayout::getIndexTableView(){
    return _qtableview->selectionModel()->selectedIndexes();
}

QString explorerlayout::getPath(){
    return _path->text();
}

void explorerlayout::filter(QPushButton *button)
{
    _listwidget->clear();
    int i = 0;
    while(_xdom->getTagList()->at(i)->getName().compare(button->text())!=0)
        ++i;
    if(_xdom->getTagList()->at(i)->getSelected() == false){
        _xdom->getTagList()->at(i)->setSelected(true);
        QVector<QString> vfiles =_xdom->getTagList()->at(i)->getVector();
        for(int k=0; k<vfiles.size(); ++k){
            if(_listfiles->findItems(vfiles.at(k),Qt::MatchContains).size()==0)
                _listfiles->addItem(vfiles.at(k));
         }
        button->setStyleSheet("QPushButton:focus:pressed{background-color : white;}");
    }else{
        _xdom->getTagList()->at(i)->setSelected(false);
        QVector<QString> vfiles =_xdom->getTagList()->at(i)->getVector();
        for(int k=0; k<vfiles.size(); ++k){
            for (int l=0; l<_listfiles->count(); ++l){
                if(vfiles.at(k).compare(_listfiles->item(l)->text())==0)
                    delete _listfiles->item(l);
            }
        }
        button->setStyleSheet(QString("background-color: %1").arg(_xdom->getTagList()->at(i)->getColor().name()));
    }
}

void explorerlayout::hideListFiles(int index)
{
    if(index == 1)
    {
        _qtableview->hide();
        _listfiles->show();
    }
    else{
        _listfiles->hide();
        _qtableview->show();
    }

}
