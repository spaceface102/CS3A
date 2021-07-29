#ifndef LINKED_LIST_WRAPPER_CLASS_H
#define LINKED_LIST_WRAPPER_CLASS_H

#include "currentLinkedList_Handler.h"
#include "myVector.h"
#include "linkedList.h"
#include "listEmpty.h"
#include <cstdint>

template<typename T>
class LinkedList_Wrapper : public CurrentLinkedList_Handler
{
public:
    LinkedList_Wrapper(void) = delete; //ensures initialization
    LinkedList_Wrapper(T (*textConvertFunction)(const char *text));
    unsigned numAvaliableLists(void) const override;
    void makeCopyOfActiveList(void) override;
    void setActiveList(unsigned listNumber) override;
    unsigned getActiveListNumber(void) const override;
    void setNextListAsActive(void) override;
    
    //Purely wrappers around existing LinkedList Functions
    void sort(void) override;
    void removeDuplicates(void) override;
    void popFront(std::ostream& error_output = std::cerr) override;
    void pushBack(const char* text) override;
    void pushFront(const char* text) override;
    void insertSorted(const char* text) override;
    void insert(const char* atNode, const char* value) override;
    void display(std::ostream& out) override; //normal display full linked list
    void display(std::ostream& out, const char* start,
                         const char* end) override; //select portion

private:
    unsigned activeListIndex;                   //PROC -current index in vector
MyVector<LinkedList<T>> listVector;             //PROC - list vector
    T (*textToType_Converter)(const char *text);//PROC - converter from cstring
                                                //to specific template type
};

/********************************************************************
 * LinkedList_Wrapper
 *  Publicly inherits from the CurrentLinkedList_Handler class,
 *  where it overrides all the methods in said class. This is a
 *  templated class, and therefore in theory should work for any
 *  type, assuming the type defines the necerrary operator overloads
 *  demanded by the LinkedList methods, and there is a correct
 *  converted from cstring to the specific type.
********************************************************************/

//DEFINITIONS
/****************************************************************
 * 
 *  Method LinkedList_Wrapper: Class LinkedList_Wrapper  
 *  //CONSTRUCTOR
 * --------------------------------------------------------------
 *  Takes a function pointer to valid "convertion function".
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The function pointer's return type must be eq. to the
 *      templated type.
 * 
 *  POST-CONDITIONS
 *      The private vector is of size 1, the index being
 *      "pointed" at is 0, and the converter is ready to be used.
 *      Ready for the rest of the methods!
****************************************************************/
template<typename T>
LinkedList_Wrapper<T>::LinkedList_Wrapper(
    T (*textConvertFunction)(const char *text)
)
{
    activeListIndex = 0; //vector index number, start counting from 0
    listVector.push_back(LinkedList<T>()); //init Vector with one index
    textToType_Converter = textConvertFunction; //function pointer to converting function
}
//EOF

/****************************************************************
 * 
 *  Method numAvaliableLists: Class LinkedList_Wrapper  
 * --------------------------------------------------------------
 *  Returns the size of the private vector of templated lists.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Only accesible through an object.
 *  POST-CONDITIONS
 *      Assured to at least be 1. (due to the constructor)
****************************************************************/
template<typename T>
unsigned LinkedList_Wrapper<T>::numAvaliableLists(void)const
    {return listVector.size();}
//EOF

/****************************************************************
 * 
 *  Method makeCopyOfActiveList: Class LinkedList_Wrapper  
 * --------------------------------------------------------------
 *  Makes a copy of the "current active list" and pushes it
 *  back to the private vector of templated lists.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Only accesible through an object.
 *  POST-CONDITIONS
 *      The size of the private vector grows by one. The active
 *      list continues to be the same.
****************************************************************/
template<typename T>
void LinkedList_Wrapper<T>::makeCopyOfActiveList(void)
{
    LinkedList<T> copy(listVector.at(activeListIndex));

    //reason for the temp variable is that if the vector needs
    //to expand, the value at activeIndex is deleted since
    //push_back takes a const reference to the variable and
    //does not make a copy!!! Tricky!
    listVector.push_back(copy);
}
//EOF

/****************************************************************
 * 
 *  Method setActiveList: Class LinkedList_Wrapper  
 * --------------------------------------------------------------
 *  Changes the current active list by changing the vector of
 *  lists active index. Is assured to change to a valid index.
 *  If invalid index is put, will default to the first (0th)
 *  index
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Only accesible through an object.
 *  POST-CONDITIONS
 *      No changes are made to the vector itself, and all data
 *      associated with previous active vector is kept safe.
****************************************************************/
template<typename T>
void LinkedList_Wrapper<T>::setActiveList(unsigned listNumber)
{
    if (listNumber >= listVector.size())
        activeListIndex = 0; //default list
    else
        activeListIndex = listNumber;
}
//EOF

