#include "explorerlayout.hpp"

explorerlayout::explorerlayout(): QWidget()
{
    _vlayout = new QVBoxLayout;

    _qfilemodel = new QFileSystemModel(this);

    _qtableview = new QTableView(this);
    _qtableview->setModel(_qfilemodel);
    _qtableview->setRootIndex(_qfilemodel->setRootPath("D:/Documents/"));
    _path = new QLineEdit();
    _path->setStyleSheet("background-color:white;");
    _path->setText(_qfilemodel->rootPath());

    _vlayout->addWidget(_path);
    _vlayout->addWidget(_qtableview);

    this->setLayout(_vlayout);
    connect(_qtableview, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(on_qtableview_doubleClicked(QModelIndex)));
    connect(_path, SIGNAL(returnPressed()), this, SLOT(on_path_returnPressed()));


}

void explorerlayout::on_qtableview_doubleClicked(const QModelIndex &index)
{
        if(index.column() == 0){
            _qtableview->setRootIndex(_qfilemodel->setRootPath("D:/Documents/"+index.data().toString()));
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
