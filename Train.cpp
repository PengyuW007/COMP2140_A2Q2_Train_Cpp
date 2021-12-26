#include "Train.h"

Train::Train() {
    first = new TrainNode("engine", 0);
}

Train::~Train() {
    cout << "No car nor engine on the train." << endl;
}
