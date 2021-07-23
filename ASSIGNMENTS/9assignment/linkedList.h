#ifndef LINKED_LIST_CLASS_H
#define LINKED_LIST_CLASS_H

/****************************************************************
 * AUTHOR           : Osbaldo Gonzalez Jr.
 * ASSIGNMENT 06    : LinkedList Template
 * CLASS            : CS 3A
 * SECTION          : 71206
 * DUE DATE         : 7/22/2021
****************************************************************/

#include "node.h"
#include "listEmpty.h"
#include "iterator.h"
#include <iostream>

//Definitions
template<typename E>
class LinkedList
{
private:
    Node<E> *head;  //PROC - used to track the head of the linked list
    Node<E> *tail;  //PROC - used to track the tail of the linked list

public:
    /*****************************
    ** CONSTRUCTOR & DESTRUCTOR **
    *****************************/
    LinkedList(void);
    ~LinkedList(void);
    LinkedList(const LinkedList& that);
    LinkedList& operator=(const LinkedList& source);

    /**************
    ** ACCESSORS **
    **************/
    void display(void) const;
    const E& front(void) const throw(ListEmpty);
    const E& back(void) const throw(ListEmpty);
    Iterator<E> begin(void);
    Iterator<E> end(void);
    int length(void) const;
    const E& sum(void) const;
    bool isEmpty(void);

    /*************
    ** MUTATORS **
    *************/
    void push_front(const E& value);
    void push_back(const E& value);
    void pop_front(void) throw(ListEmpty);
    void clear(void);
    void select_sort(void);
    void insert_sorted(const E& value);
    void remove_duplicates(void);

private:
    /**************
    **  HELPERS  **
    **************/
    int RecursiveLength(const Node<E> *node) const; 
    const E& RecursiveSum(const Node<E> *node) const;
    void RemoveNodesAfter(Node<E> *node);
};

#endif //LINKED_LIST_CLASS_H

/****************************************************************
 * 
 *  Method Constructor: Class LinkedList
 *  //DEFAULT CONSTRUCTOR
 *  //TEMPLATE
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
template<typename E>
LinkedList<E>::LinkedList(void) : head(nullptr), tail(nullptr) {}
//EOF

/****************************************************************
 * 
 *  Method Destructor: Class LinkedList
 *  //DESTRUCTOR
 *  //TEMPLATE
 * --------------------------------------------------------------
 *  Free up the heap allocated memory allocated with the LinkedList.
 *  "head" and "tail" are set to nullptr.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      LinkedList object must go out of scope, or delete must be
 *      called on an LinkedList pointer object.
 * 
 *  POST-CONDITIONS
 *      Any memory related with the list are no longer accessible.
****************************************************************/
template<typename E>
LinkedList<E>::~LinkedList(void)
{
    clear();
}
//EOF

/****************************************************************
 * 
 *  Method Constructor: Class LinkedList
 *  //COPY CONSTRUCTOR
 *  //TEMPLATE
 * --------------------------------------------------------------
 * This is the overloaded copy constructor. It will copy all
 * the nodes of the passed in linked list, in the exact same 
 * order. The new object does not share any memory with the
 * passed in object.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The passed in LinkedList object can be in any stage, no
 *      node list, one node, list or more.
 * 
 *  POST-CONDITIONS
 *      If the passed in list is empty (no nodes), the new
 *      object's head and tail are both set to NULL. Else
 *      will traverse through the list, and make new nodes.
 *      All new memory is allocated on the heap, so deleting
 *      or modifying this new object will not have any affect
 *      on the object being used to make a copy out of.
****************************************************************/
template<typename E>
LinkedList<E>::LinkedList(const LinkedList<E>& that)
{
    Node<E> *current_that;  //PROC - track node from "that"

    if (that.head == nullptr)   //empty LinkedList passed in
        head = tail = nullptr;
    else    //"that" has at least one node
    {
        current_that = that.head;
        head = tail = new Node<E>(current_that->data);  //init list
        
        //if that has only has one node, next is NULL
        //and will not run the while loop
        current_that = current_that->next;
        while (current_that != NULL)
        {   //don't use push_back to avoid checks if list is empty
            tail->next = new Node<E>(current_that->data);
            tail = tail->next;
            current_that = current_that->next;
        }
    }
}
//EOF

