#include "ctc.h"
#include "ui_ctc.h"

CTC::CTC(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CTC),
    ProcessorNum(11),
    core(parent, ProcessorNum, 4)
{
    ui->setupUi(this);
    connect (ui->pushButton, &QPushButton::clicked, this, &CTC::clickBtn);
    connect (ui->step, &QPushButton::clicked, this, &CTC::clickStep);
    connect (&core, &CTCFunction::updatePos, this, &CTC::updateUI);
    connect (&core, &CTCFunction::crashPos, this, &CTC::updateCrash);
    int centerX = this->size ().width () / 2;
    int centerY = this->size ().height () / 2;

    setMouseTracking (true);
    scene = new QGraphicsScene(this);
    for (int i = 0; i < 10; ++i) {
        ColorItem *item = new ColorItem;
        item->setPos(::sin((i * 6.28) / 10.0) * 150,
                     ::cos((i * 6.28) / 10.0) * 150);

        scene->addItem(item);
    }
//    GraphicsView view(scene);
    ui->graphicsView->setScene (scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    ui->graphicsView->setBackgroundBrush(QColor(230, 200, 167));
    ui->graphicsView->setWindowTitle("CTC");
//    view.show();
//    for (int i = 0; i < ProcessorNum; ++i) {
//        lable[i] = new QLabel(tr("one"), this);
//        lable[i]->setGeometry(QRect(centerX + 120 * qCos((360 / ProcessorNum) * i) - (lableSize >> 1),
//                                    centerY + 120 * qSin((360 / ProcessorNum) * i) - (lableSize >> 1), lableSize, lableSize));
//        lable[i]->setAutoFillBackground (true);
//        lable[i]->setAlignment (Qt::AlignCenter);
//        QPalette palette = lable[i]->palette();
//        palette.setColor(lable[i]->backgroundRole(), Qt::yellow);
//        palette.setColor(lable[i]->foregroundRole(), Qt::red);
//        lable[i]->setPalette(palette);
//        QRect *rect = new QRect(0,0,lableSize,lableSize);
//        QRegion* region = new QRegion(*rect,QRegion::Ellipse);
//        lable[i]->setMask(*region);
//    }
}

CTC::~CTC()
{
    delete ui;
}



void CTC::clickBtn()
{
    core.run ();

}

void CTC::updateUI(int pos)
{
    printf("%d\n", pos);
    lable[pos]->setText (QString::number (core.localVal[pos]));
}

void CTC::clickStep()
{
    ++core.vround;
}

void CTC::updateCrash(int pos)
{
    QPalette palette = lable[pos]->palette();
    palette.setColor(lable[pos]->backgroundRole(), Qt::black);
    palette.setColor(lable[pos]->foregroundRole(), Qt::red);
    lable[pos]->setPalette(palette);
}
