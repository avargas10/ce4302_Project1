//
// Created by kakaroto on 02/09/18.
//

#include "node.h"


node::node(bus *ics,controlBus* icsC,int pId,pthread_mutex_t* mtx,pthread_mutex_t* controlMtx){
    initCacheLock();
    _mtx= mtx;
    _cache = cache(pId);
    _cpu = cpu(ics,pId,&_cache,mtx,&cacheLock);
    _mmu = control(icsC,pId,&_cache,controlMtx,&cacheLock);
    icsC->addControl(&_mmu);

    //cout<<"Node "<<pId<<" Created"<<endl;

}

void node::initCacheLock() {
    if (pthread_mutex_init(&cacheLock, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return ;
    }
}
void node::start() {
   if(_cpu.start()){
       _mmu.getOut();
   }

}





