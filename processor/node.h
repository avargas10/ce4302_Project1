//
// Created by kakaroto on 02/09/18.
//

#ifndef CE4302_PROJECT1_NODE_H
#define CE4302_PROJECT1_NODE_H




#include "cpu.h"
#include "control.h"

class node{
public:
    node(bus*,controlBus*,int,pthread_mutex_t*,pthread_mutex_t*);
    void start();

    //int getId();
private:
    void initCacheLock();
    cache _cache;
    cpu _cpu;
    pthread_mutex_t cacheLock;
    control _mmu;

};


#endif //CE4302_PROJECT1_NODE_H
