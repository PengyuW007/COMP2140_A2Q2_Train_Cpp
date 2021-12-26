#include "TrainCar.h"


TrainCar::TrainCar(string c, int v) {
    cargo = c;
    value = v;
}//end TrainCar constructor

TrainCar::~TrainCar() {
    cargo = nullptr;
    value = 0;
}//end destructor

string TrainCar::getCargo() {
    return cargo;
}//end getCargo

int TrainCar::getValue() {
    return value;
}//end getValue

string TrainCar::toString() {
    return cargo + ", " + to_string(value);
}