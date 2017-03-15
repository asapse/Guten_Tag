#include "xmldom.hpp"

xmldom::xmldom() : QWidget()
{
    _filepath = QDir::currentPath()+"/" + QString::fromStdString("default.xml");
    _dom = new QDomDocument(QString::fromStdString("xml"));
    _taglist = new QVector<tag*>();
}

xmldom::xmldom(QString filepath) : QWidget()
{
    _filepath = QDir::currentPath()+"/" + filepath;
    _dom = new QDomDocument(QString::fromStdString("xml"));
}

xmldom::~xmldom()
{
    delete _dom;
}

void xmldom::xmlOpen()
{
    QFile file(_filepath);
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this,"Erreur à l'ouverture du document XML","Le document XML n'a pas pu être ouvert. Vérifiez que le nom est le bon et que le document est bien placé");
        return;
    }
    if (!_dom->setContent(&file))
    {
        file.close();
        QMessageBox::warning(this,"Erreur à l'ouverture du document XML","Le document de sauvegarde ne contient rien.");
        return;
    }
    file.close();
}

void xmldom::xmlReader()
{
    QDomElement head = _dom->documentElement();
    QDomNode child = head.firstChild();
    while(!child.isNull())
    {
        QDomElement childelement = child.toElement();
        QDomNodeList listfiles = child.childNodes();
        QVector<QString> files;
        for(int i =0; i<listfiles.length(); ++i)
        {
            QDomElement e = listfiles.at(i).toElement();
            files.push_back(e.attribute("path"));
        }
        _taglist->push_back(new tag(childelement.attribute("name"), QColor(childelement.attribute("color")), files));
        child = child.nextSibling();
    }
}

void xmldom::xmlSaver()
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

void xmldom::saveTagListToXML()
{
    _dom->clear();
    QDomElement newtag = _dom->createElement(QString("list-tags"));
    _dom->appendChild(newtag);
    for(int i=0; i<_taglist->size(); i++)
    {
        //qDebug() << taglist.value(i);
        //qDebug() << _taglist.value(i);

        this->addTag(_taglist->at(i)->getName(), _taglist->at(i)->getColor());
    }
    this->xmlSaver();
}

//à faire quand on quitte l'appli, puis xmlSaver()
void xmldom::addTag(QString s, QColor c)
{
    QDomElement root = _dom->documentElement();
    QDomElement newtag = _dom->createElement(QString("tag"));

    newtag.setAttribute(QString("name"),s);
    newtag.setAttribute(QString("color"),c.name());
    root.appendChild(newtag);
}

QVector<tag*>* xmldom::getTagList()
{
    return _taglist;
}
