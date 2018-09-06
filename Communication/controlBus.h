//
// Created by kakaroto on 05/09/18.
//

#ifndef CE4302_PROJECT1_CONTROLBUS_H
#define CE4302_PROJECT1_CONTROLBUS_H
#include "../memory/mainMemory.h"
#include <iostream>
#include <vector>


class invalidador{
public:
    int _id;
    invalidador();
    invalidador(int);
    virtual void setInvalid(instruction pIns) = 0;
};


class controlBus {
public:
    controlBus();


    controlBus(pthread_mutex_t*);
    void addControl(invalidador*);
    msi* getPosition(int pId);

    void invalid(instruction);

    pthread_mutex_t* getLock();


private:
    vector <invalidador*> views; // 3. Coupled only to "interface"
    pthread_mutex_t* mtx;
    pthread_mutex_t messageLock;
    void initMessage();
    void initLock();

};


#endif //CE4302_PROJECT1_CONTROLBUS_H
