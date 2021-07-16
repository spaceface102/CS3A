/****************************************************************
 * AUTHOR           : Osbaldo Gonzalez Jr.
 * ASSIGNMENT 06    : IntList
 * CLASS            : CS 3A
 * SECTION          : 71206
 * DUE DATE         : 7/12/2021
****************************************************************/
#include "intList.h"
#include <iostream>

/****************************************************************
 * 
 *  Method Constructor: Class IntList
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
IntList::IntList(void) : head(nullptr), tail(nullptr) {}
//EOF

/****************************************************************
 * 
 *  Method Destructor: Class IntList
 *  //DESTRUCTOR
 * --------------------------------------------------------------
 *  Free up the heap allocated memory allocated with the IntList.
 *  "head" and "tail" are set to nullptr.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      IntList object must go out of scope, or delete must be
 *      called on an IntList pointer object.
 * 
 *  POST-CONDITIONS
 *      Any memory related with the list are no longer accessible.
****************************************************************/
IntList::~IntList(void)
{
    ClearIntList();
}
//EOF

IntList::IntList(const IntList& that)
{
    IntNode *current_that;  //PROC - track node from "that"

    if (that.head == nullptr)   //empty IntList passed in
        head = tail = nullptr;
    else    //"that" has at least one node
    {
        current_that = that.head;
        head = tail = new IntNode(current_that->data);  //init list
        
        //if that has only has one node, next is NULL
        //and will not run the while loop
        current_that = current_that->next;
        while (current_that != NULL)
        {
            tail->next = new IntNode(current_that->data);
            tail = tail->next;
            current_that = current_that->next;
        }
    }
}
//EOF

