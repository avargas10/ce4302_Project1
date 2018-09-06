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
#include <mutex>
#include "../Tools/randomGenerator.h"
#include "../Tools/fileWriter.h"
#include "../Communication/bus.h"



class cache {
public:
    cache();
    cache(int);
    bool write(instruction);
    void directWrite(instruction);
    instruction read(instruction);
    void setInvalid(int);
    void setShared(int);

private:
    msi mem[SIZE];
    int _id;
    fileWriter writer;
    void sendMessage(instruction);
    void sendNotification(instruction,string);
    void cleanCache();
    void printCache();
    void updateCache();
    void wait();
};


#endif //CE4302_PROJECT1_CACHE_H
