#include "ctcfunction.h"

CTCFunction::CTCFunction(QWidget *parent, int pNum, int cNum) :
    QWidget(parent),
    ProcessorNum(pNum),
    CrashNum(cNum)
{
    srand((int)time(0));
//    ProcessorNum = pNum;
    if(ProcessorNum > MAX_PROCESSOR) {
        printf("Too many processors!The number of processors may not exceed 200!\n");
    }
//    CrashNum = cNum;
    for(int i = 0; i < ProcessorNum; ++i) {
        info.push_back(INF);
    }
    if(CrashNum >= ProcessorNum) {
        printf("The number of Crash Failure must be smaller than the number of processors\n");
    }

    std::thread processors[MAX_PROCESSOR];
    sema = new Slock(1);
    semb[0] = new Slock(1);
    for(int i = 1; i < MAX_PROCESSOR; i++) {
        semb[i] = new Slock(0);
    }
        // #pragma omp parallel for
    for(int cnt = 0; cnt < ProcessorNum; cnt++) {
        if (cnt < ProcessorNum - CrashNum) {
            normal[cnt] = new NormalProcessor(this);
            normal[cnt]->init (cnt, localVal, ProcessorNum, semb, sema, &info);
//            processors[cnt] = std::thread(&CTCFunction::NormalProcessor, this, cnt);
        }

        else {
//            processors[cnt] = std::thread(&CTCFunction::CrashProcessor, this, cnt);
        }
    }
//    for(int cnt = 0; cnt < ProcessorNum; cnt++) {
//        processors[cnt].join ();
//    }
//    sema->~Slock ();
//    for(int cnt = 0; cnt < MAX_PROCESSOR; cnt++)
//    {
//        semb[cnt]->~Slock ();
//    }
//    for(int i = 0; i < ProcessorNum; i++)
//    {
//        std::cout << info[i] << " ";
//    }
//    std::cout << std::endl;
}

CTCFunction::~CTCFunction()
{
    sema->~Slock ();
    for(int cnt = 0; cnt < MAX_PROCESSOR; cnt++)
    {
        semb[cnt]->~Slock ();
    }
}

//int CTCFunction::run(int pNum, int cNum)
//{
//    srand((int)time(0));
////    ProcessorNum = pNum;
//    if(ProcessorNum > MAX_PROCESSOR) {
//        printf("Too many processors!The number of processors may not exceed 200!\n");
//        return 0;
//    }
////    CrashNum = cNum;
//    for(int i = 0; i < ProcessorNum; ++i) {
//        info.push_back(INF);
//    }
//    if(CrashNum >= ProcessorNum) {
//        printf("The number of Crash Failure must be smaller than the number of processors\n");
//        return 0;
//    }

//    std::thread processors[MAX_PROCESSOR];
//    sema = new Slock(1);
//    semb[0] = new Slock(1);
//    for(int i = 1; i < MAX_PROCESSOR; i++) {
//        semb[i] = new Slock(0);
//    }
//        // #pragma omp parallel for
//    for(int cnt = 0; cnt < ProcessorNum; cnt++) {
//        if (cnt < ProcessorNum - CrashNum) {
//            processors[cnt] = std::thread(&CTCFunction::NormalProcessor, this, cnt);
//        }

//        else {
//            processors[cnt] = std::thread(&CTCFunction::CrashProcessor, this, cnt);
//        }
//    }
//    for(int cnt = 0; cnt < ProcessorNum; cnt++) {
//        processors[cnt].join ();
//    }
//    sema->~Slock ();
//    for(int cnt = 0; cnt < MAX_PROCESSOR; cnt++)
//    {
//        semb[cnt]->~Slock ();
//    }
//    for(int i = 0; i < ProcessorNum; i++)
//    {
//        std::cout << info[i] << " ";
//    }
//    std::cout << std::endl;
//    return 0;
//}

//void CTCFunction::CrashProcessor(int pos)
//{
//    int flag=0;
//    localVal[pos] = rand();
//    int randround = rand() % ProcessorNum + 1;
//    std::vector<int> localdata;
//    for(int cnt = 0; cnt < ProcessorNum + 1; cnt++)
//    {
//        semb[pos]->s_lock ();
//        if(cnt >= randround)
//        {
//            flag = 1;
//            semb[(pos + 1) % ProcessorNum]->s_unlock ();
//            if(cnt==randround)
//            {
//                printf("I am the %dth carsh processor failed at round %d,my final value is %d\n", pos,randround, localVal[pos]);
//            }
//            continue;
//        }
//        printf("I am processor %d at round %d\n",pos,cnt);
//        for(int i = 0; i < ProcessorNum; i++) {
//            printf("%d ",info[i]);
//        }
//        printf("\n");
//        sema->s_lock ();
//        info[pos] = std::min(localVal[pos], info[pos]);
//        sema->s_unlock ();
//        localdata.assign(info.begin(),info.end());
//        localVal[pos] = *(min_element(localdata.begin(),localdata.end()));
//        semb[(pos+1)%ProcessorNum]->s_unlock ();
//    }
//    if(flag==0)
//    {
//            printf("I am the %dth normal processor,my final value is %d\n",pos, localVal[pos]);
//    }
//}

//void CTCFunction::NormalProcessor(int pos)
//{
//    std::vector<int> localdata;
//    localVal[pos] = rand();
//    for(int cnt = 0; cnt < ProcessorNum + 1; cnt++) {
//        semb[pos]->s_lock ();
//        printf("I am processor %d at round %d\n",pos,cnt);
//        for(int i=0;i < ProcessorNum;i++) {
//            printf("%d ",info[i]);
//        }
//        printf("\n");
//        sema->s_lock ();
//        info[pos] = std::min(localVal[pos], info[pos]);
//        sema->s_unlock ();

//        localdata.assign(info.begin(),info.end());
//        localVal[pos] = *(min_element(localdata.begin(),localdata.end()));
//        semb[(pos + 1) % ProcessorNum]->s_unlock ();
//    }
//    printf("I am the %dth normal processor,my final value is %d\n",pos, localVal[pos]);
//}