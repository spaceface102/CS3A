/****************************************************************
 * AUTHOR           : Osbaldo Gonzalez Jr.
 * ASSIGNMENT 06    : Doubly linked List
 * CLASS            : CS 3A
 * SECTION          : 71206
 * DUE DATE         : 7/16/2021
****************************************************************/

#include "doublyLinkedList.h"
#include <iostream>

/****************************************************************
 * 
 *  Method Constructor: Class DoublyLinkedList
 *  //DEFAULT CONSTRUCTOR
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
DoublyLinkedList::DoublyLinkedList(void): head(nullptr), tail(nullptr) {}
//EOF

/****************************************************************
 * 
 *  Method Constructor: Class DoublyLinkedList
 *  //COPY CONSTRUCTOR
 * --------------------------------------------------------------
 * This is the overloaded copy constructor. It will copy all
 * the nodes of the passed in linked list, in the exact same 
 * order. The new object does not share any memory with the
 * passed in object.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The passed in DoublyLinkedList object can be in any stage, no
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
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& that)
{
    IntNode *current_that;  //PROC - track node from "that"

    if (that.head == nullptr)
        head = tail = nullptr;
    else
    {
        current_that = that.head;
        head = tail = new IntNode(current_that->data);

        current_that = current_that->next;
        while (current_that != nullptr)
        {
            tail->next = new IntNode(current_that->data);
            tail->next->prev = tail;
            tail = tail->next;
            current_that = current_that->next;
        }
    }
}
//EOF

/****************************************************************
 * 
 *  Method Destructor: Class DoublyLinkedList
 *  //DESTRUCTOR
 * --------------------------------------------------------------
 *  Free up the heap allocated memory allocated with the 
 *  DoublyLinkedList. "head" and "tail" are set to nullptr.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      DoublyLinkedList object must go out of scope, or delete must be
 *      called on an DoublyLinkedList pointer object.
 * 
 *  POST-CONDITIONS
 *      Any memory related with the list are no longer accessible.
****************************************************************/
DoublyLinkedList::~DoublyLinkedList(void)
{
    ClearDoublyLinkedList();
}
//EOF

/****************************************************************
 * 
 *  Method display: Class DoublyLinkedList
 *  //PUBLIC
 * --------------------------------------------------------------
 *  Display all the values related to the list. If forward
 *  = true, will display from head to tail, else if forward
 *  = false, will display from tail to head.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The list can be filled or empty.
 *  POST-CONDITIONS
 *      The ouput will be sent to std::cout; all the output is
 *      on one line. No new line.
****************************************************************/
void DoublyLinkedList::display(bool forward) const
{
    IntNode *current;       //PROC - keep track of current node in list
    IntNode *terminating;   //PROC - the final node printed
    IntNode* (DoublyLinkedList::*direction)(IntNode*) const; //PROC -
                                                             //method pointer
    //use method pointer to not have any if
    //statements in while loop, and use the
    //same loop structure if forward or not.
    //also, I see how method pointers work, why not?
    if (forward)
    {
        current = head;
        terminating = tail;
        direction = &DoublyLinkedList::getNext; 
    }
    else
    {
        current = tail;
        terminating = head;
        direction = &DoublyLinkedList::getPrev;
    }

    while (current != terminating)
    {
        std::cout << current->data << " ";
        current = (this->*direction)(current);
    }
    if (terminating != nullptr)
        std::cout << terminating->data;
}
//EOF

/****************************************************************
 * 
 *  Method begin: Class DoublyLinkedList
 *  //PUBLIC
 * --------------------------------------------------------------
 * Return an IntListIterator object that holds the a pointer
 * to the node head is currently point to.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The calling list can be of any size, and even empty.
 *  POST-CONDITIONS
 *      If the size of the list is 0; aka there are no nodes in
 *      the list, IntListIterator will be pointing to NULL. If
 *      you try to dereference that, you are likely to get
 *      an error.
****************************************************************/
IntListIterator DoublyLinkedList::begin(void)
{
    return IntListIterator(head);
}
//EOF

