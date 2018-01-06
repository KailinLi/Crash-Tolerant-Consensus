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
}

Begin::~Begin()
{
    delete ui;
}

void Begin::clickOK()
{
    if (ui->crashlineEdit->text ().isEmpty () || ui->totallineEdit->text ().isEmpty ()) {
        ui->label->setText (tr("please input"));
        ui->totallabel->setFocus ();
        return;
    }
    else {
        bool check;
        int tmpTotal = ui->totallineEdit->text ().toInt (&check);
        if (!check) {
            ui->label->setText (tr("please input number"));
            ui->totallineEdit->setFocus ();
            return;
        }
        int tmpCrash = ui->crashlineEdit->text ().toInt (&check);
        if (!check) {
            ui->label->setText (tr("please input number"));
            ui->crashlineEdit->setFocus ();
            return;
        }
        if (tmpTotal > 30) {
            ui->label->setText (tr("Too many processors!The number of processors may not exceed 30!"));
            ui->totallineEdit->setFocus ();
            return;
        }
        if (tmpTotal <= tmpCrash) {
            ui->label->setText (tr("The number of Crash Failure must be smaller than the number of processors"));
            ui->totallabel->setFocus ();
            return;
        }
        *total = tmpTotal;
        *crash = tmpCrash;
        accept ();
    }
}
