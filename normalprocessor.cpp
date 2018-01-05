#include "normalprocessor.h"

NormalProcessor::NormalProcessor(QObject *parent) :QObject(parent)
{

}

void NormalProcessor::init(int pos, int *localVal, int ProcessorNum, Slock **semb, Slock *sema, std::vector<int> *info)
{
    this->pos = pos;
    this->localVal = localVal;
    this->ProcessorNum = ProcessorNum;
    this->semb = semb;
    this->sema = sema;
    this->info = info;
}
