#include "ctc.h"
#include "ui_ctc.h"

CTC::CTC(QWidget *parent, int ProcessorNum, int CrashNum) :
    QWidget(parent),
    ui(new Ui::CTC),
    ProcessorNum(ProcessorNum),
    core(parent, ProcessorNum, CrashNum),
    tmpId(std::vector<bool>(30, true))
{
    ui->setupUi(this);
    connect (ui->pushButton, &QPushButton::clicked, this, &CTC::clickBtn);
    connect (ui->step, &QPushButton::clicked, this, &CTC::clickStep);
    connect (&core, &CTCFunction::updatePos, this, &CTC::updateUI);
    connect (&core, &CTCFunction::crashPos, this, &CTC::updateCrash);
//    int centerX = this->size ().width () / 2;
//    int centerY = this->size ().height () / 2;

    setMouseTracking (true);
    scene = new QGraphicsScene(this);
    for (int i = 0; i < ProcessorNum; ++i) {
        cItem[i] = new ColorItem;
        cItem[i]->setFlag (QGraphicsItem::ItemIsMovable, true);
        cItem[i]->setPos(::sin((i * 6.28) / ProcessorNum) * 150,
                     ::cos((i * 6.28) / ProcessorNum) * 150);

        scene->addItem(cItem[i]);
        ui->tableWidget->insertRow (0);
    }
//    GraphicsView view(scene);
    ui->graphicsView->setScene (scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    ui->graphicsView->setBackgroundBrush(QColor(230, 200, 167));
    ui->graphicsView->setWindowTitle("CTC");

    ui->label->setText (tr("total %1, will crash %2").arg (ProcessorNum).arg (CrashNum));
    ui->step->setEnabled (false);

}

CTC::~CTC()
{
    for (int i = 0; i < ProcessorNum; ++i)
        delete cItem[i];
    delete scene;
    delete ui;
}



void CTC::clickBtn()
{
    core.run ();
    ui->step->setEnabled (true);
    ui->pushButton->setEnabled (false);
    ui->currentlabel->setText (tr("Begin Simulation"));
}

void CTC::updateUI(int pos)
{
    printf("%d\n", pos);
    QTableWidgetItem *ud = new QTableWidgetItem(QString::number (core.info[pos]));
    ui->tableWidget->setItem (pos, 0, ud);
    cItem[pos]->setText (QString::number(core.localVal[pos]));


//    for (int i = 0; i < ProcessorNum; ++i) {
//        cItem[i]->setColor (QColor(255, 255, 255));
//    }
//    lable[pos]->setText (QString::number (core.localVal[pos]));
//    for (int i = 0; i < 10; ++i) {
//        ColorItem *item = new ColorItem;
//        item->setPos(::sin((i * 6.28) / 10.0) * 100,
//                     ::cos((i * 6.28) / 10.0) * 100);

//        scene->addItem(item);
//    }
}

void CTC::clickStep()
{
    ++core.vround;
    if (core.vround > ProcessorNum) {
        ui->step->setEnabled (false);
        for (int i = 0; i < ProcessorNum; ++i) {
            if (tmpId[i]) {
                ui->label->setText (tr("Finish Simulation!!"));
                ui->currentlabel->setText (tr("Final Message is %1").arg (core.info[i]));
                break;
            }
        }
    }
    else
        ui->currentlabel->setText (tr("Current iteration: %1").arg (core.vround));
}

void CTC::updateCrash(int pos)
{
    cItem[pos]->setColor (QColor(255, 255, 255));
    cItem[pos]->stopAnimation ();
    QTableWidgetItem *item;
    if (core.info[pos] == 0x3f3f3f3f)
        item = new QTableWidgetItem(tr("INF"));
    else
        item = new QTableWidgetItem(QString::number (core.info[pos]));
    item->setData (Qt::ForegroundRole, QColor(Qt::red));
    ui->tableWidget->setItem (pos, 0, item);
    tmpId[pos] = false;
//    QPalette palette = lable[pos]->palette();
//    palette.setColor(lable[pos]->backgroundRole(), Qt::black);
//    palette.setColor(lable[pos]->foregroundRole(), Qt::red);
//    lable[pos]->setPalette(palette);
}
