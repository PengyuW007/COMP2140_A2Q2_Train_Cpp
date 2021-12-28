//==============================================================
// Train class
//
// PURPOSE: A linked list to store the cars on a train, where the list is doubly-linked.
//
// METHODS: - constructor: public Train()
//          - public void addCar(String t, int v) - add a car to the train
//          - public int dropFirst(int numToDrop) - delete first numToDrop cargo cars
//          - public int dropLast(int numToDrop) - delete last numToDrop cargo cars
//          - public int dropCars(String type, int numToDrop) - delete first numToDrop cars with given type
//          - public int countEngines() - count number of engines in train
//          - public int countCargoCars() - count number of cargo cars in train
//          - public int sumValues() - get total value of all cargo
//          - public void printTrainInfo() - print the cars in the train, and total value
//==============================================================
#include "Train.h"

//==========================================================
// Train constructor
//
// PURPOSE: Create a new train, with a single engine.
//
// PARAMETERS:
//   None
//==========================================================
Train::Train() {
    first = new TrainNode("engine", 0);
    last = first;
}

Train::~Train() {
    cout << "No car nor engine on the train." << endl;
}

//==========================================================
// dropLast
//
// PURPOSE: Delete the last numToDrop cargo cars.
//
// PARAMETERS:
//   numToDrop - the number of cars to delete from the train
//
// RETURN:
//   int - the number of cars dropped (equal to numToDrop if
//         at least that many cargo cars existed)
//==========================================================
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
}//end dropLast

//==========================================================
// dropFirst
//
// PURPOSE: Delete the first numToDrop cargo cars.
//
// PARAMETERS:
//   numToDrop - the number of cars to delete from the train
//
// RETURN:
//   int - the number of cars dropped (equal to numToDrop if
//         at least that many cargo cars existed)
//==========================================================
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

//==========================================================
// drop
//
// PURPOSE: Delete the first numToDrop cars with the given type.
//
// PARAMETERS:
//   type - the type of car to drop
//   numToDrop - the number of cars to delete from the train
//
// RETURN:
//   int - the number of cars dropped (equal to numToDrop if
//         at least that many cargo cars of the given type existed)
//==========================================================
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

//==========================================================
// addCar
//
// PURPOSE: Add a car with given type and value to the train.
//          Add engines at front. Add cargo at end.
//
// PARAMETERS:
//   t - the type of cargo
//   v - value of the cargo
//==========================================================
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

//==========================================================
// countEngines
//
// PURPOSE: Return the number of engines on the train.
//
// PARAMETERS:
//   none
//
// RETURN:
//   int - the number of engines on the train
//==========================================================
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

//==========================================================
// countCargoCars
//
// PURPOSE: Return the number of non-engines on the train.
//
// PARAMETERS:
//   none
//
// RETURN:
//   int - the number of non-engines on the train
//==========================================================
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

//==========================================================
// sumValues
//
// PURPOSE: Calculate and return the total value of cargo on the train.
//
// PARAMETERS:
//   none
//
// RETURN:
//   int - the total value of the cargo on the train
//==========================================================
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

//==========================================================
// printTrainInfo
//
// PURPOSE: Print information about the train (summary of
//          number of cars, total cargo value, list of all
//          cars on train (type only).
//
// PARAMETERS:
//   none
//==========================================================
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

