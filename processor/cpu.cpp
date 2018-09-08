//
// Created by kakaroto on 12/08/18.
//

#include "cpu.h"
#include "cache.cpp"
//#include "../Tools/observer.cpp"
using namespace std;
/*
 * Constructor de la clase
 * */
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
/*
 * Funcion encargada de generar el loop de ejecucion del procesador
 * Notifica cuando termina el procesador
 * */
bool cpu::start() {
    for (int i = 0; i < 10; ++i) {
        fetch();
    }
    instruction pIns;
    pIns._action=4;
    writer.writeCPU(pIns);
    return true;

}

/*
 * Metodo encargado de generar la instruccion que va a ejecutar el sistema
 * */
void cpu::fetch() {
    instruction _ins;
    _ins._action = _generator.getTask();
   _ins.node = _id;
   _ins._pos = _generator.getPos(_ins._action+1);
   _ins._data=0;
    if(_ins._action==1){
       _ins._data = _id;
    }
    writer.writeCPU(_ins);
    exe(_ins);

}
/*
 * Metodo encargado de ejecutar la instruccion generada
 * */
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
/*
 * Metodo encargado de escribir un dato en cache
 * _ins = instruccion contiene dato y posicion
 * */
void cpu::write(instruction _ins) {
   // cout<<"|CPU "<<_id<<" | -----Writing------|"<<endl;
    _cache->write(_ins);
    writeMem(_ins);

}
/*
 * Metodo encargado de hacer un request al bus de la memoria
 * _ins = instruccion contiene dato y posicion
 * */
void cpu::writeMem(instruction _ins) {
    pthread_mutex_lock(mtx);
         _model->writeMem(_ins);
    pthread_mutex_unlock(mtx);
}
/*
 * Metodo encargado de hacer una lectura de cache
 * _ins = instruccion contiene dato y posicion
 * */
void cpu::read(instruction _ins) {
    //cout<<"|CPU "<<_id<<" | -----Reading------|"<<endl;
   //pthread_mutex_lock(cacheLock);
   bool res = _cache->read(_ins)._done;
   //pthread_mutex_unlock(cacheLock);
   if(!res){
       _ins._action=3;
       writer.writeCPU(_ins);
        readMem(_ins);
    }

}
/*
 * Metodo encargado de hacer un request de lectura al bus
 * _ins = instruccion contiene dato y posicion
 * */
void cpu::readMem(instruction _ins) {
    instruction res;
    pthread_mutex_lock(mtx);
         res = _model->readMem(_ins);
    pthread_mutex_unlock(mtx);
    _cache->directWrite(res);
}
/*
 * Metodo encargado de processar durante un ciclo
 * */
void cpu::processing() {
   // cout<<"|CPU "<<_id<<" | -----Processing------|"<<endl;
    std::this_thread::sleep_for (std::chrono::seconds(1));
}

void cpu::showInstruction(instruction _ins) {
    cout<<"Instruction---------"<<endl;
    cout<<"Action: "<<_ins._action<<endl;
    cout<<"Position: "<<_ins._pos<<endl;
    cout<<"Data: "<<_ins._data<<"\n"<<endl;


}