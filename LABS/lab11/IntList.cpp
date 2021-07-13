/****************************************************************
 * AUTHOR           : Osbaldo Gonzalez Jr.
 * ASSIGNMENT 05    : IntList
 * CLASS            : CS 3A
 * SECTION          : 71206
 * DUE DATE         : 7/9/2021
****************************************************************/
#include "IntList.h"
#include <iostream>

/****************************************************************
 * 
 *  Method Constructor: Class IntList
 *  //DEFAULT CONSTRUCTOR
 * --------------------------------------------------------------
 *  Set both the head and tail pointer to nullptr
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must make an object, or call the constructor with no
 *      arguments.
 * 
 *  POST-CONDITIONS
 *      The object does not have any space to store anything
 *      yet. It is an empty list.
****************************************************************/
IntList::IntList(void) : head(nullptr), tail(nullptr) {}
//EOF

/****************************************************************
 * 
 *  Method Destructor: Class IntList
 *  //DESTRUCTOR
 * --------------------------------------------------------------
 *  Free up the heap allocated memory allocated with the IntList.
 *  "head" and "tail" are set to nullptr.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      IntList object must go out of scope, or delete must be
 *      called on an IntList pointer object.
 * 
 *  POST-CONDITIONS
 *      Any memory related with the list is no longer accessible.
****************************************************************/
IntList::~IntList(void)
{
    IntNode *future;   //PROC - Store node address for next loop
    IntNode *current;  //PROC - Delete the current node
    
    future = head;
    while (future != nullptr)
    {
        current = future;
        future = future->next;
        delete current;
    }

    head = nullptr;
    tail = nullptr;
}
//EOF

/****************************************************************
 * 
 *  Method display: Class IntList
 *  //PUBLIC
 * --------------------------------------------------------------
 *  Display all the values related to the list.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The list can be filled or empty.
 *  POST-CONDITIONS
 *      The ouput will be sent to std::cout; all the output is
 *      on one line.
****************************************************************/
void IntList::display(void) const
{
    IntNode *current;   //PROC - current node in the linked list

    current = head;
    while (current != nullptr && current != tail)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    if (tail != nullptr)
        std::cout << tail->data;
}
//EOF

/****************************************************************
 * 
 *  Method push_front: Class IntList
 *  //PUBLIC
 * --------------------------------------------------------------
 *  Adds a new node in front of the head node. 
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The list can be filled or empty.
 *  POST-CONDITIONS
 *      If the list is empty, then both the head node and tail
 *      node are set to the new added node. Else, the a new head
 *      node is added.
****************************************************************/
void IntList::push_front(int value)
{
    IntNode *pastHead;  //PROC - store previous head node pointer

    if (head == nullptr) //its a new list
        head = tail = new IntNode(value);
    else //list already has elements
    {
        pastHead = head;
        head = new IntNode(value);
        head->next = pastHead;
    }
}
//EOF

/****************************************************************
 * 
 *  Method pop_front: Class IntList
 *  //PUBLIC
 * --------------------------------------------------------------
 *  Deletes the head node.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The list can be filled or empty.
 *  POST-CONDITIONS
 *      If the list is empty, then nothing is done. Else
 *      current head is deleted, and the next node is made
 *      the new head.
****************************************************************/
void IntList::pop_front(void)
{   
    IntNode *pastHead;  //PROC - store the current head node that
                        //will be deleted.

    if (head == nullptr)
        return; //do nothing
    
    pastHead = head;
    head = head->next;
    delete pastHead;
}
//EOF