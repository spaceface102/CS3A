/****************************************************************
 * AUTHOR           : Osbaldo Gonzalez Jr.
 * ASSIGNMENT 06    : Doubly linked IntList
 * CLASS            : CS 3A
 * SECTION          : 71206
 * DUE DATE         : 7/16/2021
****************************************************************/

#include "doublyLinkedList.h"
#include <iostream>

DoublyLinkedList::DoublyLinkedList(void): head(nullptr), tail(nullptr) {}
//EOF

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& that)
{
    IntNode *current_that;  //PROC - track node from "that"

    if (that.head == nullptr)
        head = tail = nullptr;
    else
    {
        current_that = that.head;
        head = tail = new IntNode(current_that->data);

        current_that = current_that->next;
        while (current_that != nullptr)
        {
            tail->next = new IntNode(current_that->data);
            tail->next->prev = tail;
            tail = tail->next;
            current_that = current_that->next;
        }
    }
}
//EOF

DoublyLinkedList::~DoublyLinkedList(void)
{

}
//EOF

void DoublyLinkedList::display(bool forward) const
{
    IntNode *current;       //PROC - keep track of current node in list
    IntNode *terminating;   //PROC - the final node printed
    IntNode* (DoublyLinkedList::*direction)(IntNode*) const; //PROC -
                                                             //method pointer
    //use method pointer to not have any if
    //statements in while loop, and use the
    //same loop structure if forward or not.
    //also, I see how method pointers work, why not?
    if (forward)
    {
        current = head;
        terminating = tail;
        direction = &DoublyLinkedList::getNext; 
    }
    else
    {
        current = tail;
        terminating = head;
        direction = &DoublyLinkedList::getPrev;
    }

    while (current != terminating)
    {
        std::cout << current->data << " ";
        current = (this->*direction)(current);
    }
    if (terminating != nullptr)
        std::cout << terminating->data;
}
//EOF

IntListIterator DoublyLinkedList::begin(void)
{
    return IntListIterator(head);
}
//EOF

IntListIterator DoublyLinkedList::end(void)
{
    return IntListIterator(nullptr);
}
//EOF

int DoublyLinkedList::front(void) const
{
    return head->data;
}
//EOF

int DoublyLinkedList::back(void) const
{
    return tail->data;
}
//EOF

int DoublyLinkedList::length(void) const
{
    IntNode* current;   //PROC - the current node in the list
    int countingNodes;  //TRACK - summation of the number of nodes

    current = head;
    countingNodes = 0;
    while (current != nullptr)
    {
        countingNodes += 1;
        current = current->next;
    }
    return countingNodes;
}
//EOF

void DoublyLinkedList::push_front(int value)
{
    if (head == nullptr)
        head = tail = new IntNode(value);
    else
    {
        head->prev = new IntNode(value);
        head->prev->next = head;
        head = head->prev;
        head->prev = nullptr;
    }
}
//EOF

