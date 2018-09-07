//
// Created by kakaroto on 02/09/18.
//

#ifndef CE4302_PROJECT1_RANDOMGENERATOR_H
#define CE4302_PROJECT1_RANDOMGENERATOR_H


class randomGenerator {
public:
    randomGenerator(int);
    randomGenerator();
    int getTask();
    int getData(int);
    int getPos(int);

private:
    int _id;
    int generate(int,int,int);
};


#endif //CE4302_PROJECT1_RANDOMGENERATOR_H
