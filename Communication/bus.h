//
// Created by kakaroto on 05/09/18.
//

#ifndef CE4302_PROJECT1_BUS_H
#define CE4302_PROJECT1_BUS_H




#include "controlBus.h"
using namespace std;

class bus {
    // 1. "independent" functionality

public:
    bus();
    bus(mainMemory*,controlBus*, pthread_mutex_t*);

    msi* getPosition();

    void invalid(msi);

    int getVal() {
        return value;
    }

    instruction readMem(instruction pIns);

    void writeMem(instruction pIns);

private:
    vector <msi*> views; // 3. Coupled only to "interface"
    int value;
    bool busy;
    mainMemory* memory;
    controlBus* control;
    pthread_mutex_t* mtx;
};


#endif //CE4302_PROJECT1_BUS_H
