#ifndef CTC_H
#define CTC_H

#include <QWidget>
#include <ctcfunction.h>
#include <QPainter>
#include <QLabel>
#include <QtMath>
#include <graphicsview.h>
#include <coloritem.h>

namespace Ui {
class CTC;
}

class CTC : public QWidget
{
    Q_OBJECT

public:
    explicit CTC(QWidget *parent = 0);
    ~CTC();
private:
    Ui::CTC *ui;
    CTCFunction core;
    int lableSize = 40;
    QLabel *lable[200];
    QGraphicsScene *scene;
public:
    int ProcessorNum;
public slots:
    void clickBtn();
    void updateUI(int pos);
    void clickStep();
    void updateCrash(int pos);
};

#endif // CTC_H
