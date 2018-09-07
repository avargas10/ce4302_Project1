//
// Created by kakaroto on 02/09/18.
//

#include "randomGenerator.h"
#include <ctime>
#include <cstdlib>
randomGenerator::randomGenerator(int pId) {
    _id = pId;
}

randomGenerator::randomGenerator() {

}

int randomGenerator::getTask() {
    return generate(0,3,_id);
}

int randomGenerator::getData(int task) {
    return generate(0,20000,task);
}

int randomGenerator::getPos(int task) {
    return generate(0,15,task);
}

int randomGenerator::generate(int min, int max,int task) {
    srand(task*_id*time(NULL));
    return rand() % max + min;
}