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
    cache _cache;       //cache del nodo #n
    cpu _cpu;           //cpu del nodo #n
    control _mmu;       //control del nodo #n
    pthread_mutex_t cacheLock;
    pthread_mutex_t* _mtx;


};


#endif //CE4302_PROJECT1_NODE_H