/****************************************************************
 * 
 *  Method operator=: Class LinkedList
 *  //PUBLIC
 *  //TEMPLATE
 * --------------------------------------------------------------
 *  Overload of the "=" operator. Do a deep copy of the passed
 *  in object. 
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Both the calling list and the passed in list can be
 *      empty, with no nodes, or any amount of nodes.
 *  POST-CONDITIONS
 *      The length of the calling object's linked list is
 *      assured to be changed if the passed in "that" linked
 *      list a different size. The only time the size will
 *      not change is the two linked list are of the exact same
 *      length. The calling object's memory associated with
 *      the linked list is automatically cleaned up or expanded
 *      according to the the size of "that".
****************************************************************/
template<typename E>
LinkedList<E>& LinkedList<E>::operator=(const LinkedList<E> &that)
{
    Node<E> *current_that;  //PROC - track node from "that"
    Node<E> *current;       //PROC - track node from calling obj.

    //avoid case were same object is on both
    //sides of the "=" operator.
    if (this == &that)
        return *this;       //just return the calling object
    
    if (that.head == nullptr)   //passed in list is empty
    {
        clear(); //clear out the current object.
        return *this;
    }

    //current object has no nodes or one node
    //and "that" also at least has one node.
    if (head == tail)
    {
        current_that = that.head;
        if (head == nullptr) //no nodes
            head = tail = new Node<E>(current_that->data);
        else //already has one node
            head->data = current_that->data;

        //get the rest of the nodes filled up
        current_that = current_that->next;
        while (current_that != nullptr)
        {
            tail->next = new Node<E>(current_that->data);
            tail = tail->next;
            current_that = current_that->next;
        }
        return *this;
    }

    //not self referential, passed in LinkedList has at least a node
    //and the current object has least has two nodes.
    current = head;
    current_that = that.head;
    while (current->next != tail && current_that != that.tail)
    {
        current->data = current_that->data;
        current = current->next;
        current_that = current_that->next;
    }


    if (current_that == that.tail)
    {   
        //current->next is not necessarily pointing to the tail node
        //but it may. The crucial thing is that we only have one more
        //node left in "that". Set current's data attribute,
        //and remove every node after current, and set current as
        //the new tail for the object.
        current->data = current_that->data;
        RemoveNodesAfter(current);  //this func sets the new tail.
    }
    else 
    {
        //must be that current->next == tail && current_that != that.tail
        //remember, in order to exit the while loop, current->next or 
        //current_that must point to their respective tails... since
        //current_that is not the tail, then current->next must be!
        //update the node before tail

        current->data = current_that->data;
        current_that = current_that->next;
        //after previous, current_that might now point to that.tail

        //remember, current->next is tail; just modifying tail
        tail->data = current_that->data; 
        current_that = current_that->next;
        //after previous, current_that might now point to NULL

        //add more nodes while "that" has more nodes to offer.
        while (current_that != nullptr)
        {
            tail->next = new Node<E>(current_that->data);
            tail = tail->next;
            current_that = current_that->next;
        }
    }

    return *this;
}
//EOF

