/**
  * @file deltagdialog.hpp
  * @authors Espasa Kévin, Bonnaud Jonathan
  * @brief classe permettant l'affichage de la boite de dialog de suppression d'un ou plusieurs tags
**/

#ifndef DELTAGDIALOG_H
#define DELTAGDIALOG_H

#include "tag.hpp"
#include "xmldom.hpp"

#include <QDialog>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QColor>
#include <QPushButton>
#include <QDebug>
#include <QList>
#include <QListWidget>

class deltagdialog : public QDialog
{
    Q_OBJECT
    public:
        /**
         * @brief constructeur de la classe
         * @param taglist adresse du taglist
         */
        deltagdialog(QVector<tag*> *taglist);
        /**
         * @brief supprime un tag de la list
         */
        void del_tag_from_list();
        /**
         * @brief retourne la liste d'indexe des tags supprimés
         * @return QList
         */
        QList<int> *getTab();
    private:
        QVector<tag*> *_taglist;
        QVBoxLayout *_vlayout;
        QHBoxLayout *_hlaytop;
        QHBoxLayout *_hlaybot;
        QPushButton *_valid;
        QPushButton *_anul;
        QListWidget *_listCheckbox;
        QList<int> *_tab;
    signals:
        void tag_deleted();
    public slots:
        /**
         * @brief affiche la liste de checkbox
         */
        void print_list_checkbox();
        /**
         * @brief slot supprimant les tags.
         */
        void accept_del_tag();
};

#endif // DELTAGDIALOG_H
