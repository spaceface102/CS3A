#ifndef INTLIST_H
#define INTLIST_H

struct IntNode
{
    int data;
    IntNode* next;
    IntNode(int data) : data(data), next(nullptr) {}
};

class IntList
{
private:
    IntNode* head;
    IntNode* tail;

public:
    /*****************************
    ** CONSTRUCTOR & DESTRUCTOR **
    *****************************/
    IntList(void);
    ~IntList(void);

    /**************
    ** ACCESSORS **
    **************/
    void display(void) const;

    /*************
    ** MUTATORS **
    *************/
    void push_front(int value);
    void pop_front(void);
};

#endif //INTLIST_H

/********************************************************************
 * IntListClass
 *  This class is a basic intlist. It manages a head and tail pointer
 *  to IntNodes.
********************************************************************/

/*****************************
** CONSTRUCTOR & DESTRUCTOR **
*****************************/

/********************************************************************
 * IntList(void);
 * 
 *      Constructor; Initialize head and tail to nullptr
 * ------------------------------------------------------------------
 *      Paramters: none
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/
/********************************************************************
 * ~IntVector(void);
 * 
 *      Destructor; Free all the dynamically allocated memory
 *                  associated with the object.
 * ------------------------------------------------------------------
 *      Paramters: none
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/

/**************
** ACCESSORS **
**************/

/********************************************************************
 * display(void);
 * 
 *      Accessor; Displays all the values in every single node
 *                of the IntList object
 * ------------------------------------------------------------------
 *      Paramters: none
 * ------------------------------------------------------------------
 *      Return:    none (std::cout output)
********************************************************************/

/*************
** MUTATORS **
*************/

/********************************************************************
 *  void push_front(int value);
 * 
 *      Mutator; Add an element to the head of the list.
 * ------------------------------------------------------------------
 *      Paramters: unsigned value //IN - value to be set
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/
/********************************************************************
 *  void pop_front(void);
 * 
 *      Mutator; Deletes current node pointed by head, and set
 *               new head to the the next node in the front of
 *               the IntList.
 * ------------------------------------------------------------------
 *      Paramters: none
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/