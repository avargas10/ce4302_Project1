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

bool randomGenerator::getTask() {
    int number = generate(0,20000);
    return number%2==0;
}

int randomGenerator::getData() {
    return generate(0,20000);
}

int randomGenerator::getPos() {
    return generate(0,15);
}

int randomGenerator::generate(int min, int max) {
    srand(_id*time(NULL));
    return rand() % max + min;
}