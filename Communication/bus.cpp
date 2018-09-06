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
    if((instruction*)memory->write(pIns)._done){
        msi message;
        message._invalid = true;
        message.pos = pIns._pos;
        cout<<"Invalidading"<<endl;
        //pthread_mutex_lock(mtx);
        control->invalid(pIns);
        //pthread_mutex_unlock(mtx);
    }
}


instruction bus::readMem(instruction pIns) {
    instruction res = memory->read(pIns);
    if(res._done){
        return  res;
    }
}

void bus::invalid(msi message) {
    for (int i = 0; i < views.size() ; ++i) {
        views[i]->pos= message.pos;
        views[i]->_invalid = true;
    }
}
