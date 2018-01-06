#ifndef CRASHPROCESSOR_H
#define CRASHPROCESSOR_H

#include <QObject>
#include <vector>
#include "slock.h"

class CrashProcessor : public QObject
{
    Q_OBJECT
public:
    explicit CrashProcessor(QObject *parent = 0);
    int pos;
    int *localVal;
    int ProcessorNum;
    Slock* (*semb);
    Slock* sema;
    std::vector<int> *info;
    volatile int *vround;
    void init(int pos = 0, int *localVal = 0,
              int ProcessorNum = 0, Slock* (*semb) = 0, Slock* sema = 0,
              std::vector<int> *info = 0, volatile int *vround = 0);
    void processor();
signals:
    void updateVal(int i);
    void crashMsg(int i);
public slots:
};

#endif // CRASHPROCESSOR_H
