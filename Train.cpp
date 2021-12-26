#include "Train.h"

Train::Train() {
    first = new TrainNode("engine", 0);
}

Train::~Train() {
    cout << "No car nor engine on the train." << endl;
}

void Train::addCar(string t, int v) {
    TrainNode *temp = new TrainNode(t, v);

    if (first == nullptr) {
        first = temp;
        last = first;
    } else if (strcmp(t.c_str(), "engine") == 0) {
        //add engines at front
        first->setPrev(temp);
        temp->setNext(first);
        first = temp;
    } else {
        //add at end
        last->setNext(temp);
        temp->setPrev(last);
        last = temp;
    }
}
