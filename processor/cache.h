//
// Created by kakaroto on 12/08/18.
//

#ifndef CE4302_PROJECT1_CACHE_H
#define CE4302_PROJECT1_CACHE_H
#define SIZE 16
#include <chrono>
#include <string>
#include <thread>
#include <iostream>
#include <pthread.h>
#include <cstring>
#include <vector>
#include "../Communication/messages.h"

class cache {
public:
    cache();
    cache(int);
    bool write(instruction);
    instruction read(instruction);

private:
    msi mem[SIZE];
    int _id;
    void cleanCache();
    void printCache();
    void wait();
};


#endif //CE4302_PROJECT1_CACHE_H
