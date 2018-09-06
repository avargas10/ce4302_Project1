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
    int getData();
    int getPos();

private:
    int _id;
    int generate(int,int);
};


#endif //CE4302_PROJECT1_RANDOMGENERATOR_H
