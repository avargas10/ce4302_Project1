//
// Created by kakaroto on 12/08/18.
//

#ifndef CE4302_PROJECT1_MAINMEMORY_H
#define CE4302_PROJECT1_MAINMEMORY_H
#define SIZE 16

#include "../Communication/messages.h"
class mainMemory {
public:
    mainMemory();
    bool write(instruction);
    instruction read(instruction);
private:
    int mem[SIZE];
};


#endif //CE4302_PROJECT1_MAINMEMORY_H
