//
// Created by kakaroto on 12/08/18.
//

#ifndef CE4302_PROJECT1_MAINMEMORY_H
#define CE4302_PROJECT1_MAINMEMORY_H
#define SIZE 16


#include "../Tools/fileWriter.h"
using namespace std;
class mainMemory {

public:
    mainMemory();
    instruction write(instruction);
    instruction read(instruction);
private:
    int mem[SIZE];
    void printMem();
    void cleanMem();
};


#endif //CE4302_PROJECT1_MAINMEMORY_H
