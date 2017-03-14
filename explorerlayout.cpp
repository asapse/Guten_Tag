#include "explorerlayout.hpp"

explorerlayout::explorerlayout(): QWidget()
{
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

    _path = new QLineEdit();
    _backbutton = new QPushButton("<", this);
    _backbutton->setMaximumWidth(50);
    _path->setStyleSheet("background-color:white;");
    _path->setText(_qfilemodel->rootPath());

    _completer = new QCompleter(this);
    _completer->setModel(_qfilemodel);
    _path->setCompleter(_completer);

    _qtreeview = new QTreeView();
    _qtreeview->setMaximumHeight(250);
    _pathlayout->addWidget(_backbutton);
    _pathlayout->addWidget(_path);

    _vlayout->addLayout(_pathlayout);
    _vlayout->addWidget(_qtableview);
    _vlayout->addWidget(_qtreeview);

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

}
