/**
  * @file xmldom.hpp
  * @authors Espasa Kévin, Bonnaud Jonathan
  * @brief classe permettant la lecture et l'ecrire d'un xml
**/
#ifndef XMLDOM_HPP
#define XMLDOM_HPP

#include "tag.hpp"

#include <QtXml/qxml.h>
#include <QDomDocument>
#include <QString>
#include <QWidget>
#include <QString>
#include <QDir>
#include <QMessageBox>
#include <iostream>
#include <QDebug>

class xmldom : public QWidget
{

    private:
        QDomDocument *_dom;
        QString _filepath;
        QVector<tag*>* _taglist;
    public:
        /**
         * @brief constructeur par defaut de la classe.
         */
        xmldom();
        /**
         * @brief constructeur de la classe prenant le chemin du fichier
         * @param filepath chemin du fichier xml
         */
        xmldom(QString filepath);
        /**
          * @brief destructeur de la classe
        **/
        ~xmldom();
        /**
         * @brief procedure ouvrant un fichier xml
         */
        void xmlOpen();
        /**
         * @brief procedure lisant un fichier xml
         */
        void xmlReader();
        /**
         * @brief procedure créant un tag à partir des balises xml
         * @param s nom du tag
         * @param c couleur du tag
         */
        void addTag(QString s, QColor c);
        /**
         * @brief fonction retournant l'adresse du tableau de tags
         * @return l'adresse du tableau de tag
         */
        QVector<tag*>* getTagList();
        /**
         * @brief procedure transformant une tagliste en xml
         */
        void saveTagListToXML();
        /**
         * @brief procedure ajoutant une balise file
         * @param root noeud parent du fichier
         * @param path chemin du fichiers
         */
        void addFile(QDomElement root,QString path);
    public slots:
        /**
         * @brief slot permettant l'enregistrement dans le fichier xml
         */
        void xmlSaver();
};

#endif // XMLDOM_HPP
