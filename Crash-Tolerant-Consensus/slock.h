#ifndef SLOCK_H
#define SLOCK_H

#include <QObject>
#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

class Slock
{
public:
    sem_t *semp;
    char name[20];

    Slock(unsigned int i);
    ~Slock();
    void s_lock();
    void s_unlock();
};

#endif // SLOCK_H
