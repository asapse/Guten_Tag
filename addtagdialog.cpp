#include "addtagdialog.hpp"

addtagdialog::addtagdialog(QVector<tag*> taglist) : QDialog()
{
    _taglist = taglist;

    QLineEdit *tagname = new QLineEdit();
    tagname->setPlaceholderText("Tag Name");

    this->setBulletColor(QColor(252, 61, 57));

    QHBoxLayout *hlayout = new QHBoxLayout;
    this->setLayout(hlayout);
    hlayout->addWidget(tagname);
}

void addtagdialog::setBulletColor(QColor c)
{
    QPixmap bul = QPixmap(100, 100);
    bul.fill(QColor(0, 0, 0, 0));

    QPainter *paint = new QPainter(&bul);
    QPen pen;
    pen.setColor(c);
    pen.setWidth(10);
    paint->setPen(pen);
    paint->setBrush(c.lighter(110));
    paint->drawEllipse(QPoint(bul.width()/2,
                              bul.height()/2), 45, 45);
}

int addtagdialog::accept_add_tag(QString *s, QColor *c)
{
    for(int i=0; i<_taglist.size(); i++)
    {
        if(s == _taglist.value(i)->getName())
            //afficher l'erreur
            QMessageBox::warning(this,"Erreur à l'ajout d'un tag","Ce nom de tag existe déjà.");
            return 1;
    }
    //ajouter le tag au fichier xml
    return 0;
}

