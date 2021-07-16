#ifndef INTLIST_ITERATOR_CLASS_H
#define INTLIST_ITERATOR_CLASS_H

#include "intNode.h"
class IntListIterator
{
private:
    IntNode* current;

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

#endif