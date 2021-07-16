#ifndef INTLIST_ITERATOR_CLASS_H
#define INTLIST_ITERATOR_CLASS_H

#include "intList.h"

class IntListIterator
{
private:
    IntNode *current;

public:
    /*****************************
    ** CONSTRUCTOR & DESTRUCTOR **
    *****************************/
    IntListIterator(void);
    IntListIterator(IntNode *ptr);

    /*************
    ** MUTATORS **
    *************/
    //I would probably declare as operator++() as const, 
    //but following assignment specifications
    IntListIterator operator++(void);

    /**************
    ** ACCESSORS **
    **************/
    //I would probably declare as operator*() as const, 
    //but following assignment specifications
    int operator*(void);
    bool operator==(const IntListIterator& right) const;
    bool operator!=(const IntListIterator& right) const;
};

#endif