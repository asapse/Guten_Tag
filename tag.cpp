#include "tag.hpp"

tag::tag()
{

}

tag::tag(QString name, QColor color)
{
    _name = name;
    _color = color;
    _selected = false;
}

tag::tag(QString name, QColor color, QVector<QString> files)
{
    _name = name;
    _color = color;
    _files = files;
    _selected = false;
}


QColor tag::getColor()
{
    return _color;
}

void tag::setColor(QColor color)
{
    _color = color;
}

QString tag::getName()
{
    return _name;
}

void tag::setName(QString name)
{
    _name = name;
}

void tag::deleteFile(QString filename)
{
    _files.remove(_files.indexOf(filename));
}
void tag::addFile(QString filename)
{
    _files << filename;
}

void tag::setVector(QVector<QString> files)
{
    _files = files;
}

QVector<QString> tag::getVector()
{
    return _files;
}

bool tag::getSelected(){
    return _selected;
}

void tag::setSelected(bool s){
    _selected = s;
}
