//
// Created by kakaroto on 12/08/18.
//

#ifndef CE4302_PROJECT1_CPU_H
#define CE4302_PROJECT1_CPU_H


      // std::this_thread::sleep_for

#include "cache.h"

using namespace std;
/*
 * CPU Clase encargada de simular las etapas de un procesador
 *
 * */
class cpu {
  public:
    cpu();
    cpu(bus*,int,cache*,pthread_mutex_t*,pthread_mutex_t*);
    bool start();

  private:
    cache *_cache;              //puntero a cache del nodo
    void write(instruction);
    int _id;                    //id del nodo
    fileWriter writer;
    bus *_model;                //puntero al bus del sistema
    pthread_mutex_t *mtx;       //lock del bus
    pthread_mutex_t *cacheLock;
    void read(instruction);
    void writeMem(instruction);
    void readMem(instruction);
    void processing();
    randomGenerator _generator;
    void fetch();
    void exe(instruction);
    void showInstruction(instruction);

};


#endif //CE4302_PROJECT1_CPU_H