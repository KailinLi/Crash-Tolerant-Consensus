#include "ctc.h"
#include "ui_ctc.h"

CTC::CTC(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CTC),
    core(parent)
{
    ui->setupUi(this);
    connect (ui->pushButton, &QPushButton::clicked, this, &CTC::clickBtn);

    for (int i = 0; i < 10; ++i) {
        lable[i] = new QLabel(tr("one"), this);
        lable[i]->setGeometry(QRect(30 * i,30 * i, 50, 50));
        lable[i]->setAutoFillBackground (true);
        QPalette palette = lable[i]->palette();
        palette.setColor(lable[i]->backgroundRole(), Qt::yellow);
        palette.setColor(lable[i]->foregroundRole(), Qt::red);
        lable[i]->setPalette(palette);
        QRect *rect = new QRect(0,0,50,50);
        QRegion* region = new QRegion(*rect,QRegion::Ellipse);
        lable[i]->setMask(*region);
    }

}

CTC::~CTC()
{
    delete ui;
}



void CTC::clickBtn()
{
//    for (int i = 0; i < 20; ++i) {
//        lable[i] = new QLabel(tr("one"), this);
//        lable[i]->setGeometry(QRect(10 ,10 , 20, 20));
//        QPalette palette = lable[i]->palette();
//        palette.setColor(lable[i]->backgroundRole(), Qt::yellow);
//        palette.setColor(lable[i]->foregroundRole(), Qt::yellow);
//        lable[i]->setPalette(palette);
//    }
//    core.run (11, 1);
}
