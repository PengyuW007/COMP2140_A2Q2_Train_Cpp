#include "TrainCar.h"

TrainCar::TrainCar(string c,int value) {
    cargo = c;
    value = v;
}//end TrainCar constructor

TrainCar::~TrainCar(){
    cargo = null;
    value = 0;
}//end destructor

string TrainCar::getCargo() {
    return cargo;
}//end getCargo

int TrainCar::getValue() {
    return value;
}