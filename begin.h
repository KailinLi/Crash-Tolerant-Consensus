#ifndef BEGIN_H
#define BEGIN_H

#include <QDialog>
#include <QPropertyAnimation>

namespace Ui {
class Begin;
}

class Begin : public QDialog
{
    Q_OBJECT

public:
    explicit Begin(QWidget *parent = 0, int *total = 0, int *crash = 0);
    ~Begin();
    void clickOK();
    void shakeWindow();
public:
    Ui::Begin *ui;
    int *total;
    int *crash;
};

#endif // BEGIN_H