/****************************************************************
 * 
 *  Method end: Class DoublyLinkedList
 *  //PUBLIC
 * --------------------------------------------------------------
 * Return an IntListIterator object that holds the a pointer to
 * NULL.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The calling list can be of any size, and even empty.
 *  POST-CONDITIONS
 *      IntListIterator will be pointing to NULL. If
 *      you try to dereference that, you are likely to get
 *      an error (probably a seg fault).
****************************************************************/
IntListIterator DoublyLinkedList::end(void)
{
    return IntListIterator(nullptr);
}
//EOF

/****************************************************************
 * 
 *  Method front: Class DoublyLinkedList
 *  //PUBLIC
 * --------------------------------------------------------------
 * Return the value of associated with the head of the list.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must call on a list of at least length 1 (at least one
 *      node).
 *  POST-CONDITIONS
 *      Assuming the calling object at least has one active node
 *      a copy of the value at the head will be returned. 
****************************************************************/
int DoublyLinkedList::front(void) const
{
    return head->data;
}
//EOF

/****************************************************************
 * 
 *  Method back: Class DoublyLinkedList
 *  //PUBLIC
 * --------------------------------------------------------------
 * Return the value of associated with the tail of the list.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must call on a list of at least length 1 (at least one
 *      node).
 *  POST-CONDITIONS
 *      Assuming the calling object at least has one active node
 *      a copy of the value at the tail will be returned. 
****************************************************************/
int DoublyLinkedList::back(void) const
{
    return tail->data;
}
//EOF

/****************************************************************
 * 
 *  Method length: Class DoublyLinkedList
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
int DoublyLinkedList::length(void) const
{
    IntNode* current;   //PROC - the current node in the list
    int countingNodes;  //TRACK - summation of the number of nodes

    current = head;
    countingNodes = 0;
    while (current != nullptr)
    {
        countingNodes += 1;
        current = current->next;
    }
    return countingNodes;
}
//EOF

/****************************************************************
 * 
 *  Method push_front: Class DoublyLinkedList
 *  //PUBLIC
 * --------------------------------------------------------------
 *  Adds a new node in front of the head node. 
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The list can be filled or empty.
 *  POST-CONDITIONS
 *      If the list is empty, then both the head node and tail
 *      node are set to the new added node. Else, the a new head
 *      node is added.
****************************************************************/
void DoublyLinkedList::push_front(int value)
{
    if (head == nullptr)    //empty list
        head = tail = new IntNode(value);
    else
    {
        head->prev = new IntNode(value);
        head->prev->next = head;
        head = head->prev;
    }
}
//EOF

/****************************************************************
 * 
 *  Method push_back: Class DoublyLinkedList
 *  //PUBLIC
 * --------------------------------------------------------------
 *  Adds a new node to the end of the list.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The list can be filled or empty.
 *  POST-CONDITIONS
 *      If the list is empty, head and tail will point to the
 *      same new node. Else, the tail before calling the method
 *      will now point to a new node.
****************************************************************/
void DoublyLinkedList::push_back(int value)
{
    if (head == nullptr)    //empty list
        head = tail = new IntNode(value);
    else
    {
        tail->next = new IntNode(value);
        tail->next->prev = tail;
        tail = tail->next;
    }
}
//EOF

/****************************************************************
 * 
 *  Method pop_front: Class DoublyLinkedList
 *  //PUBLIC
 * --------------------------------------------------------------
 *  Deletes the front node.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The list can be filled or empty.
 *  POST-CONDITIONS
 *      If the list is empty, then nothing is done. Else
 *      current head is deleted, and the next node is made
 *      the new head.
****************************************************************/
void DoublyLinkedList::pop_front(void)
{
    //no node or single node. (nothing will happen
    //if we use delete on NULL, delete checks for that)
    if (head == tail)
    {
        delete head;
        head = tail = nullptr;
    }
    else
    {
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
    }
}
//EOF

/****************************************************************
 * 
 *  Method pop_back: Class DoublyLinkedList
 *  //PUBLIC
 * --------------------------------------------------------------
 *  Deletes the end node.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The list can be filled or empty.
 *  POST-CONDITIONS
 *      If the list is empty, then nothing is done. Else
 *      current tail is deleted, and the previous node is made
 *      the new tail.
****************************************************************/
void DoublyLinkedList::pop_back(void)
{
    //no node or single node. (nothing will happen
    //if we use delete on NULL, delete checks for that)
    if (head == tail)
    {
        delete tail;
        head = tail = nullptr;
    }
    else
    {
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }
}
//EOF

