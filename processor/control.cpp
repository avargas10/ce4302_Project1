//
// Created by kakaroto on 12/08/18.
//

#include "control.h"

control::control():invalidador() {

}
/*
 * Constructor de control
 * */
control::control(controlBus* ics,int pid,cache* pCache,pthread_mutex_t* pMtx,pthread_mutex_t* pCacheLock):invalidador(pid) {
    communication = ics;
    _cache = pCache;
    mtx = pMtx;
    cacheLock = pCacheLock;


}

void control::getListener() {
    pthread_mutex_lock(mtx);
    communication->addControl(this);
    pthread_mutex_unlock(mtx);
}

void control::getOut() {
    pthread_mutex_lock(mtx);
    communication->getControlOut(this);
    pthread_mutex_unlock(mtx);
}