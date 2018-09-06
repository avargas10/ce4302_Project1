//
// Created by kakaroto on 05/09/18.
//

#include "fileWriter.h"


fileWriter::fileWriter() {

}

fileWriter::fileWriter(int pId) {
    _id = pId;
    parser = Json_Code_Decode();
}

void fileWriter::writeCPU(instruction pIns) {
    std::ofstream out;
    string id = std::to_string(_id);
    out.open(path+"cpu/cpu"+id+".txt", std::ios::app);
    std::string str = generateInstruction(pIns)+"\n";
    out << str;
    out.close(); // close the file
}

void fileWriter::writeCache(message msg) {
    std::ofstream out;
    string id = std::to_string(_id);
    out.open(path+"cache/cache"+id+".txt", std::ios::app);
    std::string str = generateMessage(msg)+"\n";
    out << str;
    out.close(); // close the file
}
void fileWriter::writeNofication(message msg) {
    std::ofstream out;
    string id = std::to_string(_id);
    out.open(path+"notifications/notify"+id+".txt", std::ios::app);
    std::string str = generateNotification(msg)+"\n";
    out << str;
    out.close(); // close the file
}

string fileWriter::generateInstruction(instruction pIns) {
    Json::Value root;
    root = parser.includeString("cpu",root,std::to_string(_id));
    root = parser.includeString("action",root,std::to_string(pIns._action));
    root = parser.includeString("position",root,std::to_string(pIns._pos));
    root = parser.includeString("data",root,std::to_string(pIns._data));
    Json::FastWriter fastWriter;
    std::string output = fastWriter.write(root);
    return output;
}

string fileWriter::generateMessage(message msg) {
    Json::Value root;
    root = parser.includeString("node",root,std::to_string(_id));
    root = parser.includeString("invalid",root,std::to_string(msg.invalid));
    root = parser.includeString("action",root,std::to_string(msg.action));
    root = parser.includeString("position",root,std::to_string(msg.pos));
    root = parser.includeString("data",root,std::to_string(msg.data));
    Json::FastWriter fastWriter;
    std::string output = fastWriter.write(root);
    return output;
}

string fileWriter::generateNotification(message msg) {
    Json::Value root;
    root = parser.includeString("node",root,std::to_string(_id));
    root = parser.includeString("invalid",root,std::to_string(msg.invalid));
    root = parser.includeString("action",root,std::to_string(msg.action));
    root = parser.includeString("position",root,std::to_string(msg.pos));
    root = parser.includeString("data",root,std::to_string(msg.data));
    root = parser.includeString("Message",root,msg.notifaction);
    Json::FastWriter fastWriter;
    std::string output = fastWriter.write(root);
    return output;
}

