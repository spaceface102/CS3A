#ifndef INTLIST_ITERATOR_CLASS_H
#define INTLIST_ITERATOR_CLASS_H

#include "intNode.h"
class IntListIterator
{
private:
    IntNode* current;   //PROC - node poiter from a IntList object.

public:
    /*****************************
    ** CONSTRUCTOR & DESTRUCTOR **
    *****************************/
    IntListIterator(void);
    IntListIterator(IntNode *ptr);

    /*************
    ** MUTATORS **
    *************/
    IntListIterator operator++(void);
    IntListIterator operator--(void);
    
    /**************
    ** ACCESSORS **
    **************/
    //I would probably make another version that
    //is declared as a const method, and I would
    //make this return an int&
    int operator*(void);
    bool operator==(const IntListIterator& right) const;
    bool operator!=(const IntListIterator& right) const;
};

#endif //INTLIST_ITERATOR_CLASS_H

/********************************************************************
 * IntListIterator Class
 *  Manages a pointer from an IntClass object. Used to have looped
 *  exectution without needed to have some sort of explicit method
 *  related with IntClass.
********************************************************************/

/*****************************
** CONSTRUCTOR & DESTRUCTOR **
*****************************/
/********************************************************************
 * IntListIterator(void);
 * 
 *      Constructor; Initialize current to NULL
 * ------------------------------------------------------------------
 *      Paramters: none
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/
/********************************************************************
 * IntListIterator(IntNode *ptr);
 * 
 *      Constructor; Initialize current to passed in ptr.
 * ------------------------------------------------------------------
 *      Paramters: IntNode *ptr //PROC - used to init current
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/

/*************
** MUTATORS **
*************/
/********************************************************************
 * IntListIterator operator++(void);
 * 
 *      Mutator; set current ot current->next and return *this
 * ------------------------------------------------------------------
 *      Paramters: none
 * ------------------------------------------------------------------
 *      Return:    IntListIterator (*this)
********************************************************************/

/**************
** ACCESSORS **
**************/
/********************************************************************
 * int operator*(void);
 * 
 *      Accessor; derefence current pointer node's data attribute
 * ------------------------------------------------------------------
 *      Paramters: none
 * ------------------------------------------------------------------
 *      Return:    int (current->data)
********************************************************************/
/********************************************************************
 * bool operator==(const IntListIterator& right) const;
 * 
 *      Accessor; Compare the address that each current private
 *                attribute holds. If equal return true
 * ------------------------------------------------------------------
 *      Paramters: const IntListIterator& right //PROC - object to
 *                                               compare with
 * ------------------------------------------------------------------
 *      Return:    bool
********************************************************************/
/********************************************************************
 * bool operator!=(const IntListIterator& right) const;
 * 
 *      Accessor; Compare the address that each current private
 *                attribute holds. If equal return false
 * ------------------------------------------------------------------
 *      Paramters: const IntListIterator& right //PROC - object to
 *                                               compare with
 * ------------------------------------------------------------------
 *      Return:    bool
********************************************************************/