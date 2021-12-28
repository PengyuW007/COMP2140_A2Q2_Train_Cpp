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
        TrainNode *prev = NULL;
        TrainNode *curr = first;

        while (curr != NULL) {
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

    if (first != NULL) {
        while (curr != NULL && strcmp(curr->getType().c_str(), "engine") == 0) {
            count++;
            curr = curr->getNext();
        }
    }
    return count;
}//end countEngines

int Train::countCargoCars() {
    int count = 0;
    TrainNode *curr = first;
    if (first != NULL) {
        while(curr!=NULL){
            if(strcmp(curr->getType().c_str(),"engine")!=0){
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

    if(first!=NULL){
        while(curr!=NULL){
            total+=curr->getValue();
            curr = curr->getNext();
        }
    }
    return total;
}//end sumValues

void Train::printTrainInfo() {
    cout << "Total number of engines: " << countEngines() <<", Total number of cargo cars: "<<countCargoCars()<<
    ", Total value of cargo: $ "<<sumValues()<<endl;

    cout<<"The cars on the train are: "<<endl;
    TrainNode* curr = first;
    while(curr!=NULL){
        cout<<curr->getType();
        curr = curr->getNext();
        if(curr!=NULL){
            cout<<" - ";
        }
    }
    cout<<endl;
}//end printTrainInfo

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

TrainNode *Train::getLast() {
    return last;
}

TrainNode *Train::getFirst() {
    return first;
}

