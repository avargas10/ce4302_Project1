//
// Created by kakaroto on 05/09/18.
//

#include "JsonCodeDecode.h"


Json_Code_Decode::Json_Code_Decode() {

}
Json::Value Json_Code_Decode::getJson(string pJson) {
    if (isJson(pJson)) {
        Json::Value root;
        Json::Reader reader;
        reader.parse(pJson, root);
        return root;
    } else {
        return 0;
    }
}

bool Json_Code_Decode::isJson(string pJson) {
    Json::Value root;
    Json::Reader reader;
    bool done = reader.parse(pJson, root);
    std::cout << "parse = " << done << std::endl;
    return done;
}

string Json_Code_Decode::getString(Json::Value pJson, string pKey) {
    string key1 = pJson[pKey].asString();
    return key1;
}
bool Json_Code_Decode::getBool(Json::Value pJson, string pKey) {
    bool key1 = pJson[pKey].asBool();
    return key1;
}

Json::Value Json_Code_Decode::includeString(string pKey, Json::Value pJson,
                                            string pData) {
    pJson[pKey] = pData;
    return pJson;
}

Json::Value Json_Code_Decode::includeInt(int pData, Json::Value pJson, string pKey) {
    pJson[pKey] = pData;
    return pJson;
}

int Json_Code_Decode::getInt(Json::Value pJson, string pKey) {
    int key1 = pJson[pKey].asInt();
    return key1;
}
double Json_Code_Decode::getDouble(Json::Value pJson, string pKey) {
    double key1 = pJson[pKey].asDouble();
    return key1;
}