#ifndef DOUBLY_LINKED_LIST_CLASS_H
#define DOUBLY_LINKED_LIST_CLASS_H

#include "intNode.h"
#include "intListIterator.h"

class DoublyLinkedList
{
private:
    IntNode* head;
    IntNode* tail;

public:
    /*****************************
    ** CONSTRUCTOR & DESTRUCTOR **
    *****************************/
    DoublyLinkedList(void);
    DoublyLinkedList(const DoublyLinkedList &D);
    ~DoublyLinkedList(void);

    /**************
    ** ACCESSORS **
    **************/
    void display(bool forward = true) const;
    IntListIterator begin(void);
    IntListIterator end(void);
    int front(void) const;
    int back(void) const;
    int length(void) const;
    /*************
    ** MUTATORS **
    *************/
    DoublyLinkedList& operator=(const DoublyLinkedList &D);
    void push_front(int value);
    void pop_front(void);
    void push_back(int value);
    void pop_back(void);
    void select_sort();
    void insert_sorted(int value);
    bool remove(int value);

private:
    /**************
    **  HELPERS  **
    **************/
    IntNode* getPrev(IntNode* node) const;
    IntNode* getNext(IntNode* node) const;
};

#endif //DOUBLY_LINKED_LIST_CLASS_H