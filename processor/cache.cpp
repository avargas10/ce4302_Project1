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
    writer = fileWriter(pId);
}

void cache::cleanCache() {
    for (int i = 0; i <SIZE ; ++i) {
        mem[i]._data =0;
        mem[i]._invalid = 1;
        mem[i]._shared = 0;
    }
}

bool cache::write(instruction pIns) {
        mem[pIns._pos]._data = pIns._data;
        pIns._done = true;
        wait();
        sendMessage(pIns);
        return true;
}

void cache::directWrite(instruction pIns) {
    mem[pIns._pos]._data = pIns._data;
    pIns._done= true;
    sendMessage(pIns);
}

instruction cache::read(instruction pIns) {
    if(mem[pIns._pos]._invalid){
        pIns._done = false;
        sendMessage(pIns);
        //cout<<"Miss Invalid Cache Position"<<endl;
        return pIns;
    }
    else{
        pIns._done = true;
        pIns._data = mem[pIns._pos]._data;
        sendMessage(pIns);
        wait();
        return pIns;
    }
}

void cache::setInvalid(int pPos) {
    mem[pPos]._invalid = true;
    message msg;
    msg.invalid = true;
    msg.pos = pPos;
    msg.notifaction = "Invalid Position";
    msg.data = 0;
    msg.action = 0;
    writer.writeNofication(msg);
}

void cache::wait(){
    std::this_thread::sleep_for (std::chrono::seconds(1));
    //printCache();
}

void cache::printCache() {
    cout<<"Main Memory: "<<_id<<"----------"<<endl;
    cout<<"|   POS   |"<<"|   DATA   |"<<endl;
    for (int i = 0; i <15 ; ++i) {
        cout<<"|    "<<i<<"    |"<<"|   "<<mem[i]._data<<"   |"<<endl;
    }
}

void cache::sendMessage(instruction pIns) {
    message msg;
    msg.invalid = !pIns._done;
    msg.action = pIns._action;
    msg.data = pIns._data;
    msg.pos = pIns._pos;
    if(msg.invalid){
        msg.notifaction= "Reading Miss";
        writer.writeNofication(msg);
    }
    writer.writeCache(msg);


}