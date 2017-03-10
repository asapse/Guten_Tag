#ifndef ADDTAGDIALOG_HPP
#define ADDTAGDIALOG_HPP

#include "tag.hpp"

#include <QDialog>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QColor>
#include <QPushButton>
#include <QPixmap>
#include <QPainter>
#include <QDebug>

class addtagdialog : public QDialog
{
    Q_OBJECT
    public:
        addtagdialog(QVector<tag*> taglist);
    private:
        QVector<tag*> _taglist;
        QVBoxLayout *_vlayout;
        QHBoxLayout *_hlaytop;
        QHBoxLayout *_hlaybot;
        QPushButton *_valid;
        QPushButton *_anul;
        QLineEdit *_lineditag;
        QColor _c;
    signals:

    public slots:
        int accept_add_tag();
};

#endif // ADDTAGDIALOG_HPP
