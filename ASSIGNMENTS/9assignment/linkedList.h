#ifndef LINKED_LIST_CLASS_H
#define LINKED_LIST_CLASS_H

#include "listEmpty.h"

//Declerations
template<typename E>
struct Node;
template<typename E>
class LinkedList;
template<typename E>
class Iterator;


//Definitions
template<typename E>
struct Node
{
    E data;
    Node *next;
    Node(E data) : data(data), next(nullptr) {}
};

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
    Iterator begin(void);
    Iterator end(void);
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
    E RecursiveSum(const Node<E>* node) const;
    void RemoveNodesAfter(Node<E>* node);
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