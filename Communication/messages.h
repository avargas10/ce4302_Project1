//
// Created by kakaroto on 02/09/18.
//

#ifndef CE4302_PROJECT1_MESSAGES_H
#define CE4302_PROJECT1_MESSAGES_H

#endif //CE4302_PROJECT1_MESSAGES_H

#include <chrono>
#include <string>
#include <thread>
#include <iostream>


struct instruction{
    int _action = 0;
    int _data = 0;
    int _pos = 0;
    bool _done = 0;
    int node = 0;
};

struct message{
    int action = 0;
    int pos = 0;
    int data = 0;
    int invalid = 0;
    std::string notifaction;

};



struct msi{
    bool _invalid = 0;
    int _data = 0;
    bool _shared = 0;
    int pos = 0;
    int node = 0;
};


