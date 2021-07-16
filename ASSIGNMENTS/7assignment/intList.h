#ifndef INTLIST_CLASS_H
#define INTLIST_CLASS_H

#include "intNode.h"
#include "intListIterator.h"

class IntList
{
private:
    IntNode* head;  //PROC - used to track the head of the linked list
    IntNode* tail;  //PROC - used to track the tail of the linked list

public:
    /*****************************
    ** CONSTRUCTOR & DESTRUCTOR **
    *****************************/
    IntList(void);
    ~IntList(void);
    IntList(const IntList& that);
    /**************
    ** ACCESSORS **
    **************/
    void display(void) const;
    IntListIterator begin(void);
    IntListIterator end(void);
    int front(void) const;
    int back(void) const;
    int length(void) const;
    int sum(void) const;
    void reverseDisplay() const;

    /*************
    ** MUTATORS **
    *************/
    void push_front(int value);
    void push_back(int value);
    void pop_front(void);
    void select_sort(void);
    void insert_sorted(int value);
    void remove_duplicates(void);
    IntList& operator=(const IntList& list);

private:
    /**************
    **  HELPERS  **
    **************/
    int RecursiveLength(const IntNode* node) const;
    int RecursiveSum(const IntNode* node) const;
    void RecursiveReverseDisplay(const IntNode* node) const;
    void ClearIntList(void);
    void RemoveNodesAfter(IntNode *node);
};

#endif //INTLIST_CLASS_H

/********************************************************************
 * IntListClass
 *  This class is a basic singly linked list. It manages a head and
 *  tail pointer to IntNode structs.
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
 *      Return:    none (std::cout output of the whole linked list)
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
 *  void push_back(int value);
 * 
 *      Mutator; Add a node to the tail of the list;
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
/********************************************************************
 *  void select_sort(void);
 * 
 *      Mutator; Sorts all the nodes of the singly linked list by
 *               asscending order.
 * ------------------------------------------------------------------
 *      Paramters: none
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/
/********************************************************************
 *  void insert_sorted(int value);
 * 
 *      Mutator; Add a node to the linked list such that the node
 *               before it is less than or equal to the new node,
 *               and the node after it is greater than or equal to it
 *               OR there is NO node after, since it's the largest
 *               value in the linked list.
 * ------------------------------------------------------------------
 *      Paramters: unsigned value //IN- value to be set to a new node
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/
/********************************************************************
 *  void remove_duplicates(void);
 * 
 *      Mutator; Makes sure that each value in the list only has
 *               one copy. After method is used, linked list
 *               is assured to not have any duplicate values, and
 *               the list might have "shrunk" depending of how many
 *               duplicate values where in the list.
 * ------------------------------------------------------------------
 *      Paramters: none
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/