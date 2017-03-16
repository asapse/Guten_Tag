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
        QList<int> *getTab();
    private:
        QVector<tag*> *_taglist;
        QVBoxLayout *_vlayout;
        QHBoxLayout *_hlaytop;
        QHBoxLayout *_hlaybot;
        QPushButton *_valid;
        QPushButton *_anul;
        QListWidget *_listCheckbox;
        QList<int> *_tab;
    signals:
        void tag_deleted();
    public slots:
        void print_list_checkbox();
        void accept_del_tag();
};

#endif // DELTAGDIALOG_H