/****************************************************************
 * 
 *  Method getActiveListNumber: Class LinkedList_Wrapper
 * --------------------------------------------------------------
 *  Returns the value of the private field activeListIndex.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Only accesible through an object.
 *  POST-CONDITIONS
 *      Assured to be greater than or equal to 0. Will at most
 *      be equal to LinkedList_Wrapper::numAvaliableList() - 1.
****************************************************************/
template<typename T>
unsigned LinkedList_Wrapper<T>::getActiveListNumber(void) const
    {return activeListIndex;}
//EOF

/****************************************************************
 * 
 *  Method setNextListAsActive: Class LinkedList_Wrapper
 * --------------------------------------------------------------
 *  Changes activeListIndex to next valid index. If at the
 *  end of the private vector's index, will wrap around and
 *  start from the begenging (like a clock)
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Only accesible through an object.
 *  POST-CONDITIONS
 *      State of the previously defined active list is 
 *      assured not to change.
****************************************************************/
template<typename T>
void LinkedList_Wrapper<T>::setNextListAsActive(void)
{
    activeListIndex = (activeListIndex + 1)%(listVector.size());
}
//EOF




//Purely Wrappers around the LinkedList functions



/****************************************************************
 * 
 *  Method sort: Class LinkedList_Wrapper
 * --------------------------------------------------------------
 *  Uses select_sort on the currently active linked list in the
 *  private vector of templated lists
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Only accesible through an object.
 *  POST-CONDITIONS
 *      Only the current active linked list gets modified.
****************************************************************/
template<typename T>
void LinkedList_Wrapper<T>::sort(void)
{
    listVector.at(activeListIndex).select_sort();
}
//EOF

/****************************************************************
 * 
 *  Method removeDuplicates: Class LinkedList_Wrapper
 * --------------------------------------------------------------
 *  Uses remove_duplicates method on the currently active 
 *  linked list in the private vector of templated lists
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Only accesible through an object.
 *  POST-CONDITIONS
 *      Only the current active linked list gets modified.
****************************************************************/
template<typename T>
void LinkedList_Wrapper<T>::removeDuplicates(void)
{
    listVector.at(activeListIndex).remove_duplicates();
}
//EOF

/****************************************************************
 * 
 *  Method popFront: Class LinkedList_Wrapper
 * --------------------------------------------------------------
 *  Uses pop_front method on the currently active 
 *  linked list in the private vector of templated lists
 *  Will handle possible exception, and display to error_output
 *  std::ostream, which by default is std::cerr
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Only accesible through an object.
 *  POST-CONDITIONS
 *      Only the current active linked list gets modified.
****************************************************************/
template<typename T>
void LinkedList_Wrapper<T>::popFront(std::ostream& error_output)
{
    try
    {
        listVector.at(activeListIndex).pop_front();
    }
    catch (const ListEmpty& except)
    {
        error_output << except.what() << "\n";
    }
}
//EOF

/****************************************************************
 * 
 *  Method pushBack: Class LinkedList_Wrapper
 * --------------------------------------------------------------
 *  Uses push_back method on the currently active 
 *  linked list in the private vector of templated lists.
 *  Takes in a cstring as input which is converted
 *  with the passed in function pointer when initially declaring
 *  and constructing the calling LinkedList_Wrapper object.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Only accesible through an object.
 *      Very depended on the implentsation of the passed in
 *      function pointer converter being correct for this
 *      specific templated class.
 *  POST-CONDITIONS
 *      Only the current active linked list gets modified.
****************************************************************/
template<typename T>
void LinkedList_Wrapper<T>::pushBack(const char* text)
{
    listVector.at(activeListIndex).push_back(textToType_Converter(text));
}
//EOF

/****************************************************************
 * 
 *  Method pushFront: Class LinkedList_Wrapper
 * --------------------------------------------------------------
 *  Uses push_front method on the currently active 
 *  linked list in the private vector of templated lists.
 *  Takes in a cstring as input which is converted
 *  with the passed in function pointer when initially declaring
 *  and constructing the calling LinkedList_Wrapper object.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Only accesible through an object.
 *      Very depended on the implentation of the passed in
 *      function pointer converter being correct for this
 *      specific templated class.
 *  POST-CONDITIONS
 *      Only the current active linked list gets modified.
****************************************************************/
template<typename T>
void LinkedList_Wrapper<T>::pushFront(const char* text)
{
    listVector.at(activeListIndex).push_front(textToType_Converter(text));
}
//EOF

