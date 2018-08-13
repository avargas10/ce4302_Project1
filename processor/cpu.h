//
// Created by kakaroto on 12/08/18.
//

#ifndef CE4302_PROJECT1_CPU_H
#define CE4302_PROJECT1_CPU_H

#include <string>

class cpu {
  public:
    int _id;
    int _clock;
    int *_stages;
    int _currentStage;
    int *_instruction;

};


#endif //CE4302_PROJECT1_CPU_H
