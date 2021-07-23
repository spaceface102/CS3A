#ifndef ITERATOR_TEMPLATE_CLASS_H
#define ITERATOR_TEMPLATE_CLASS_H

/****************************************************************
 * AUTHOR           : Osbaldo Gonzalez Jr.
 * ASSIGNMENT 06    : LinkedList Template
 * CLASS            : CS 3A
 * SECTION          : 71206
 * DUE DATE         : 7/22/2021
****************************************************************/

#include "node.h"

template <typename E>
class Iterator
{
private:
    Node<E>* current;   //PROC - node poiter from a IntList object.

public:
    /*****************************
    ** CONSTRUCTOR & DESTRUCTOR **
    *****************************/
    Iterator(void);
    Iterator(Node<E> *ptr);

    /*************
    ** MUTATORS **
    *************/
    Iterator operator++(void);

    /**************
    ** ACCESSORS **
    **************/
    //I would probably make another version that
    //is declared as a const method, and I would
    //make this return an int&
    const E& operator*(void);
    bool operator==(const Iterator<E>& right) const;
    bool operator!=(const Iterator<E>& right) const;
};

/****************************************************************
 * 
 *  Method Constructor: Class Iterator
 *  //DEFAULT CONSTRUCTOR
 * --------------------------------------------------------------
 *  Set current to NULL
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must make an object, or call the constructor with no
 *      arguments.
 * 
 *  POST-CONDITIONS
 *      Dereferencing this point will cause a segfault.
****************************************************************/
template <typename E>
Iterator<E>::Iterator(void) : current(nullptr) {}
//EOF

/****************************************************************
 * 
 *  Method Constructor: Class Iterator
 *  //CONSTRUCTOR
 * --------------------------------------------------------------
 *  Set current to a passed in address
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The address should be a valid address of a node
 *      inside the class LinkedList.
 *      Must make an object, or call the constructor with no
 *      arguments.
 * 
 *  POST-CONDITIONS
 *      As long as the node that is being pointed to is
 *      valid, derefrencing it should be fine.
 * 
 *      No validation on the pointer. Be careful using non
 *      valid pointers.
****************************************************************/
template <typename E>
Iterator<E>::Iterator(Node<E>* ptr) : current(ptr) {}
//EOF

/****************************************************************
 * 
 *  Method operator*: Class Iterator
 *  //PUBLIC
 * --------------------------------------------------------------
 *  Return the data associated with the node that current
 *  points to.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Should probably make sure that the node that object
 *      pointing to is valid.
 * 
 *  POST-CONDITIONS
 *      As long as the node that is being pointed to is
 *      valid, derefrencing it should be fine.
****************************************************************/
template <typename E>
const E& Iterator<E>::operator*(void)
    {return current->data;}
//EOF

/****************************************************************
 * 
 *  Method operator*: Class Iterator
 *  //PUBLIC
 * --------------------------------------------------------------
 *  Return an Iterator object, and modifies the calling
 *  object so that it's private current attribute is set to 
 *  current->next.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Current should be a valid, non NULL, pointer to a node.
 *  POST-CONDITIONS
 *      The new current after is allowed to be NULL assuming
 *      its the tail node.
****************************************************************/
template <typename E>
Iterator<E> Iterator<E>::operator++(void)
{
    current = current->next;
    return *this;
}
//EOF

/****************************************************************
 * 
 *  Method operator==: Class Iterator
 *  //PUBLIC
 * --------------------------------------------------------------
 *  Check if two Iterator objects are pointing to the
 *  same node.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Both object must have been initialized.
 *  POST-CONDITIONS
 *      The nodes that are being pointed at do not change.
 *      Only check to see if the address are the same.
****************************************************************/
template <typename E>
bool Iterator<E>::operator==(const Iterator<E>& right) const
    {return (current == right.current);}
//EOF

/****************************************************************
 * 
 *  Method operator==: Class Iterator
 *  //PUBLIC
 * --------------------------------------------------------------
 *  Check if two Iterator objects are NOT pointing to the
 *  same node.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Both object must have been initialized.
 *  POST-CONDITIONS
 *      The nodes that are being pointed at do not change.
 *      Only check to see if the address are NOT the same.
****************************************************************/
template <typename E>
bool Iterator<E>::operator!=(const Iterator<E>& right) const
    {return !(*this == right);}
//EOF

#endif //ITERATOR_TEMPLATE_CLASS_H