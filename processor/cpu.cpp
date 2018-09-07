//
// Created by kakaroto on 12/08/18.
//

#include "cpu.h"
#include "cache.cpp"
//#include "../Tools/observer.cpp"
using namespace std;

cpu::cpu(bus* ics,int pid,cache* pCache,pthread_mutex_t* pMtx,pthread_mutex_t* pCacheLock) {
    _generator = randomGenerator(pid);
    _id = pid;
    _model = ics;
    _cache = pCache;
    writer = fileWriter(pid);
    cacheLock = pCacheLock;
    mtx = pMtx;
}

cpu::cpu() {

}

bool cpu::start() {
    for (int i = 0; i < 100     ; ++i) {
        fetch();
    }
    return true;

}


void cpu::fetch() {
    instruction _ins;
    _ins._action = _generator.getTask();
   _ins.node = _id;
   _ins._pos = _generator.getPos(_ins._action+1);
   _ins._data=0;
    if(_ins._action==1){
       //_ins._data =  _generator.getData(_ins._action+1);
       _ins._data = _id;
    }
    //showInstruction(_ins);
    writer.writeCPU(_ins);
    exe(_ins);

}

void cpu::exe(instruction _ins) {
    switch (_ins._action){
        case 0:
            read(_ins);
            break;
        case 1:
            write(_ins);
            break;
        case 2:
            processing();
            break;
    }
}

void cpu::write(instruction _ins) {
    cout<<"|CPU "<<_id<<" | -----Writing------|"<<endl;
    /*cout<<"|Pos "<<_ins._pos<<" |Data "<<_ins._data<<"|"<<endl;
    cout<<"-----------------------------------"<<endl;*/
    _cache->write(_ins);
    writeMem(_ins);

}

void cpu::writeMem(instruction _ins) {
    pthread_mutex_lock(mtx);
         _model->writeMem(_ins);
    pthread_mutex_unlock(mtx);
}

void cpu::read(instruction _ins) {
    cout<<"|CPU "<<_id<<" | -----Reading------|"<<endl;
   /* cout<<"|Pos "<<_ins._pos<<endl;
    cout<<"-----------------------------------"<<endl;*/
   //pthread_mutex_lock(cacheLock);
   bool res = _cache->read(_ins)._done;
   //pthread_mutex_unlock(cacheLock);
   if(!res){
        readMem(_ins);
    }

}

void cpu::readMem(instruction _ins) {
    instruction res;
    pthread_mutex_lock(mtx);
         res = _model->readMem(_ins);
    pthread_mutex_unlock(mtx);
    _cache->directWrite(res);
}

void cpu::processing() {
    cout<<"|CPU "<<_id<<" | -----Processing------|"<<endl;
    std::this_thread::sleep_for (std::chrono::seconds(1));
}

void cpu::showInstruction(instruction _ins) {
    cout<<"Instruction---------"<<endl;
    cout<<"Action: "<<_ins._action<<endl;
    cout<<"Position: "<<_ins._pos<<endl;
    cout<<"Data: "<<_ins._data<<"\n"<<endl;


}