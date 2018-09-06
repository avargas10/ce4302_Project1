//
// Created by kakaroto on 02/09/18.
//

#include "node.h"


node::node(bus *ics,controlBus* icsC,int pId,pthread_mutex_t* mtx,pthread_mutex_t* controlMtx){
    initCacheLock();
    _cache = cache(pId);
    _cpu = cpu(ics,pId,&_cache,mtx,&cacheLock);
    _mmu = control(icsC,pId,&_cache,controlMtx,&cacheLock);
    icsC->addControl(&_mmu);

    //cout<<"Node "<<pId<<" Created"<<endl;

}

/*void *initCPU(void* args){
    cpu *_cpu = (cpu *)args;
    _cpu->start();
}

void* initMMU(void *args){
    control *_mmu = (control *)args;
    _mmu->start();
}*/


void node::initCacheLock() {
    if (pthread_mutex_init(&cacheLock, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return ;
    }
}
void node::start() {
   _cpu.start();
    /* int ret;
    pthread_t cpu;
    pthread_t mmu;
    if ((ret = pthread_create(&mmu, NULL, initMMU, &_mmu) ) != 0) {
        cout << "Error creating thread: " << strerror(ret) << endl;
        exit(1);
    }
    if ((ret = pthread_create(&cpu, NULL, initCPU, &_cpu) ) != 0) {
        cout << "Error creating thread: " << strerror(ret) << endl;
        exit(1);
    }*/

    //pthread_join(cpu,NULL);
    //pthread_join(mmu,NULL);

}