/****************************************************************
 * 
 *  Method select_sort: Class DoublyLinkedList
 *  //PUBLIC
 * --------------------------------------------------------------
 *  Sort the list in accending order. Algoirthim used is
 *  selection sort.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The list can be filled or empty.
 *  POST-CONDITIONS
 *      If list has at least two nodes head will have the
 *      smallest value, and tail will have the largest value.
 *      If a new list, or a list with only one node, do nothing.
****************************************************************/
void DoublyLinkedList::select_sort(void)
{
    IntNode *subHead;   //PROC - head of the sub array
    IntNode *current;   //PROC - the current node we are inspecting
    IntNode *minNode;   //PROC - keep track of the minimum value node
    int swap;           //PROC - used to swap data

    subHead = head;
    while (subHead != tail)
    {
        minNode = subHead;
        current = subHead->next;
        while (current != nullptr)
        {
            if (current->data < minNode->data)
                minNode = current;
            current = current->next;
        }
        swap = subHead->data;
        subHead->data = minNode->data;
        minNode->data = swap;

        subHead = subHead->next;
    }
}
//EOF

/****************************************************************
 * 
 *  Method insert_sorted: Class DoublyLinkedList
 *  //PUBLIC
 * --------------------------------------------------------------
 *  Will insert value sorted.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The list can be filled or empty. The list must have
 *      already been sorted, else will not not insert the 
 *      value in a sorted fashion.
 *  POST-CONDITIONS
 *      If the value is greater than or equal to tail, new tail
 *      is set. If value is less than or equal to head, new head
 *      is set. Else, node is just plugged into the list.
****************************************************************/
void DoublyLinkedList::insert_sorted(int value)
{
    IntNode **current;          //PROC - track the current node indirectly
    IntNode *previousOldNode;   //PROC - store the prev node of next node

    if (head == nullptr)    //list doesn't have any nodes yet.
    {
        //one single node is automatically sorted
        head = tail = new IntNode(value);
        return;
    }

    if (value >= tail->data)
    {
        tail->next = new IntNode(value);
        tail->next->prev = tail;
        tail = tail->next;
        return;
    }

    //For sure not touching the tail node due to prev if block
    current = &head;
    while (value > (*current)->data)
        current = &((*current)->next);
    
    //*current node's data is greater or equal to value
    //just always put the new node as the previous node
    //remember, other than for head, current is pointing
    //to the next pointer of a node.
    previousOldNode = (*current)->prev;
    (*current)->prev = new IntNode(value);
    (*current)->prev->next = *current;
    (*current)->prev->prev = previousOldNode;
    *current = (*current)->prev;
    //use of indirect pointer to avoid special case for
    //chaning head.
}
//EOF

/****************************************************************
 * 
 *  Method remove_duplicates: Class DoublyLinkedList
 *  //PUBLIC
 * --------------------------------------------------------------
 *  Will delete every instance of the passed in the value from
 *  the list
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The list can be filled or empty. 
 *  POST-CONDITIONS
 *      The head is assured to change if the the node that head
 *      points to is the value being looked for. Note, head may change
 *      multiple times throughout the method.
 *      Tail can also change, but assuming it is a candinate for
 *      removal, will only be removed/changed once.
 *      Assuming the whole list is equal to the value passed in
 *      the finalized list will result in an empty list.
****************************************************************/
bool DoublyLinkedList::remove(int value)
{
    IntNode **current;   //PROC - track the current node indirectly
    IntNode *removeNode; //PROC - temp while rewiring linked list
    bool removedValue;   //PROC - return value, true if a value is removed

    removedValue = false;
    current = &head;
    while (*current != tail)
    {
        if ((*current)->data == value)
        {
            //at most most removeNode = tail->prev
            removedValue = true;
            removeNode = *current;
            (*current)->next->prev = (*current)->prev;
            *current = (*current)->next;
            delete removeNode;
        }
        else
            current = &((*current)->next);
    }

    if (tail == head)
    {
        if (tail != nullptr && tail->data == value)
        {   //single node with specified value
            removedValue = true;
            delete tail;
            head = tail = nullptr;
        }
    }
    else if (tail->data == value) //linked list at least has two nodes.
    {
        removedValue = true;
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }

    return removedValue;
}
//EOF

