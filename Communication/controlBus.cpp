//
// Created by kakaroto on 05/09/18.
//

#include "controlBus.h"
invalidador::invalidador() {

}

invalidador::invalidador(int pId) {
    _id = pId;
}
controlBus::controlBus(pthread_mutex_t* pMtx) {
    mtx  = pMtx;
    initLock();
}


void controlBus::initLock() {
    if (pthread_mutex_init(&messageLock, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return ;
    }
}

void controlBus::addControl(invalidador *mmu) {

    views.push_back(mmu);
    //cout<<"add "<<views.back()->_id<<endl;

}



pthread_mutex_t* controlBus::getLock() {
    return &messageLock;
}


void controlBus::invalid(instruction pIns)  {
    cout<<"Get in"<<endl;
    //pthread_mutex_lock(&messageLock);
    for (int i = 0; i <views.size() ; ++i) {
        views[i]->setInvalid(pIns);
    }
    //pthread_mutex_unlock(&messageLock);



}