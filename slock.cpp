#include "slock.h"


Slock::Slock(unsigned int i)
{
    static int cnt;
    do {
        snprintf(this->name, sizeof(this->name), "/%ld.%d", (long)getpid(), cnt++);
        this->semp = sem_open(this->name, O_CREAT|O_EXCL, S_IRWXU, i);
    } while ((this->semp == SEM_FAILED) && (errno == EEXIST));
    if (this->semp == SEM_FAILED) {
        free(this);
    }
    sem_unlink(this->name);
}

Slock::~Slock()
{
    sem_close(this->semp);
}

void Slock::s_lock()
{
    sem_wait (this->semp);
}

void Slock::s_unlock()
{
    sem_post (this->semp);
}