/****************************************************************
 * 
 *  Method operator=: Class DoublyLinkedList
 *  //PUBLIC
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
DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& that)
{
    IntNode *current_that;  //PROC - track node from "that"
    IntNode *current;       //PROC - track node from calling obj.
    IntNode *newTail;       //PROC - in the event calling obj.'s list is bigger

    //avoid case were same object is on both
    //sides of the "=" operator.
    if (this == &that)
        return *this;       //just return the calling object
    
    //passed in list is empty
    if (that.head == nullptr)
    {
        ClearDoublyLinkedList();
        return *this;
    }

    //current object has no nodes or one node
    //and "that" also at least has one node
    if (head == tail)
    {
        current_that = that.head;
        if (head == nullptr)
            head = tail = new IntNode(current_that->data);
        else
            head->data = current_that->data;
        
        current_that = current_that->next;
        while (current_that != nullptr)
        {
            tail->next = new IntNode(current_that->data);
            tail->next->prev = tail;
            tail = tail->next;
            current_that = current_that->next;
        }
        return *this;
    }

    //not self referential, passed in DoublyLinkedList has at least a node
    //and the current object has least has two nodes.
    current = head;
    current_that = that.head;
    while (current != nullptr && current_that != nullptr)
    {
        current->data = current_that->data;
        current = current->next;
        current_that = current_that->next;
    }

    //each list must have NOT been the same size.
    if (current != current_that)
    {
        //calling object's list is smaller, need to expand
        if (current == nullptr)
        {
            while (current_that != nullptr)
            {
                tail->next = new IntNode(current_that->data);
                tail->next->prev = tail;
                tail = tail->next;
                current_that = current_that->next;
            }
        }
        else //current_that must be nullptr
        {
            //since we are assured by now the calling object has at
            //least two nodes, and the passed in linked list "that"
            //has at least one node, current at most is eq. to tail.
            //current->prev would therefore be head at most.
            newTail = current->prev;
            while (current != tail)
            {
                current = current->next;
                delete current->prev;
            }
            delete tail;
            tail = newTail;
            tail->next = nullptr;
        }
    }
    //else both list were of the exact same size.

    return *this;
}
//EOF

/****************************************************************
 * 
 *  Method ClearDoublyLinkedList: Class DoublyLinkedList
 *  //PRIVATE
 * --------------------------------------------------------------
 *  Return the address of the next node relative to passed in
 *  node
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The passed in node address must be valid
 *  POST-CONDITIONS
 *      The passed in node will not be modified.
 *      If node address is invalid, unexpected results.
****************************************************************/
IntNode* DoublyLinkedList::getNext(IntNode* node) const
{
    return node->next;
}
//EOF

/****************************************************************
 * 
 *  Method ClearDoublyLinkedList: Class DoublyLinkedList
 *  //PRIVATE
 * --------------------------------------------------------------
 *  Return the address of the previous node relative to passed in
 *  node
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The passed in node address must be valid
 *  POST-CONDITIONS
 *      The passed in node will not be modified.
 *      If node address is invalid, unexpected results.
****************************************************************/
IntNode* DoublyLinkedList::getPrev(IntNode* node) const
{
    return node->prev;
}
//EOF

/****************************************************************
 * 
 *  Method ClearDoublyLinkedList: Class DoublyLinkedList
 *  //PRIVATE
 * --------------------------------------------------------------
 *  Free all the memory related with the object's linked list.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The object can be of any size. No nodes, or many nodes.
 *  POST-CONDITIONS
 *      The head and tail pointers are set to NULL.
****************************************************************/
void DoublyLinkedList::ClearDoublyLinkedList(void)
{
    while (head != tail)
    {
        head = head->next;
        delete head->prev;
    }

    delete tail;
    head = tail = nullptr;
}