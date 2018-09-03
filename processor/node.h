//
// Created by kakaroto on 02/09/18.
//

#ifndef CE4302_PROJECT1_NODE_H
#define CE4302_PROJECT1_NODE_H



#include "../Tools/observer.h"
#include "cpu.h"
#include "control.h"

class node : public Observer{
public:
    node(bus*,int);
    void start();
    void update();
    //int getId();
private:
    cache _cache;
    cpu _cpu;
    control _mmu;

};


#endif //CE4302_PROJECT1_NODE_H
