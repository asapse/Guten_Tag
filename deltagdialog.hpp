#ifndef DELTAGDIALOG_H
#define DELTAGDIALOG_H

#include "tag.hpp"
#include "xmldom.hpp"

#include <QDialog>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QColor>
#include <QPushButton>
#include <QDebug>
#include <QList>
#include <QListWidget>

class deltagdialog : public QDialog
{
    Q_OBJECT
    public:
        deltagdialog(QVector<tag*> *taglist);
        void del_tag_from_list();
    private:
        QVector<tag*> *_taglist;
        QVBoxLayout *_vlayout;
        QHBoxLayout *_hlaytop;
        QHBoxLayout *_hlaybot;
        QPushButton *_valid;
        QPushButton *_anul;
        QListWidget *_listCheckbox;
    signals:
        //void tag_added();
    public slots:
        //void accept_del_tag();
};

#endif // DELTAGDIALOG_H
