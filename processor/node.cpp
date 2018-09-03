//
// Created by kakaroto on 02/09/18.
//

#include "node.h"


node::node(bus *ics,int pId):Observer(ics,pId){
    _cache = cache(pId);
    _cpu = cpu(pId,&_cache);
    _mmu = control();
    cout<<"Node "<<pId<<" Created"<<endl;
}

void node::start() {
        //_cpu.start();
        getBus()->notify();

}

void node::update() {
    cout<<"Id "<<getId()<<endl;
}