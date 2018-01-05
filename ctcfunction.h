#ifndef CTCFUNCTION_H
#define CTCFUNCTION_H

#include <QObject>
#include <QWidget>
#include <slock.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <zconf.h>
#include <algorithm>
#include <thread>
#include <time.h>
#include <QThread>
#include <crashprocessor.h>
#include <normalprocessor.h>
const int INF = 0x3f3f3f3f;
const int MAX_PROCESSOR = 200;
class CTCFunction : public QWidget
{
    Q_OBJECT
public:
    explicit CTCFunction(QWidget *parent = 0, int pNum = 0, int cNum = 0);
    ~CTCFunction();

public:
    QThread thread[MAX_PROCESSOR];
    CrashProcessor *crash[MAX_PROCESSOR];
    NormalProcessor *normal[MAX_PROCESSOR];
    int ProcessorNum = 0;
    int CrashNum = 0;
    std::vector<int> info;
    Slock* sema;
    Slock* semb[MAX_PROCESSOR];
    int localVal[MAX_PROCESSOR];
    int run(int argc, int cNum);
//    void CrashProcessor(int pos);
//    void NormalProcessor(int pos);
signals:

public slots:
};

#endif // CTCFUNCTION_H