/****************************************************************
 * 
 *  Method insertSorted: Class LinkedList_Wrapper
 * --------------------------------------------------------------
 *  Uses insert_sorted method on the currently active 
 *  linked list in the private vector of templated lists.
 *  Takes in a cstring as input which is converted
 *  with the passed in function pointer when initially declaring
 *  and constructing the calling LinkedList_Wrapper object.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Only accesible through an object.
 *      Very depended on the implentation of the passed in
 *      function pointer converter being correct for this
 *      specific templated class.
 *  POST-CONDITIONS
 *      Only the current active linked list gets modified.
****************************************************************/
template<typename T>
void LinkedList_Wrapper<T>::insertSorted(const char* text)
{
    listVector.at(activeListIndex).insert_sorted(textToType_Converter(text));
}
//EOF


/****************************************************************
 * 
 *  Method display: Class LinkedList_Wrapper
 * --------------------------------------------------------------
 *  Uses display method from the templated linked list class.
 *  Have to pass in a std::ostream& to define where output
 *  should got to.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Only accesible through an object.
 *  POST-CONDITIONS
 *      Only the current active linked list gets displayed.
 *      The current active linked list does not change state,
 *      and stays constants
****************************************************************/
template<typename T>
void LinkedList_Wrapper<T>::display(std::ostream& out)
{
    listVector.at(activeListIndex).display(out);
}
//EOF

/****************************************************************
 * 
 *  Method display : Class LinkedList_Wrapper<t>
 *  //PUBLIC
 *  //OVERLOAD 2
 * --------------------------------------------------------------
 *  This function displays output to the passed in output stream.
 *  Only the portion of the linked list defined by the start and
 *  end arguments are displayed. NOTE: the head of the linked
 *  list is treated as node number 1, therefore there is NO
 *  NODE 0. This is done since user usually starts counting
 *  from zero to one. This therefore also means that the end
 *  index is equal to the length of the linked list.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Passed in cstring MUST have a null terminainting
 *      character.
 *  POST-CONDITIONS
 *      In the event that start is greater than or equal to end
 *      nothing is printed.
 *      There are no new lines added in this method. Final data
 *      output is not trailed by any character. Seperating
 *      between data is " "
****************************************************************/
template<typename T>
void LinkedList_Wrapper<T>::display(std::ostream& out, const char* start,
                                    const char* end)
{
    uint64_t index;         //PROC - track the current node number
    uint64_t startIndex;    //PROC - convert start cstring
    uint64_t endIndex;      //PROC - convert end cstring
    Iterator<T> currNode;   //PROC - current node in the linked list
    Iterator<T> endNode;    //PROC - technically just a node ptr to NULL

    startIndex = atol(start);
    startIndex = (startIndex <= 0) ? 1 : startIndex; //ensure starting at 1
    endIndex = atol(end);

    if (startIndex > endIndex)
        return; //nothing to print....

    //counts head node as node number 1
    index = 1;
    currNode = listVector.at(activeListIndex).begin();
    endNode = listVector.at(activeListIndex).end();
    while (currNode != endNode && index < startIndex)
        ++currNode, ++index;

    //endIndex - 1 to ensure to not have trailing ", "
    for (; currNode != endNode && index < endIndex; ++currNode, ++index)
        out << *currNode << " "; //display the node!
    
    //if currNode != endNode, then index is assured to be eq. endIndex
    if (currNode != endNode)
        out << *currNode;
}
//EOF


/****************************************************************
 * 
 *  Method insert: Class LinkedList_Wrapper
 * --------------------------------------------------------------
 *  Uses insert method on the currently active 
 *  linked list in the private vector of templated lists.
 *  Takes in a cstring as input which is converted
 *  with the passed in function pointer when initially declaring
 *  and constructing the calling LinkedList_Wrapper object.
 *  The paramter atNode is used to define after what node
 *  to insert the value ("noting head is node number 1")
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Only accesible through an object.
 *      Very depended on the implentation of the passed in
 *      function pointer converter being correct for this
 *      specific templated class.
 *  POST-CONDITIONS
 *      Only the current active linked list gets modified.
****************************************************************/
template<typename T>
void LinkedList_Wrapper<T>::insert(const char* atNode, const char* value)
{
    listVector.at(activeListIndex).insert(atoi(atNode), 
        textToType_Converter(value)
    );
}
//EOF

#endif //LINKED_LIST_WRAPPER_CLASS_H
