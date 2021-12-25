#ifndef TRAINCPP_TRAIN_H
#define TRAINCPP_TRAIN_H

#pragma once

#include "TrainCar.h"
#include <string>

class Train {
private:
    TrainCar *car;

public:
    Train();

    ~Train();

    void printInfo();//Print one line displaying the number of cars
    //in the train and the total value of the cargo. On a second line, print the train from front
    //to back, listing the type of cargo in each car (the list of cars may wrap to multiple lines).
    void dropLast(int num);

    void dropFirst(int num);

    void drop(string type, int num);
};

#endif //TRAINCPP_TRAIN_H
