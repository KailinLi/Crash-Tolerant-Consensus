#include "normalprocessor.h"

NormalProcessor::NormalProcessor(QObject *parent) :QObject(parent)
{

}

void NormalProcessor::init(int pos, int *localVal, int ProcessorNum,
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

void NormalProcessor::processor()
{
    std::vector<int> localdata;
    localVal[pos] = rand();
    for(int cnt = 0; cnt < ProcessorNum + 1; cnt++) {
        while (cnt > *vround) {

        }
        semb[pos]->s_lock ();
        printf("I am processor %d at round %d\n",pos,cnt);
        for(int i=0;i < ProcessorNum;i++) {
            printf("%d ",(*info)[i]);
        }
        printf("\n");
        sema->s_lock ();
        (*info)[pos] = std::min(localVal[pos], (*info)[pos]);
        sema->s_unlock ();

        localdata.assign(info->begin(),info->end());
        localVal[pos] = *(min_element(localdata.begin(),localdata.end()));
        emit updateVal (pos);
        semb[(pos + 1) % ProcessorNum]->s_unlock ();
    }
    printf("I am the %dth normal processor,my final value is %d\n",pos, localVal[pos]);
}
