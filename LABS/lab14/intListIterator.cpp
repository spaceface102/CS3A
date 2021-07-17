/****************************************************************
 * AUTHOR           : Osbaldo Gonzalez Jr.
 * ASSIGNMENT 06    : IntList Recursive && IntListIterator
 * CLASS            : CS 3A
 * SECTION          : 71206
 * DUE DATE         : 7/15/2021
****************************************************************/

#include "intListIterator.h"

/****************************************************************
 * 
 *  Method Constructor: Class IntListIterator
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
IntListIterator::IntListIterator(void) : current(nullptr) {}
//EOF

/****************************************************************
 * 
 *  Method Constructor: Class IntListIterator
 *  //CONSTRUCTOR
 * --------------------------------------------------------------
 *  Set current to a passed in address
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The address should be a valid address of a node
 *      inside the IntListClass.
 *      Must make an object, or call the constructor with no
 *      arguments.
 * 
 *  POST-CONDITIONS
 *      As long as the node that is being pointed to is
 *      valid, derefrencing it should be fine.
****************************************************************/
IntListIterator::IntListIterator(IntNode* ptr) : current(ptr) {}
//EOF

/****************************************************************
 * 
 *  Method operator*: Class IntListIterator
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
int IntListIterator::operator*(void)
{
    return current->data;
}
//EOF

/****************************************************************
 * 
 *  Method operator*: Class IntListIterator
 *  //PUBLIC
 * --------------------------------------------------------------
 *  Return an IntListIterator object, and modifies the calling
 *  object so that it's private current attribute is set to 
 *  current->next.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Current should be a valid, non NULL, pointer to a node.
 *  POST-CONDITIONS
 *      The new current after is allowed to be NULL assuming
 *      its the tail node.
****************************************************************/
IntListIterator IntListIterator::operator++(void)
{
    current = current->next;
    return *this;
}
//EOF

/****************************************************************
 * 
 *  Method operator*: Class IntListIterator
 *  //PUBLIC
 * --------------------------------------------------------------
 *  Return an IntListIterator object, and modifies the calling
 *  object so that it's private current attribute is set to 
 *  current->prev.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Current should be a valid, non NULL, pointer to a node.
 *  POST-CONDITIONS
 *      The new current after is allowed to be NULL assuming
 *      its the head node.
****************************************************************/
IntListIterator IntListIterator::operator--(void)
{
    current = current->prev;
    return *this;
}

/****************************************************************
 * 
 *  Method operator==: Class IntListIterator
 *  //PUBLIC
 * --------------------------------------------------------------
 *  Check if two IntListIterator objects are pointing to the
 *  same node.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Both object must have been initialized.
 *  POST-CONDITIONS
 *      The nodes that are being pointed at do not change.
 *      Only check to see if the address are the same.
****************************************************************/
bool IntListIterator::operator==(const IntListIterator& right) const
{
    return (current == right.current);
}
//EOF

/****************************************************************
 * 
 *  Method operator==: Class IntListIterator
 *  //PUBLIC
 * --------------------------------------------------------------
 *  Check if two IntListIterator objects are NOT pointing to the
 *  same node.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Both object must have been initialized.
 *  POST-CONDITIONS
 *      The nodes that are being pointed at do not change.
 *      Only check to see if the address are NOT the same.
****************************************************************/
bool IntListIterator::operator!=(const IntListIterator& right) const
{
    return !(*this == right);
}
//EOF