#include "ctc.h"
#include <begin.h>

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    CTC w;
//    w.show();
    int ProcessorNum;
    int CrashNum;
    Begin begin;
    begin.total = &ProcessorNum;
    begin.crash = &CrashNum;
    if (begin.exec () == QDialog::Accepted) {
        CTC w(0, ProcessorNum, CrashNum);
        w.show ();
        return a.exec ();
    }


    return a.exec();
}
