#ifndef CTC_H
#define CTC_H

#include <QWidget>
#include <ctcfunction.h>
#include <QPainter>
#include <QLabel>
#include <QtMath>
#include <coloritem.h>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPropertyAnimation>

namespace Ui {
class CTC;
}

class CTC : public QWidget
{
    Q_OBJECT

public:
    explicit CTC(QWidget *parent = 0, int ProcessorNum = 0, int CrashNum = 0);
    ~CTC();
public:
    Ui::CTC *ui;
    int ProcessorNum;
    int CrashNum;
    CTCFunction core;
    int lableSize = 40;
//    QLabel *lable[200];
    QGraphicsScene *scene;
    ColorItem *cItem[200];
public:
public slots:
    void clickBtn();
    void updateUI(int pos);
    void clickStep();
    void updateCrash(int pos);
};

#endif // CTC_H
