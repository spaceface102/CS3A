#ifndef CURRENT_LINKED_LIST_HANDLER_CLASS_H
#define CURRENT_LINKED_LIST_HANDLER_CLASS_H

#include "../linkedList.h"
#include "../myVector.h"
#include <iostream>

class CurrentLinkedList_Handler
{
    //NOTE: in the inhereted class, you should include:
    //A Vector of Linked Lists, which stores all the
    //lists associated
    //An "activeList" field which keeps track of
    //which LinkedList (in the vector) we are using
public:
    //return the size of the vector storing
    //all the linked lists
    virtual unsigned numAvaliableLists(void) const = 0;
    //push_back a copy of the current linked
    //list to the end of the list.
    virtual void makeCopyOfActiveList(void) = 0;
    //change the activeList private field to
    //the passed in listNumber if valid.
    virtual void setActiveList(unsigned listNumber) = 0;
    //return the index of the active list in the Vector
    //of lists, often used to change ActiveList
    virtual unsigned getActiveListNumber(void) const = 0;
    //sets the active list as the next list in the vector
    //will wrap around if need be
    virtual void setNextListAsActive(void) = 0;

    //Purely wrappers around existing LinkedList Functions
    virtual void sort(void) = 0;
    virtual void removeDuplicates(void) = 0;
    virtual void popFront(std::ostream& error_output = std::cerr) = 0;
    virtual void pushBack(const char* text) = 0;
    virtual void insertSorted(const char* text) = 0;
    virtual void display(std::ostream& out) = 0;
    virtual void insert(const char* atNode, const char* value) = 0;
    virtual void display(std::ostream& out, const char* start,
                         const char* end) = 0; //select portion
};

/********************************************************************
 * CurrentLinkedList_Handler
 *  An abstract class used to define an interface for the current
 *  linked list, depending on which radioButton on QTCreator is
 *  being used. Intended to be publicly inhereted.
********************************************************************/
#endif //CURRENT_LINKED_LIST_HANDLER_CLASS_H