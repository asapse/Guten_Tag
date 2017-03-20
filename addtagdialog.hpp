/**
  * @file addtagdialog.hpp
  * @authors Espasa Kévin, Bonnaud Jonathan
  * @brief classe permettant l'affichage de la boite de dialog d'ajout d'un tag
**/

#ifndef ADDTAGDIALOG_HPP
#define ADDTAGDIALOG_HPP

#include "tag.hpp"
#include "xmldom.hpp"

#include <QDialog>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QColor>
#include <QPushButton>
#include <QPixmap>
#include <QPainter>
#include <QDebug>
#include <QRgb>
#include <QList>
#include <QListWidget>
#include <QComboBox>
#include <QMap>

class addtagdialog : public QDialog
{
    Q_OBJECT
    public:
    /**
         * @brief constructeur de la classe
         * @param taglist adresse du taglist
         */
        addtagdialog(QVector<tag*> *taglist);
        /**
         * @brief procédure créant un boutton
         */
        void add_tag_to_list();
    private:
        QVector<tag*> *_taglist;
        QVBoxLayout *_vlayout;
        QHBoxLayout *_hlaytop;
        QHBoxLayout *_hlaybot;
        QPushButton *_valid;
        QPushButton *_anul;
        QLineEdit *_lineditag;
        QComboBox *_cb;
        QMap<QString, QColor> *_colors;

    signals:
        void tag_added();
    public slots:
        /**
         * @brief slot associé au boutton valider testant si un bouton peut être créé
         */
        void accept_add_tag();
};

#endif // ADDTAGDIALOG_HPP
