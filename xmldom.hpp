#ifndef XMLDOM_HPP
#define XMLDOM_HPP

#include <QtXml/qxml.h>
#include <QDomDocument>
#include <QString>

class xmldom
{

    private:
        QDomDocument *_dom;
        QString _filepath;
    public:
        xmldom();
        xmldom(QString filepath);
        ~xmldom();

        void xmlreader();
        void xmlsaver();

};

#endif // XMLDOM_HPP
