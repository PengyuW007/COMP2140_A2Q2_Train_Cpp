#include "TrainNode.h"

TrainNode::TrainNode(string t, int v) {
    car = new TrainCar(t,v);
    next = nullptr;
    prev = nullptr;
}//end constructor

string TrainNode::getType() {
    return car->getCargo();
}

int TrainNode::getValue() {
    return car->getValue();
}

TrainNode *TrainNode::getNext() {
    return next;
}

TrainNode *TrainNode::getPrev() {
    return prev;
}

TrainNode *TrainNode::setNext(TrainNode *newNext) {
    return next = newNext;
}

TrainNode *TrainNode::setPrev(TrainNode *newPrev) {
    return prev = newPrev;
}
