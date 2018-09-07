//
// Created by kakaroto on 12/08/18.
//

#ifndef CE4302_PROJECT1_CONTROL_H
#define CE4302_PROJECT1_CONTROL_H

#include "cache.h"

class control: public invalidador{
public:
    control();
    control(controlBus*,int,cache*,pthread_mutex_t*,pthread_mutex_t*);
    void setInvalid(instruction pIns)  {
       // cout<<"Invalid "<<_id<<endl;
        _cache->setInvalid(pIns._pos);

    }
    void setShared(instruction pIns)  {
        //cout<<"Shared "<<_id<<endl;
        _cache->setShared(pIns._pos);

    }
    void getOut();

private:
    cache *_cache;
    pthread_mutex_t *mtx;
    pthread_mutex_t* cacheLock;
    pthread_mutex_t* messageLock;
    controlBus *communication;
    void getListener();



};


#endif //CE4302_PROJECT1_CONTROL_H
