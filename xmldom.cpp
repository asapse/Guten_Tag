#include "xmldom.hpp"

xmldom::xmldom()
{
    _filepath = QString::fromStdString("defaultxml.xml");
    _dom = new QDomDocument(QString::fromStdString("xml"));
}

xmldom::xmldom(QString filepath)
{
    _filepath = filepath;
    _dom = new QDomDocument(QString::fromStdString("xml"));
}

xmldom::~xmldom()
{
    delete _dom;
}

void xmldom::xmlreader()
{
    QFile file(_filepath);
    if(!file.open(QIODevice::ReadOnly))
        return;
    if (!_dom->setContent(&file))
    {
        file.close();
        return;
    }
    file.close();
}

void xmldom::xmlsaver()
{
    QString write_doc = _dom->toString();
    QFile file(_filepath);
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&file);
        stream << write_doc;
    }
    file.close();
}
