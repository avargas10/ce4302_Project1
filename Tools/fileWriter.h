//
// Created by kakaroto on 05/09/18.
//

#ifndef CE4302_PROJECT1_FILEWRITER_H
#define CE4302_PROJECT1_FILEWRITER_H

#include "../Communication/messages.h"
#include "JsonCodeDecode.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class fileWriter {
public:
    fileWriter();
    fileWriter(int);
    void writeCPU(instruction);
    void writeCache(message);
    void writeNofication(message);
    void updateCache(msi*);
    void updateMainMem(int*);

private:
    int _id;
    Json_Code_Decode parser;
    string path = "../Data/";
    string generateInstruction(instruction);
    string generateMessage(message);
    string generateNotification(message);
    string generateMem(int*);
    string generateCache(msi[]);
    Json::Value getJson(msi);
};


#endif //CE4302_PROJECT1_FILEWRITER_H
