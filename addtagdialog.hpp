#ifndef ADDTAGDIALOG_HPP
#define ADDTAGDIALOG_HPP

#include "tag.hpp"
#include "xmldom.hpp"

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
        void add_tag_to_list();
        QVector<tag*> getTagList();
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
        void tag_added();
    public slots:
        void accept_add_tag();
};

#endif // ADDTAGDIALOG_HPP
