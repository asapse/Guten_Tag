#include "explorerlayout.hpp"

explorerlayout::explorerlayout(QWidget *parent): QVBoxLayout()
{
    _qfilemodel = new QFileSystemModel();
    _qtableview = new QTableView(parent);
}
