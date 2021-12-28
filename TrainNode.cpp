//==============================================================
// TrainNode class
//
// PURPOSE: Store one train car and the links between nodes. To
//          be used in a doubly-linked list.
//
// **The Node class could be nested inside the linked list class**
//
// METHODS: - constructor: public TrainNode(String t, int v)
//          - accessors: public String getCargoType()
//                       public int getValue()
//                       public TrainNode getNext()
//                       public TrainNode getPrev()
//          - mutators: public boolean setNext(TrainNode newNext)
//                      public boolean setPrev(TrainNode newPrev)
//==============================================================
#include "TrainNode.h"

//==========================================================
// TrainNode constructor
//
// PURPOSE: Create one TrainNode object with given type and value.
//
// PARAMETERS:
//   t  type of cargo
//   v  value of cargo (must be non-negative)
//==========================================================
TrainNode::TrainNode(string t, int v) {
    car = new TrainCar(t,v);
    next = nullptr;
    prev = nullptr;
}//end constructor

//==========================================================
// getType
//
// PURPOSE: Return the type of cargo.
//
// PARAMETERS:
//   None
//
// RETURNS:
//   String - the type of cargo
//==========================================================
string TrainNode::getType() {
    return car->getCargo();
}

//==========================================================
// getValue
//
// PURPOSE: Return the cargo value stored in this node.
//
// PARAMETERS:
//   None
//
// RETURNS:
//   int - the value of cargo in this car
//==========================================================
int TrainNode::getValue() {
    return car->getValue();
}

//==========================================================
// getNext
//
// PURPOSE: Return the reference to the next Node in a list of Nodes.
//
// PARAMETERS:
//   None
//
// RETURNS:
//   TrainNode - a reference/pointer to the next Node
//==========================================================
TrainNode *TrainNode::getNext() {
    return next;
}

//==========================================================
// getPrev
//
// PURPOSE: Return the reference to the previous Node in a list of Nodes.
//
// PARAMETERS:
//   None
//
// RETURNS:
//   TrainNode - a reference/pointer to the previous Node
//==========================================================
TrainNode *TrainNode::getPrev() {
    return prev;
}

//==========================================================
// setNext
//
// PURPOSE: Set the reference to the next Node in the list
//
// PARAMETERS:
//   newNext  the new reference
//
// RETURNS:
//   boolean - true if next was set successfully
//==========================================================
TrainNode *TrainNode::setNext(TrainNode *newNext) {
    return next = newNext;
}

//==========================================================
// setPrev
//
// PURPOSE: Set the reference to the previous Node in the list
//
// PARAMETERS:
//   newPrev  the new reference
//
// RETURNS:
//   boolean - true if next was set successfully
//==========================================================
TrainNode *TrainNode::setPrev(TrainNode *newPrev) {
    return prev = newPrev;
}
