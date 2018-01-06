#include "crashprocessor.h"
#include <QDebug>
CrashProcessor::CrashProcessor(QObject *parent) : QObject(parent)
{

}

void CrashProcessor::init(int pos, int *localVal, int ProcessorNum,
                          Slock **semb, Slock *sema, std::vector<int> *info, volatile int *vround)
{
    this->pos = pos;
    this->localVal = localVal;
    this->ProcessorNum = ProcessorNum;
    this->semb = semb;
    this->sema = sema;
    this->info = info;
    this->vround = vround;
}

void CrashProcessor::processor()
{
    int flag=0;
    localVal[pos] = rand();
    int randround = rand() % ProcessorNum + 1;
    qDebug() << "*" <<randround;
    std::vector<int> localdata;
    for(int cnt = 0; cnt < ProcessorNum + 1; cnt++)
    {
//        printf("%d****%d\n", *vround, ProcessorNum);
        while (cnt > *vround) {
        }
        semb[pos]->s_lock ();
        if(cnt >= randround)
        {
            flag = 1;
            semb[(pos + 1) % ProcessorNum]->s_unlock ();
            if(cnt==randround)
            {
                printf("I am the %dth carsh processor failed at round %d,my final value is %d\n", pos,randround, localVal[pos]);
                emit crashMsg (pos);
            }
            continue;
        }
        emit updateVal (pos);
        printf("I am shit processor %d at round %d\n",pos,cnt);
        for(int i = 0; i < ProcessorNum; i++) {
            printf("%d ",(*info)[i]);
        }
        printf("\n");
        sema->s_lock ();
        (*info)[pos] = std::min(localVal[pos], (*info)[pos]);
        sema->s_unlock ();
        localdata.assign(info->begin(),info->end());
        localVal[pos] = *(min_element(localdata.begin(),localdata.end()));
        semb[(pos+1)%ProcessorNum]->s_unlock ();
    }
    if(flag==0)
    {
        printf("I am the %dth normal processor,my final value is %d\n",pos, localVal[pos]);
    }
}
