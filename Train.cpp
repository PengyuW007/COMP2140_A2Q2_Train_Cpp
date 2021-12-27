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
        //empty train
        first = temp;
        last = first;
    } else if (strcmp(t.c_str(), "engine") == 0) {
        //add engines at front
        first->setPrev(temp);
        temp->setNext(first);
        first = temp;
    } else {
        //add cargo at end
        last->setNext(temp);
        temp->setPrev(last);
        last = temp;
    }

}//end addCar

int Train::dropFirst(int numToDrop) {
    int numDropped = 0;
    TrainNode *curr = first;
    TrainNode *prev = nullptr;

    if (first != nullptr) {
        while (curr != nullptr && strcmp(curr->getType().c_str(), "engine") == 0) {
            //remove except engine
            prev = curr;
            curr = curr->getNext();
        }

        while (curr != nullptr && numDropped < numToDrop) {
            if (prev == nullptr) {
                //drop first cargo's car
                first->getNext()->setPrev(nullptr);
                first = first->getNext();
            } else if (curr->getNext() == nullptr) {
                //drop last cargo's car
                last = curr->getPrev();
                if (last != nullptr) {
                    last->setNext(nullptr);
                }
            } else {
                //drop middle car
                curr->getPrev()->setNext(curr->getNext());
                curr->getNext()->setPrev(curr->getPrev());
            }
            numDropped++;
            curr = curr->getNext();
        }
    }
    return numDropped;
}//end dropFirst
