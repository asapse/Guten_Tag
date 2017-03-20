/**
  * @file explorerlayout.hpp
  * @authors Espasa Kévin, Bonnaud Jonathan
  * @brief widget affichant les fichiers et les informations qui sont associées
**/

#ifndef EXPLORERLAYOUT_HPP
#define EXPLORERLAYOUT_HPP

#include "xmldom.hpp"

#include <QWidget>
#include <QObject>
#include <QFileSystemModel>
#include <QTableView>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QString>
#include <QDir>
#include <QMessageBox>
#include <QPushButton>
#include <iostream>
#include <QHeaderView>
#include <QCompleter>
#include <QDirModel>
#include <QListWidget>
#include <QItemSelectionModel>
#include <QDebug>
class explorerlayout : public QWidget
{
    Q_OBJECT
    public:
    /**
         * @brief constructeur du widget.
         * @param xdom le xml comportant les informations sur les tags.
         */
        explorerlayout(xmldom *xdom);
        /**
         * @brief fonction retournant la table view.
         * @return la table view.
         */
        QTableView* getTableView();
        /**
         * @brief fonction retournant le pointeur du tableau des indexes sélectionnés.
         * @return QTableView.
         */
        QModelIndexList getIndexTableView();
        /**
         * @brief fonction retournant le path de la editline.
         * @return QString.
         */
        QString getPath();
        /**
         * @brief procédure de filtre, elle affiche à la place de la table view la liste des fichiers associés à un tag donné.
         * @param name, le nom du boutton.
         */
        void filter(QPushButton* button);
    private:
        xmldom * _xdom;
        QFileSystemModel *_qfilemodel;
        QTableView *_qtableview;
        QLineEdit *_path ;
        QVBoxLayout *_vlayout;
        QPushButton *_backbutton;
        QHBoxLayout * _pathlayout;
        QCompleter * _completer;
        QListWidget * _listwidget;
        QListWidget * _listfiles;
    public slots:
        /**
         * @brief slot permettant lors d'un double clic de rentrer dans le dossier.
         * @param index
         */
        void on_qtableview_doubleClicked(const QModelIndex &index);
        /**
         * @brief slot associé a l'edit text lorsque l'on appuie sur entrée, on va au path donné s'il existe.
         */
        void on_path_returnPressed();
        /**
         * @brief slot associé au boutton "<" permettant le retour en arriere pour le path.
         */
        void on_backbutton_clicked();
        /**
         * @brief slot associé à la table view affichant dans la table la liste des tags associés au fichier sélectionné dans le table view
         * @param index
         */
        void on_qtableview_clicked(const QModelIndex &index);
        void hideListFiles(int index);
};

#endif // EXPLORERLAYOUT_HPP
