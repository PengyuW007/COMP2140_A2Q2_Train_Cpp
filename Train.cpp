#include "Train.h"

Train::Train() {
    car = new TrainCar("Engine",0);
}

Train::~Train(){
    cout<<"No car nor engine on the train."<<endl;
}
