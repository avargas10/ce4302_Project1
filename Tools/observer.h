//
// Created by kakaroto on 02/09/18.
//

#ifndef CE4302_PROJECT1_OBSERVER_H
#define CE4302_PROJECT1_OBSERVER_H

#include <iostream>
#include <vector>
#include "../Communication/messages.h"
using namespace std;

class bus {
    // 1. "independent" functionality
    vector < class Observer * > views; // 3. Coupled only to "interface"
    int value;
    bool busy;
public:
    void attach(Observer *obs) {
        views.push_back(obs);
    }
    void setVal(int val) {
        value = val;
        notify();
    }
    bool useMem(instruction _ins){
        if(busy){

            return false;
        }
        return true;


    }
    bool isBusy(){
        return busy;
    }
    int getVal() {
        return value;
    }
    void notify();
};



class Observer {
    // 2. "dependent" functionality
    bus *model;
    int _id;
public:
    Observer(bus *mod, int pId) {
        model = mod;
        _id = pId;
        // 4. Observers register themselves with the bus
        model->attach(this);
    }
    virtual void update() = 0;
    bus *getBus() {
        return model;
    }
    int getId() {
        return _id;
    }
};


#endif //CE4302_PROJECT1_OBSERVER_H
