//
// Created by kakaroto on 05/09/18.
//

#include "bus.h"
#include "../memory/mainMemory.cpp"
/*
 * COnstructor del bus principal
 * */
bus::bus(mainMemory * pMem,controlBus* pControl, pthread_mutex_t* controlLock) {
    memory = pMem;
    control = pControl;
    mtx = controlLock;
}
/*
 * Bus envia instruccion a la memoria para escribir un dato
 * */
void bus::writeMem(instruction pIns){
    if(memory->write(pIns)){
        pthread_mutex_lock(mtx);
        control->invalid(pIns);
        pthread_mutex_unlock(mtx);
    }
}

/*
 * Bus envia instruccion a la memoria para leer un dato
 * */
instruction bus::readMem(instruction pIns) {
    instruction res = memory->read(pIns);
    if(res._done){
        //cout<<"Sharing"<<endl;
        pthread_mutex_lock(mtx);
        control->shared(pIns);
        pthread_mutex_unlock(mtx);
        return  res;
    }
}

