//
// Created by kakaroto on 12/08/18.
//

#include "cpu.h"
#include "cache.cpp"
using namespace std;

cpu::cpu(int pid,cache* pCache) {
    _id = pid;
    _generator = randomGenerator(_id);
    _cache = pCache;
}

cpu::cpu() {

}


void cpu::start() {
    for (int i = 0; i < 4 ; ++i) {
        fetch();
        exe();
    }
}


void cpu::test() {
    for (int i = 0; i < 10; ++i) {
        cout<<"I am CPU "<<_id<<endl;
        std::this_thread::sleep_for (std::chrono::seconds(1));
    }
}

void cpu::fetch() {
    _ins._action = _generator.getTask();
    _ins._pos = _generator.getPos();
    if(_ins._action){
       _ins._data =  _generator.getData();
    }
    showInstruction();
}

void cpu::exe() {
    if(_ins._action){
        write();
    } else{
        read();
    }
}

void cpu::write() {
    cout<<"|CPU "<<_id<<" | -----Writing------|"<<endl;
    cout<<"|Pos "<<_ins._pos<<" |Data "<<_ins._data<<"|"<<endl;
    cout<<"-----------------------------------"<<endl;
    _cache->write(_ins);
}

void cpu::read() {
    cout<<"|CPU "<<_id<<" | -----Reading------|"<<endl;
    cout<<"|Pos "<<_ins._pos<<" |Data "<<_ins._data<<"|"<<endl;
    cout<<"-----------------------------------"<<endl;
    _cache->read(_ins);
}

void cpu::showInstruction() {
    cout<<"Instruction---------"<<endl;
    cout<<"Action: "<<_ins._action<<endl;
    cout<<"Position: "<<_ins._pos<<endl;
    cout<<"Data: "<<_ins._data<<"\n"<<endl;


}