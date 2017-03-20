/**
  * @file taglayout.hpp
  * @authors Espasa Kévin, Bonnaud Jonathan
  * @brief classe definissant les tags
**/

#ifndef TAGLAYOUT_HPP
#define TAGLAYOUT_HPP

#include "tag.hpp"
#include "xmldom.hpp"
#include "addtagdialog.hpp"
#include "deltagdialog.hpp"
#include "explorerlayout.hpp"

#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QObject>
#include <QApplication>
#include <QListWidget>
#include <QTabBar>

class taglayout : public QWidget
{
    Q_OBJECT
    public:
    /**
         * @brief construteur de la classe
         * @param xd le xml genere à partir du fichier xml
         * @param el explorer layout
         */
        taglayout(xmldom *xd, explorerlayout *el);
        /**
         * @brief procedure affichant les tags dans la gridlayout
         */
        void print_Tags();
        /**
         * @brief fonction retournant la liste de tags
         * @return QVector de tag
         */
        QVector<tag*>* getTagList();
        /**
         * @brief fonction permettant la création d'un boutton tag
         * @param tag
         * @return
         */
        QPushButton *createButton(tag *tag);
        /**
         * @brief procedure ajout un fichier a un tag
         * @param tagname le nom du tag
         * @param file le nom du fichier
         */
        void addFile(QString tagname, QString file);
        /**
         * @brief fonction créant la boite de dialog d'ajout
         * @return l'adresse vers la boite
         */
        addtagdialog *getDial();
        /**
         * @brief fonction créant la boite de dialog de suppression
         * @return l'adresse vers la boite
         */
        deltagdialog *getDelDial();
    private:
        xmldom *_xd;
        QLineEdit *_recherche;
        QVector<tag*>* _taglist;
        QVBoxLayout *_vlayout;
        QPushButton *_del;
        QPushButton *_add;
        QHBoxLayout *_hlay;
        addtagdialog *_dial;
        deltagdialog *_deldial;
        QGridLayout *_gridlayout;
        QListView *_listview;
        explorerlayout * _explayout;
        QTabWidget *_tabwidget;
        QGridLayout * _filtergridlayout;
    public slots:
        /**
         * @brief slot d'affichage des tags
         */
        void slot_print_Tags();
        /**
         * @brief slot de suppression des tags
         */
        void slot_del_Tags();
        /**
         * @brief slot associé à la barre de recherche, permettant de chercher dans la liste des tags le tag souhaité
         */
        void findTag();
        /**
         * @brief slot associé au boutton de tag, permet soit l'affichage des tags associés soit de tagger un fichier
         */
        void on_tagbutton_clicked();
        /**
         * @brief slot associé au boutton de tag pour le filtrage
         */
        void on_filterbutton_clicked();

};

#endif // TAGLAYOUT_HPP
