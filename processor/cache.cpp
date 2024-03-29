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
/*
 * Se limpia el array de cache
 * */
void cache::cleanCache() {
    for (int i = 0; i <SIZE ; ++i) {
        mem[i]._data =0;
        mem[i].state = 1;
        mem[i].pos = i;
    }
}

/*
 * Escritura de dato en array de cache
 * */
bool cache::write(instruction pIns) {
        mem[pIns._pos]._data = pIns._data;
        mem[pIns._pos].state = 2;
        pIns._done = 2;
        wait();
        //sendMessage(pIns);
        updateCache();
        return true;
}

/*
 * Escritura de dato despues de reading miss en array de cache
 * */
void cache::directWrite(instruction pIns) {
    mem[pIns._pos]._data = pIns._data;
    mem[pIns._pos].state = 1;
    pIns._done= 1;
    wait();
    //sendMessage(pIns);
    updateCache();
}

/*
 * Lectura de dato en array de cache
 * */
instruction cache::read(instruction pIns) {
    if(mem[pIns._pos].state==0){
        pIns._done = 0;
        //sendMessage(pIns);
        //cout<<"Miss Invalid Cache Position"<<endl;
        return pIns;
    }
    else{
        pIns._done = mem[pIns._pos].state;
        pIns._data = mem[pIns._pos]._data;
        //sendMessage(pIns);
        wait();
        return pIns;
    }
}

/*
 * Posicion de memoria pPos pasa a ser compartida
 * */
void cache::setShared(int pPos ) {
    if(mem[pPos].state==2){
        mem[pPos].state= 1;
        message msg;
        msg.state = 1;
         msg.pos = pPos;
        msg.notifaction = "Shared Position";
        msg.data = 0;
        msg.action = 0;
        writer.writeNofication(msg);
        updateCache();
    }

}

/*
 * Posicion de memoria pPos pasa a ser invalida
 * */
void cache::setInvalid(int pPos ) {
    mem[pPos].state = 0;
    message msg;
    msg.state = 0;
    msg.pos = pPos;
    msg.notifaction = "Invalid Position";
    msg.data = 0;
    msg.action = 0;
    writer.writeNofication(msg);
    updateCache();
}

/*
 *Ciclos de acceso 1 ciclo
 * */
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
    msg.state = pIns._done;
    msg.action = pIns._action;
    msg.data = pIns._data;
    msg.pos = pIns._pos;

    if(msg.state==0){
        msg.notifaction= "Reading Miss";
        writer.writeNofication(msg);

    }
    writer.writeCache(msg);
}

/*
 * Notifica cambios en la cache
 * */
void cache::updateCache() {
    writer.updateCache(mem);
}