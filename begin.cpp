#include "begin.h"
#include "ui_begin.h"

Begin::Begin(QWidget *parent, int *total, int *crash) :
    QDialog(parent),
    ui(new Ui::Begin),
    total(total),
    crash(crash)
{
    ui->setupUi(this);
    connect (ui->pushButton, &QPushButton::clicked, this, &Begin::clickOK);
    ui->totallineEdit->setFocus ();
    ui->totallineEdit->setPlaceholderText (tr("e.g. 12"));
    ui->crashlineEdit->setPlaceholderText (tr("e.g. 5"));
//    shakeWindow ();
}

Begin::~Begin()
{
    delete ui;
}

void Begin::clickOK()
{
    if (ui->crashlineEdit->text ().isEmpty () || ui->totallineEdit->text ().isEmpty ()) {
        ui->label->setText (tr("Please input something"));
        ui->totallabel->setFocus ();
        shakeWindow ();
        return;
    }
    else {
        bool check;
        int tmpTotal = ui->totallineEdit->text ().toInt (&check);
        if (!check) {
            ui->label->setText (tr("Please input two number"));
            ui->totallineEdit->setFocus ();
            shakeWindow ();
            return;
        }
        int tmpCrash = ui->crashlineEdit->text ().toInt (&check);
        if (!check) {
            ui->label->setText (tr("Please input two number"));
            ui->crashlineEdit->setFocus ();
            shakeWindow ();
            return;
        }
        if (tmpTotal > 20) {
            ui->label->setText (tr("Total processors can not exceed 20"));
            ui->totallineEdit->setFocus ();
            shakeWindow ();
            return;
        }
        if (tmpTotal <= tmpCrash) {
            ui->label->setText (tr("Crashed number can not exceed total number"));
            ui->totallabel->setFocus ();
            shakeWindow ();
            return;
        }
        *total = tmpTotal;
        *crash = tmpCrash;
        accept ();
    }
}

void  Begin::shakeWindow()
{
    QPropertyAnimation *pAnimation = new QPropertyAnimation(this, "pos");
    pAnimation->setDuration(500);
    pAnimation->setLoopCount(2);
    pAnimation->setKeyValueAt(0, QPoint(geometry().x() - 3, geometry().y() - 3));
    pAnimation->setKeyValueAt(0.1, QPoint(geometry().x() + 6, geometry().y() + 6));
    pAnimation->setKeyValueAt(0.2, QPoint(geometry().x() - 6, geometry().y() + 6));
    pAnimation->setKeyValueAt(0.3, QPoint(geometry().x() + 6, geometry().y() - 6));
    pAnimation->setKeyValueAt(0.4, QPoint(geometry().x() - 6, geometry().y() - 6));
    pAnimation->setKeyValueAt(0.5, QPoint(geometry().x() + 6, geometry().y() + 6));
    pAnimation->setKeyValueAt(0.6, QPoint(geometry().x() - 6, geometry().y() + 6));
    pAnimation->setKeyValueAt(0.7, QPoint(geometry().x() + 6, geometry().y() - 6));
    pAnimation->setKeyValueAt(0.8, QPoint(geometry().x() - 6, geometry().y() - 6));
    pAnimation->setKeyValueAt(0.9, QPoint(geometry().x() + 6, geometry().y() + 6));
    pAnimation->setKeyValueAt(1, QPoint(geometry().x() - 3, geometry().y() - 3));
    pAnimation->start(QAbstractAnimation::DeleteWhenStopped);
}
