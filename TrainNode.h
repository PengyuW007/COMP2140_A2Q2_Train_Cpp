#ifndef A2Q2TRAINCPP_TRAINNODE_H
#define A2Q2TRAINCPP_TRAINNODE_H

#include "TrainCar.h"
#include <string>

using namespace std;
class TrainNode {
private:
    TrainCar *car;
    TrainNode *next;
    TrainNode *prev;
public:
    TrainNode(string t, int v);//constructor

    string getType();

    int getValue();

    TrainNode *getNext();

    TrainNode *getPrev();

    TrainNode *setNext(TrainNode *newNext);

    TrainNode *setPrev(TrainNode *newPrev);

};


#endif //A2Q2TRAINCPP_TRAINNODE_H
