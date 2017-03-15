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
        xmldom();
        xmldom(QString filepath);
        ~xmldom();
        void xmlOpen();
        void xmlReader();
        void addTag(QString s, QColor c);
        QVector<tag*>* getTagList();
        void saveTagListToXML();
    public slots:
        void xmlSaver();
};

#endif // XMLDOM_HPP
