//
// Created by kakaroto on 12/08/18.
//

#include "mainMemory.h"

mainMemory::mainMemory() {
    cleanMem();
    writer= fileWriter();
}
/*
 * Escritura de dato en array de memoria
 * */
bool mainMemory::write(instruction pIns) {
    std::this_thread::sleep_for (std::chrono::seconds(2));
    mem[pIns._pos]=pIns._data;
    writer.updateMainMem(mem);
    //printMem();
    return true;
}
/*
 * Lectura de dato en array de memoria
 * */
instruction mainMemory::read(instruction pIns) {
    std::this_thread::sleep_for (std::chrono::seconds(2));
    pIns._data = mem[pIns._pos];
    pIns._done = true;
    //printMem();
    return pIns;
}


void mainMemory::printMem() {
        cout<<"Main Memory ----------"<<endl;
        cout<<"|   POS   |"<<"|   DATA   |"<<endl;
        for (int i = 0; i <15 ; ++i) {
            cout<<"|    "<<i<<"    |"<<"|   "<<mem[i]<<"   |"<<endl;
        }

}

/*
 * Limpia el array de memoria
 * */
void mainMemory::cleanMem() {
    for (int i = 0; i <SIZE ; ++i) {
        mem[i] =0;
    }
}
