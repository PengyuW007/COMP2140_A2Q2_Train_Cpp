#ifndef TRAINCPP_TRAINCAR_H
#define TRAINCPP_TRAINCAR_H

#pragma once

#include <string>
#include <iostream>

using namespace std;

class TrainCar {
private:
    string cargo;//type of cargo
    int value;//value of the cargo

public:
    TrainCar(string c,int v);

    ~TrainCar();

    string getCargo();

    int getValue();

    string toString();
};


#endif //A2Q2TRAINCPP_TRAINCAR_H
