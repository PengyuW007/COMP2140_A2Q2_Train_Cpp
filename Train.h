#ifndef TRAINCPP_TRAIN_H
#define TRAINCPP_TRAIN_H

#pragma once

#include "TrainNode.h"
#include <string>

using namespace std;

class Train {
private:
    //TrainCar *car;
    TrainNode *first;
    TrainNode *last;

public:
    Train();

    ~Train();

    void addCar(string t,int v);

    void printInfo();//Print one line displaying the number of cars
    //in the train and the total value of the cargo. On a second line, print the train from front
    //to back, listing the type of cargo in each car (the list of cars may wrap to multiple lines).
    void dropLast(int num);

    void dropFirst(int num);

    void drop(string type, int num);

    void printCarInfo();
};

#endif //TRAINCPP_TRAIN_H
