#ifndef XMLDOM_HPP
#define XMLDOM_HPP

#include <QtXml/qxml.h>
#include <QDomDocument>
#include <QString>
#include <QWidget>
#include <QString>
#include <tag.hpp>
#include <QDir>
#include <QMessageBox>
#include <iostream>

class xmldom : public QWidget
{

    private:
        QDomDocument *_dom;
        QString _filepath;
        QVector<tag*> _taglist;
    public:
        xmldom();
        xmldom(QString filepath);
        ~xmldom();
        void xmlOpen();
        void xmlReader();
        void xmlSaver();
        QVector<tag*> getTagList();

};

#endif // XMLDOM_HPP
