//
// Created by kakaroto on 12/08/18.
//

#ifndef CE4302_PROJECT1_CPU_H
#define CE4302_PROJECT1_CPU_H


      // std::this_thread::sleep_for

#include "cache.h"
#include "../Tools/randomGenerator.h"
using namespace std;

class cpu {
  public:
    cpu();
    cpu(int,cache*);
    int _id;
    int _clock;
    int *_stages;
    int _currentStage;
    void start();
    void test();


  private:
    cache *_cache;
    instruction _ins;
    void write();
    void read();
    randomGenerator _generator;
    void fetch();
    void exe();
    void showInstruction();

};


#endif //CE4302_PROJECT1_CPU_H