/****************************************************************
 * 
 *  Method display: Class LinkedList
 *  //PUBLIC
 *  //TEMPLATE
 * --------------------------------------------------------------
 *  Display all the values related to the list.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The list can be filled or empty.
 *  POST-CONDITIONS
 *      The ouput will be sent to std::cout; all the output is
 *      on one line.
****************************************************************/
template<typename E>
void LinkedList<E>::display(void) const
{
    Node<E> *current;   //PROC - current node in the linked list

    current = head;
    while (current != tail)
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
 *  Method front: Class LinkedList
 *  //PUBLIC
 *  //EXCEPTION
 * --------------------------------------------------------------
 * Return the value of associated with the head of the list.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must call on a list of at least length 1 (at least one
 *      node).
 *  POST-CONDITIONS
 *      Assuming the calling object at least has one active node
 *      a copy of the value at the head will be returned. Else
 *      if list is empty, exception ListEmpty() is throw.
****************************************************************/
template<typename E>
const E& LinkedList<E>::front(void) const throw(ListEmpty)
{
    if (head == nullptr)
        throw ListEmpty("Error in: LinkedList<E>::front\n"
                        "Can't get first element from EMPTY list");
    return head->data;
}
//EOF

/****************************************************************
 * 
 *  Method front: Class LinkedList
 *  //PUBLIC
 *  //EXCEPTION
 * --------------------------------------------------------------
 * Return the value of associated with the tail of the list.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must call on a list of at least length 1 (at least one
 *      node).
 *  POST-CONDITIONS
 *      Assuming the calling object at least has one active node
 *      a copy of the value at the head will be returned. Else
 *      if list is empty, exception ListEmpty() is throw.
****************************************************************/
template<typename E>
const E& LinkedList<E>::back(void) const throw(ListEmpty)
{
    if (head == nullptr)
        throw ListEmpty("Error in: LinkedList<E>::back\n"
                        "Can't get last element from EMPTY list");
    return tail->data;
}
//EOF

/****************************************************************
 * 
 *  Method begin: Class LinkedList
 *  //PUBLIC
 *  //TEMPLATE
 * --------------------------------------------------------------
 * Return an Iterator object that holds the a pointer
 * to the node head is currently point to.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The calling list can be of any size, and even empty.
 *  POST-CONDITIONS
 *      If the size of the list is 0; aka there are no nodes in
 *      the list, Iterator will be pointing to NULL. If
 *      you try to dereference that, you are likely to get
 *      an error.
****************************************************************/
template<typename E>
Iterator<E> LinkedList<E>::begin(void)
    {return Iterator<E>(head);}
//EOF

/****************************************************************
 * 
 *  Method end: Class LinkedList
 *  //PUBLIC
 *  //TEMPLATE
 * --------------------------------------------------------------
 * Return an Iterator object that holds the a pointer
 * to the node head is currently point to.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The calling list can be of any size, and even empty.
 *  POST-CONDITIONS
 *      If the size of the list is 0; aka there are no nodes in
 *      the list, Iterator will be pointing to NULL. If
 *      you try to dereference that, you are likely to get
 *      an error.
****************************************************************/
template<typename E>
Iterator<E> LinkedList<E>::end(void)
    {return Iterator<E>(tail);}
//EOF

/****************************************************************
 * 
 *  Method length: Class LinkedList
 *  //PUBLIC
 * --------------------------------------------------------------
 * Return the number of nodes in the singly linked list.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The object can have a linked list of any size; it
 *      can be empty
 *  POST-CONDITIONS
 *      If the linked list is empty, will return 0, else
 *      each node will be counted as 1.
****************************************************************/
template<typename E>
int LinkedList<E>::length(void) const
{
    return RecursiveLength(head);
}
//EOF

/****************************************************************
 * 
 *  Method RecursiveLength: Class LinkedList
 *  //PRIVATE
 * --------------------------------------------------------------
 * Recursively traverse through the linked list, incrementing
 * the return value by one until reaching/hitting NULL.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The passed in the Node<E>* should be a valid pointer
 *      to an already existing node.
 *  POST-CONDITIONS
 *      If the linked list is empty, will return 0, else
 *      each node will be counted as 1.
****************************************************************/
template<typename E>
int LinkedList<E>::RecursiveLength(const Node<E> *node) const
{
    if (node == nullptr)
        return 0;
    
    return 1 + RecursiveLength(node->next);
}
//EOF

/****************************************************************
 * 
 *  Method sum: Class LinkedList
 *  //PUBLIC
 * --------------------------------------------------------------
 *  Return the sum of all the nodes in the linked list. Note:
 *  The default constructor of the type being uses is treated
 *  as "0".
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The linked list can be empty, and any other size.
 * 
 *      The type used for the template should be able to overload
 *      the addition operator (operator+ must be defined for
 *      the used linked list type).
 *  POST-CONDITIONS
 *      The linked list is not modified. Will always traverse
 *      through the whole linked list.
 *      Whatever implentation of the used type for the linked
 *      list, will always add (only once at the end) the
 *      default constructor.
****************************************************************/
template<typename E>
const E& LinkedList<E>::sum(void) const
{
    return RecursiveSum(head);
}

/****************************************************************
 * 
 *  Method RecursiveSum: Class LinkedList
 *  //PRIVATE
 * --------------------------------------------------------------
 * Recursively traverse through the linked list, incrementing
 * the return value by the node's data value.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The passed in the Node<E>* should be a valid pointer
 *      to an already existing node. Or the node can be null,
 *      in which case just return default constructor.
 *  POST-CONDITIONS
 *      The function will not modify any node, just get the
 *      value at the node.
 *      If passed in "node" points to NULL, will return default
 *      constructor for template type.
****************************************************************/
template<typename E>
const E& LinkedList<E>::RecursiveSum(const Node<E> *node) const
{
    if (node == nullptr)
        return E();
    
    return node->data + RecursiveSum(node->next);
}

/****************************************************************
 * 
 *  Method clear: Class LinkedList
 *  //PUBLIC
 *  //TEMPLATE
 * --------------------------------------------------------------
 *  Free all the memory related with the object's linked list.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The object can be of any size. No nodes, or many nodes.
 *  POST-CONDITIONS
 *      The head and tail pointers are set to NULL.
****************************************************************/
template<typename E>
void LinkedList<E>::clear(void)
{
    Node<E> *future;   //PROC - Store node address for next loop
    Node<E> *current;  //PROC - Delete the current node
    
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
 *  Method RemoveNodesAfter: Class LinkedList
 *  //PRIVATE
 *  //TEMPLATE
 * --------------------------------------------------------------
 *  Free all the nodes after the node passed in. Set the node
 *  passed in as the new tail.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The passed in node must be part of the object's 
 *      list. Conforming with that condition, the passed in
 *      node pointer can point to anything inside the list, 
 *      including the head, tail, and nullptr.
 *      The calling object's list can have any number
 *      of nodes.
 *  POST-CONDITIONS
 *      A new tail is set as the current node. All
 *      the nodes after the passed in node are deleted.
 *      In the case where the object's list is just one
 *      node big, or the node pointer passed in is NULL
 *      then nothing is done.
****************************************************************/
template<typename E>
void LinkedList<E>::RemoveNodesAfter(Node<E> *node)
{
    Node<E> *future;    //PROC - store the next node
    Node<E> *current;   //PROC - track the current node

    //checking if node == tail also ensures if the
    //current list is only one node, and if head
    //is passed in, won't do anything.
    if (node == nullptr || node == tail) //don't do anything.
        return;

    future = node->next;    //avoid deleteing passed in node.
    while (future != tail)
    {
        current = future;
        future = future->next;
        delete current;
    }

    delete tail;
    tail = node;
    tail->next = nullptr;
}
//EOF