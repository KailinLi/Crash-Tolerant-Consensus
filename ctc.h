#ifndef CTC_H
#define CTC_H

#include <QWidget>
#include <ctcfunction.h>
#include <QPainter>
#include <QLabel>

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
    QLabel *lable[200];
public slots:
    void clickBtn();
};

#endif // CTC_H
