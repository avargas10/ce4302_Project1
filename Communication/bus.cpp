//
// Created by kakaroto on 05/09/18.
//

#include "bus.h"
#include "../memory/mainMemory.cpp"

bus::bus(mainMemory * pMem,controlBus* pControl, pthread_mutex_t* controlLock) {
    memory = pMem;
    control = pControl;
    mtx = controlLock;
}



void bus::writeMem(instruction pIns){
    if(memory->write(pIns)){
        msi message;
        message.state = 0;
        message.pos = pIns._pos;
        cout<<"Invalidading"<<endl;
        pthread_mutex_lock(mtx);
        control->invalid(pIns);
        pthread_mutex_unlock(mtx);
    }
}


instruction bus::readMem(instruction pIns) {
    instruction res = memory->read(pIns);
    if(res._done){
        cout<<"Sharing"<<endl;
        pthread_mutex_lock(mtx);
        control->shared(pIns);
        pthread_mutex_unlock(mtx);
        return  res;
    }
}

void bus::invalid(msi message) {
    for (int i = 0; i < views.size() ; ++i) {
        views[i]->pos= message.pos;
        views[i]->state = 0;
    }
}
