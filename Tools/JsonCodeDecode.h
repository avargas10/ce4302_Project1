//
// Created by kakaroto on 05/09/18.
//

#ifndef CE4302_PROJECT1_JSONCODEDECODE_H
#define CE4302_PROJECT1_JSONCODEDECODE_H


#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <pthread.h>

#include "jsoncpp/json/json.h"

using namespace std;
class Json_Code_Decode {
public:
    Json_Code_Decode();
    void getJsonData(string, string);
    int getInt(Json::Value, string);
    bool getBool(Json::Value, string);
    double getDouble(Json::Value, string);
    char* getChar(Json::Value, string);
    string getString(Json::Value, string);
    Json::Value getJson(string);
    bool isJson(string);
    Json::Value includeString(string, Json::Value, string);
    Json::Value includeInt(int, Json::Value, string);
private:



};


#endif //CE4302_PROJECT1_JSONCODEDECODE_H
