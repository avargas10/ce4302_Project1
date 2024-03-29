//
// Created by kakaroto on 05/09/18.
//

#include "controlBus.h"
invalidador::invalidador() {

}

invalidador::invalidador(int pId) {
    _id = pId;
}

/*
 * Constructor del bus de control
 * */
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

/*
 * Se agrega un control a escuchar el bus de control
 * */
void controlBus::addControl(invalidador *mmu) {

    views.push_back(mmu);
    //cout<<"add "<<views.back()->_id<<endl;

}


pthread_mutex_t* controlBus::getLock() {
    return &messageLock;
}

/*
 * Se invalida una posicion de memoria cache y los controladores escuchan
 * */
void controlBus::invalid(instruction pIns)  {
    //pthread_mutex_lock(&messageLock);
    for (int i = 0; i <views.size() ; ++i) {
        if(views[i]->_id!=pIns.node){
            views[i]->setInvalid(pIns);
        }
    }
    //pthread_mutex_unlock(&messageLock);
}

/*
* se desconecta un control del bus
* */
void controlBus::getControlOut(invalidador *mmu) {
    for (int i = 0; i <views.size() ; ++i) {
        if(mmu->_id==views[i]->_id){
            views.erase(views.begin()+i);
            //cout<<"Free "<<mmu->_id<<endl;
        }
    }
}

/*
* Se comparte una posicion de memoria cache y los controladores escuchan
* */
void controlBus::shared(instruction pIns){

    for (int i = 0; i <views.size() ; ++i) {
        if(views[i]->_id!=pIns.node){
            views[i]->setShared(pIns);
        }
    }

}