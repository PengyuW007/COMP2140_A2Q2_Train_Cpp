#include "Train.h"

Train::Train() {
    first = new TrainNode("engine", 0);
    last = first;
}

Train::~Train() {
    cout << "No car nor engine on the train." << endl;
}

int Train::dropLast(int numToDrop) {
    int numDropped = 0;
    TrainNode *curr = last;

    if (first != nullptr) {
        while (curr != nullptr && strcmp(curr->getType().c_str(), "engine") != 0 && numDropped < numToDrop) {
            if (curr->getPrev() == nullptr) {
                first->getNext()->setPrev(nullptr);
                first = first->getNext();
            } else if (curr->getNext() == nullptr) {
                //drop tail
                last = curr->getPrev();
                if (last != nullptr) {
                    last->setNext(nullptr);
                }
            } else {
                //drop middle
                curr->getPrev()->setNext(curr->getNext());
                curr->getNext()->setPrev(curr->getPrev());
            }
            numDropped++;
            curr = curr->getPrev();
        }
    }
    return numDropped;
}

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

int Train::drop(string type, int numToDrop) {
    int numDropped = 0;
    TrainNode *curr = first;
    TrainNode *prev = nullptr;

    if (first != nullptr) {
        while (curr != nullptr && numDropped < numToDrop) {
            if (strcmp(curr->getType().c_str(), type.c_str()) == 0) {
                if (curr == first && first == last) {
                    //drop one car in one car train
                    first = nullptr;
                    last = nullptr;
                } else if (curr->getNext() == nullptr) {
                    //drop last
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
            } else {
                prev = curr;
            }
            curr = curr->getNext();
        }
    }
    return numDropped;
}//end drop

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
        TrainNode *prev = nullptr;
        TrainNode *curr = first;

        while (curr != nullptr) {
            //locate prev's location
            prev = curr;
            curr = curr->getNext();
        }

        prev->setNext(temp);
        temp->setPrev(last);
        last = temp;
    }
}//end addCar

int Train::countEngines() {
    int count = 0;
    TrainNode *curr = first;

    if (first != nullptr) {
        while (curr != nullptr && strcmp(curr->getType().c_str(), "engine") == 0) {
            count++;
            curr = curr->getNext();
        }
    }
    return count;
}//end countEngines

int Train::countCargoCars() {
    int count = 0;
    TrainNode *curr = first;
    if (first != nullptr) {
        while (curr != nullptr) {
            if (strcmp(curr->getType().c_str(), "engine") != 0) {
                count++;
            }
            curr = curr->getNext();
        }
    }
    return count;
}//end countCargoCars

int Train::sumValues() {
    int total = 0;
    TrainNode *curr = first;

    if (first != nullptr) {
        while (curr != nullptr) {
            total += curr->getValue();
            curr = curr->getNext();
        }
    }
    return total;
}//end sumValues

void Train::printTrainInfo() {
    cout << "Total number of engines: " << countEngines() << ", Total number of cargo cars: " << countCargoCars() <<
         ", Total value of cargo: $ " << sumValues() << endl;

    cout << "The cars on the train are: " << endl;
    TrainNode *curr = first;
    while (curr != nullptr) {
        cout << curr->getType();
        curr = curr->getNext();
        if (curr != nullptr) {
            cout << " - ";
        }
    }
    cout << endl;
}//end printTrainInfo

TrainNode *Train::getLast() {
    return last;
}

TrainNode *Train::getFirst() {
    return first;
}

