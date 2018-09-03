//
// Created by kakaroto on 12/08/18.
//

#include "cache.h"
using namespace std;
cache::cache() {
    cleanCache();
}
cache::cache(int pId) {
    _id = pId;
    cleanCache();
}

void cache::cleanCache() {
    for (int i = 0; i <SIZE ; ++i) {
        mem[i]._data =0;
    }
}

bool cache::write(instruction pIns) {
    if(mem[pIns._pos]._invalid){
        wait();
        return false;
    }
    else{
        mem[pIns._pos]._data = pIns._data;
        wait();
        return true;
    }
}

instruction cache::read(instruction pIns) {
    if(mem[pIns._pos]._invalid){
        pIns._done = false;
        wait();
        return pIns;
    }
    else{
        pIns._done = true;
        pIns._data = mem[pIns._pos]._data;
        wait();
        return pIns;
    }
}

void cache::wait(){
    std::this_thread::sleep_for (std::chrono::seconds(1));
    //printCache();
}

void cache::printCache() {
    cout<<"Cache: "<<_id<<"----------"<<endl;
    cout<<"|   POS   |"<<"|   DATA   |"<<endl;
    for (int i = 0; i <15 ; ++i) {
        cout<<"|    "<<i<<"    |"<<"|   "<<mem[i]._data<<"   |"<<endl;
    }
}