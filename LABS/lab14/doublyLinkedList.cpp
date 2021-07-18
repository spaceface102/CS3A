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
    ClearDoublyLinkedList();
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
    if (head == nullptr)    //empty list
        head = tail = new IntNode(value);
    else
    {
        head->prev = new IntNode(value);
        head->prev->next = head;
        head = head->prev;
    }
}
//EOF

void DoublyLinkedList::push_back(int value)
{
    if (head == nullptr)    //empty list
        head = tail = new IntNode(value);
    else
    {
        tail->next = new IntNode(value);
        tail->next->prev = tail;
        tail = tail->next;
    }
}
//EOF

void DoublyLinkedList::pop_front(void)
{
    //no node or single node. (nothing will happen
    //if we use delete on NULL, delete checks for that)
    if (head == tail)
    {
        delete head;
        head = tail = nullptr;
    }
    else
    {
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
    }
}
//EOF

void DoublyLinkedList::pop_back(void)
{
    //no node or single node. (nothing will happen
    //if we use delete on NULL, delete checks for that)
    if (head == tail)
    {
        delete tail;
        head = tail = nullptr;
    }
    else
    {
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }
}
//EOF

void DoublyLinkedList::select_sort(void)
{
    IntNode *subHead;   //PROC - head of the sub array
    IntNode *current;   //PROC - the current node we are inspecting
    IntNode *minNode;   //PROC - keep track of the minimum value node
    int swap;           //PROC - used to swap data

    subHead = head;
    while (subHead != tail)
    {
        minNode = subHead;
        current = subHead->next;
        while (current != nullptr)
        {
            if (current->data < minNode->data)
                minNode = current;
            current = current->next;
        }
        swap = subHead->data;
        subHead->data = minNode->data;
        minNode->data = swap;

        subHead = subHead->next;
    }
}
//EOF

void DoublyLinkedList::insert_sorted(int value)
{
    IntNode **current;          //PROC - track the current node indirectly
    IntNode *previousOldNode;   //PROC - store the prev node of next node

    if (head == nullptr)    //list doesn't have any nodes yet.
    {
        //one single node is automatically sorted
        head = tail = new IntNode(value);
        return;
    }

    if (value >= tail->data)
    {
        tail->next = new IntNode(value);
        tail->next->prev = tail;
        tail = tail->next;
        return;
    }

    //For sure not touching the tail node due to prev if block
    current = &head;
    while (value > (*current)->data)
        current = &((*current)->next);
    
    //*current node's data is greater or equal to value
    //just always put the new node as the previous node
    //remember, other than for head, current is pointing
    //to the next pointer of a node.
    previousOldNode = (*current)->prev;
    (*current)->prev = new IntNode(value);
    (*current)->prev->next = *current;
    (*current)->prev->prev = previousOldNode;
    *current = (*current)->prev;
    //use of indirect pointer to avoid special case for
    //chaning head.
}
//EOF

bool DoublyLinkedList::remove(int value)
{
    IntNode **current;   //PROC - track the current node indirectly
    IntNode *removeNode; //PROC - temp while rewiring linked list
    bool removedValue;   //PROC - return value, true if a value is removed

    removedValue = false;
    current = &head;
    while (*current != tail)
    {
        if ((*current)->data == value)
        {
            //at most most removeNode = tail->prev
            removedValue = true;
            removeNode = *current;
            (*current)->next->prev = (*current)->prev;
            *current = (*current)->next;
            delete removeNode;
        }
        else
            current = &((*current)->next);
    }

    if (tail == head)
    {
        if (tail != nullptr && tail->data == value)
        {   //single node with specified value
            removedValue = true;
            delete tail;
            head = tail = nullptr;
        }
    }
    else if (tail->data == value) //linked list at least has two nodes.
    {
        removedValue = true;
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }

    return removedValue;
}
//EOF

DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& that)
{
    IntNode *current_that;  //PROC - track node from "that"
    IntNode *current;       //PROC - track node from calling obj.
    IntNode *newTail;       //PROC - in the event calling obj.'s list is bigger

    //avoid case were same object is on both
    //sides of the "=" operator.
    if (this == &that)
        return *this;       //just return the calling object
    
    //passed in list is empty
    if (that.head == nullptr)
    {
        ClearDoublyLinkedList();
        return *this;
    }

    //current object has no nodes or one node
    //and "that" also at least has one node
    if (head == tail)
    {
        current_that = that.head;
        if (head == nullptr)
            head = tail = new IntNode(current_that->data);
        else
            head->data = current_that->data;
        
        current_that = current_that->next;
        while (current_that != nullptr)
        {
            tail->next = new IntNode(current_that->data);
            tail->next->prev = tail;
            tail = tail->next;
            current_that = current_that->next;
        }
        return *this;
    }

    //not self referential, passed in IntList has at least a node
    //and the current object has least has two nodes.
    current = head;
    current_that = that.head;
    while (current != nullptr && current_that != nullptr)
    {
        current->data = current_that->data;
        current = current->next;
        current_that = current_that->next;
    }

    //each list must have NOT been the same size.
    if (current != current_that)
    {
        //calling object's list is smaller, need to expand
        if (current == nullptr)
        {
            while (current_that != nullptr)
            {
                tail->next = new IntNode(current_that->data);
                tail->next->prev = tail;
                tail = tail->next;
                current_that = current_that->next;
            }
        }
        else //current_that must be nullptr
        {
            //since we are assured by now the calling object has at
            //least two nodes, and the passed in linked list "that"
            //has at least one node, current at most is eq. to tail.
            //current->prev would therefore be head at most.
            newTail = current->prev;
            while (current != tail)
            {
                current = current->next;
                delete current->prev;
            }
            delete tail;
            tail = newTail;
            tail->next = nullptr;
        }
    }
    //else both list were of the exact same size.

    return *this;
}
//EOF

IntNode* DoublyLinkedList::getNext(IntNode* node) const
{
    return node->next;
}
//EOF

IntNode* DoublyLinkedList::getPrev(IntNode* node) const
{
    return node->prev;
}
//EOF

void DoublyLinkedList::ClearDoublyLinkedList(void)
{
    while (head != tail)
    {
        head = head->next;
        delete head->prev;
    }

    delete tail;
    head = tail = nullptr;
}