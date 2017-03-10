#ifndef TAG_HPP
#define TAG_HPP

#include <QColor>
#include <QVector>
#include <QString>
#include <QFile>

class tag
{
    private:
        QString _name;
        QColor _color;
        QVector<QString> _files;
    public:
        tag();
        tag(QString name, QColor color);
        tag(QString name, QColor color, QVector<QString> files);
        QColor getColor();
        void setColor(QColor color);
        QString getName();
        void setName(QString name);
        void deleteFile(QString filename);
        void addFile(QString filename);
        void setVector(QVector<QString> files);
        QVector<QString> getVector();
};

#endif // TAG_HPP
