#ifndef ADDTAGDIALOG_HPP
#define ADDTAGDIALOG_HPP

#include "tag.hpp"

#include <QDialog>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QPainter>
#include <QPixmap>
#include <QMessageBox>

class addtagdialog : public QDialog
{
    Q_OBJECT
    public:
        addtagdialog(QVector<tag*> taglist);
        void setBulletColor(QColor c);
    private:
        QVector<tag*> _taglist;
    signals:

    public slots:
        int accept_add_tag(QString *s, QColor *c);
};

#endif // ADDTAGDIALOG_HPP
