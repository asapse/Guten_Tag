#include "explorerlayout.hpp"

explorerlayout::explorerlayout(QWidget *parent): QVBoxLayout(parent)
{
    _qfilemodel = new QFileSystemModel();
    _qtableview = new QTableView(parent);
}
