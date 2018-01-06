#ifndef BEGIN_H
#define BEGIN_H

#include <QDialog>

namespace Ui {
class Begin;
}

class Begin : public QDialog
{
    Q_OBJECT

public:
    explicit Begin(QWidget *parent = 0, int *total = 0, int *crash = 0);
    ~Begin();
    int *total;
    int *crash;
    void clickOK();
private:
    Ui::Begin *ui;
};

#endif // BEGIN_H