/****************************************************************
 * 
 *  Method display: Class IntList
 *  //PUBLIC
 * --------------------------------------------------------------
 *  Display all the values related to the list.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The list can be filled or empty.
 *  POST-CONDITIONS
 *      The ouput will be sent to std::cout; all the output is
 *      on one line.
****************************************************************/
void IntList::display(void) const
{
    IntNode *current;   //PROC - current node in the linked list

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

IntListIterator IntList::begin(void)
{
    return IntListIterator(head);
}
//EOF

IntListIterator IntList::end(void)
{
    return IntListIterator(nullptr);
}
//EOF

int IntList::front(void) const
{
    return head->data;
}
//EOF

int IntList::back(void) const
{
    return tail->data;
}
//EOF

int IntList::length(void) const
{
    return RecursiveLength(head);
}
//EOF

int IntList::RecursiveLength(const IntNode* node) const
{
    if (node == nullptr)
        return 0;
    
    return 1 + RecursiveLength(node->next);
}
//EOF

int IntList::sum(void) const
{
    if (head == nullptr)    //empty list, return sum as -1
        return -1;
    return RecursiveSum(head);
}
//EOF

int IntList::RecursiveSum(const IntNode* node) const
{
    if (node == tail)
        return tail->data;
    
    return node->data + RecursiveSum(node->next);
}
//EOF

void IntList::reverseDisplay(void) const
{
    if (head == nullptr)    //list with no nodes, do nothing
        return;
    RecursiveReverseDisplay(head);
}
//EOF

void IntList::RecursiveReverseDisplay(const IntNode* node) const
{
    if (node == tail)
    {
        std::cout << node->data; //make sure dont have trailing " "
        return;
    }
    
    RecursiveReverseDisplay(node->next);
    std::cout << node->data << " ";
}
//EOF

/****************************************************************
 * 
 *  Method push_front: Class IntList
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
void IntList::push_front(int value)
{
    IntNode *pastHead;  //PROC - store previous head node pointer

    if (head == nullptr) //its a new list
        head = tail = new IntNode(value);
    else //list already has elements
    {
        pastHead = head;
        head = new IntNode(value);
        head->next = pastHead;
    }
}
//EOF

/****************************************************************
 * 
 *  Method push_back: Class IntList
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
void IntList::push_back(int value)
{
    if (head == nullptr)    //empty list
        head = tail = new IntNode(value);
    else
    {
        tail->next = new IntNode(value);
        tail = tail->next;
    }
}
//EOF

/****************************************************************
 * 
 *  Method pop_front: Class IntList
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
void IntList::pop_front(void)
{   
    IntNode *pastHead;  //PROC - store the current head node that
                        //will be deleted.

    if (head == nullptr)
        return; //do nothing
    
    pastHead = head;
    head = head->next;
    delete pastHead;
}
//EOF

/****************************************************************
 * 
 *  Method select_sort: Class IntList
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
void IntList::select_sort(void)
{
    IntNode *subHead;   //PROC - head of the sub array
    IntNode *current;   //PROC - the current node we are inspecting
    IntNode *minNode;   //PROC - keep track of the minimum value node
    int temp;           //PROC - used to swap data

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
        temp = subHead->data;
        subHead->data = minNode->data;
        minNode->data = temp;

        subHead = subHead->next;
    }
}
//EOF

/****************************************************************
 * 
 *  Method insert_sorted: Class IntList
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
void IntList::insert_sorted(int value)
{
    IntNode **current;  //PROC - indirect_pointer to a node.
    IntNode *aNode;     //PROC - pointer to the new inserted node.

    //avoid having to traverse through the whole
    //list. List is sorted, therefore tail will have
    //the biggest value: if tail->data is less than
    //or equal to value, define a new tail with the
    //push_back() method.
    if (value >= tail->data)
    {
        push_back(value);
        return; //done, we are leaving early!
    }

    //value is assured to not be placed after tail.
    //The first if statement resolves that case.
    current = &head;
    while (value > (*current)->data)
        current = &((*current)->next);
    
    //value must be less than or equal to (*current)->data
    //if less than, then new node must go before **current
    //node, if equal, placement doesn't matter... Just place
    //everything before **current always to reduce checks.
    aNode = new IntNode(value);
    aNode->next = *current;
    *current = aNode;

    //make current an indirect pointer to not have a prev
    //pointer, and also to not have a special case if 
    //have to insert value before head, and therefore have
    //to make a new head (change where head points to)
}
//EOF

/****************************************************************
 * 
 *  Method remove_duplicates: Class IntList
 *  //PUBLIC
 * --------------------------------------------------------------
 *  Will only keep one instance of value in the list. No
 *  duplicates.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The list can be filled or empty. 
 *  POST-CONDITIONS
 *      The tail is assured to change if the the node that tail
 *      points to is not a unique value. Note, tail may change
 *      multiple times throughout the method (won't always just
 *      be the node right before tail). head is assured to stay
 *      the same, and it's value will NOT change.
****************************************************************/
void IntList::remove_duplicates(void)
{
    IntNode *subHead;   //PROC - shift the head, traverse through the list
    IntNode *current;   //PROC - current node pointer.
    IntNode *temp;      //PROC - delete past address.

    //main loop condition ensures that both empty and
    //lists with only one node are not allowed into
    //the loop.
    subHead = head;
    while (subHead != tail)
    {
        current = subHead;
        //condition ensures that when the loop exits
        //current will point to the node before tail.
        //useful for when have to delete tail, and
        //setup current as the new tail.
        while (current->next != tail)
        {
            if (current->next->data == subHead->data)
            {
                //current->next is asured to not be tail,
                //current->next->next might be. 
                temp = current->next;
                current->next = current->next->next;
                delete temp;
                //since current->next is being changed
                //to current->next->next, it has the a similar
                //effect as current = current->next, therefore
                //no need to increment if inside this if block.
                //Though what is really nice is the current
                //can continue pointing to the same node, and 
                //therefore can still modify the same next pointer
                //if need be for the next iteration. Aka, current
                //continues to point to the "previous" node.
            }
            else
                current = current->next;
        }
        if (tail->data == subHead->data)
        {
            delete tail;
            tail = current;
            tail->next = nullptr;
            
            //ensure that on the next iteration, subHead
            //is not pointing to NULL pointer, only doing
            //this because changing what tail points to
            //before changing what subHead points to
            if (subHead == tail) //note same condition as outer loop
                return; //just end "early"
        }
        subHead = subHead->next;
    }
}
//EOF

IntList& IntList::operator=(const IntList &that)
{
    IntNode *current_that;  //PROC - track node from "that"
    IntNode *current;       //PROC - track node from calling obj.

    //avoid case were same object is on both
    //sides of the "=" operator.
    if (this == &that)
        return *this;       //just return the calling object
    
    current = head;
    current_that = that.head;
    while (current_that != nullptr && current != nullptr)
    {   //change the values of existing nodes, don't
        //allocate more memory if you don't need to.
        current->data = current->data;
        current = current->next;
        current_that = current_that->next;
    }

    if (current != current_that)    //lists are not the same size.
    {
        //calling object's list must have been smaller
        if (current == nullptr)
        {
            //continue moving forward from where left off
            while (current_that != nullptr)
            {
                tail->next = new IntNode(current_that->data);
                tail = tail->next;
                current_that = current_that->next;
            }
        }
        //calling object's list must have been larger than of "that"
        else if (current_that == nullptr)
            /* remove the node that current is pointing at
             * the end of the main while loop, both current
             * and current_that are set to the next node.
             * Therefore the node that current points to here
             * must be the next node. 
             * The only case where this is not true is if 
             * even before going through the while loop,
             * current_that is set to NULL, therefore passed
             * in list is an empty list. Therefore current
             * must be head, and will result in removing
             * all the nodes
             * In the case both current and current_that
             * are NULL, since both are empty list, then
             * the outer if statement wouldn't be true, 
             * and therefore we wouldn't be here.*/
            RemoveNodesStartingAt(current);
    }
    //else both the lists must have had the same amount of nodes

    return *this;
}
//EOF

void IntList::ClearIntList()
{
    IntNode *future;   //PROC - Store node address for next loop
    IntNode *current;  //PROC - Delete the current node
    
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

void IntList::RemoveNodesStartingAt(IntNode *node)
{
    IntNode *future;    //PROC - store the next node
    IntNode *current;   //PROC - track the current node

    //since singly linked list, all cases are expensive
    //and have to traverse the full list, other than 
    //when the passed node is NULL. This is just do 
    //to how a singly linked list works, and have to
    //often be at the previous node.

    if (node == head)
        ClearIntList();
    else if (node == nullptr)
        return;
    else if (node == tail)
    {
        //list only has one node
        if (head == tail)   //protect again current->next == NULL in while
        {
            delete head;
            head = tail = nullptr;  //now list has no nodes
        }

        //list at least has two nodes
        current = head;
        while (current->next != tail) //look ahead to set tail to current later
            current = current->next;
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    else //node passed in is neither the head, or the tail, or NULL
    {
        current = head;
        while (current->next != node)
            current = current->next;
        tail = current; //tail is set to the node right before
        tail->next = nullptr;

        future = node;
        while (future != nullptr)
        {
            current = future;
            future = future->next;
            delete current;
        }
    }
}
//EOF

void IntList::RemoveNodesAfter(IntNode *node)
{
    RemoveNodesStartingAt(node->next);
}
//EOF