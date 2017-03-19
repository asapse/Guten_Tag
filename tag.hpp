/**
  * @file tag.hpp
  * @authors Espasa Kévin, Bonnaud Jonathan
  * @brief classe definissant un tag
**/
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
        /**
         * @brief constructeur par defaut d'un tag
         */
        tag();
        /**
         * @brief construteur du tag
         * @param name nom du tag
         * @param color couleur qui lui est associée
         */
        tag(QString name, QColor color);
        /**
         * @brief constructeur du tag
         * @param name nom du tag
         * @param color couleur qui lui est associée
         * @param files liste des fichiers qui sont taggé par le tag
         */
        tag(QString name, QColor color, QVector<QString> files);
        /**
         * @brief fonction retournant la couleur associé à un tag
         * @return QColor
         */
        QColor getColor();
        /**
         * @brief modifie la couleur associé au tag
         * @param color
         */
        void setColor(QColor color);
        /**
         * @brief fonction retournant le nom du tag
         * @return QString _name
         */
        QString getName();
        /**
         * @brief modifie le nom associé au tag
         * @param color
         */
        void setName(QString name);
        /**
         * @brief procédure supprimant un fichier associé à un tag.
         * @param filename le nom du fichier
         */
        void deleteFile(QString filename);
        /**
         * @brief procédure ajoutant un fichier à un tag
         * @param filename le nom du fichier
         */
        void addFile(QString filename);
        /**
         * @brief procédure modifiant le vecteur de fichier associé au tag
         * @param files vecteur contenant les paths des fichiers
         */
        void setVector(QVector<QString> files);
        /**
         * @brief fonction retournant le vecteur de fichiers associé au tag
         * @return vecteur de QString
         */
        QVector<QString> getVector();
};

#endif // TAG_HPP
