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
    void insertSorted(const char* text) override;
    void insert(const char* atNode, const char* value) override;
    void display(std::ostream& out) override; //normal display full linked list
    void display(std::ostream& out, const char* start,
                         const char* end) override; //select portion

private:
    unsigned activeListIndex;
    MyVector<LinkedList<T>> listVector;
    T (*textToType_Converter)(const char *text);
};

//DEFINITIONS
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

template<typename T>
unsigned LinkedList_Wrapper<T>::numAvaliableLists(void)const
    {return listVector.size();}
//EOF

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

template<typename T>
void LinkedList_Wrapper<T>::setActiveList(unsigned listNumber)
{
    if (listNumber >= listVector.size())
        activeListIndex = 0; //default list
    else
        activeListIndex = listNumber;
}
//EOF

template<typename T>
unsigned LinkedList_Wrapper<T>::getActiveListNumber(void) const
    {return activeListIndex;}
//EOF

template<typename T>
void LinkedList_Wrapper<T>::setNextListAsActive(void)
{
    activeListIndex = (activeListIndex + 1)%(listVector.size());
}
//EOF




//Purely Wrappers around the LinkedList functions




template<typename T>
void LinkedList_Wrapper<T>::sort(void)
{
    listVector.at(activeListIndex).select_sort();
}
//EOF

template<typename T>
void LinkedList_Wrapper<T>::removeDuplicates(void)
{
    listVector.at(activeListIndex).remove_duplicates();
}
//EOF

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

template<typename T>
void LinkedList_Wrapper<T>::pushBack(const char* text)
{
    listVector.at(activeListIndex).push_back(textToType_Converter(text));
}
//EOF

template<typename T>
void LinkedList_Wrapper<T>::insertSorted(const char* text)
{
    listVector.at(activeListIndex).insert_sorted(textToType_Converter(text));
}
//EOF

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

    if (startIndex >= endIndex)
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

template<typename T>
void LinkedList_Wrapper<T>::insert(const char* atNode, const char* value)
{
    listVector.at(activeListIndex).insert(atoi(atNode), 
        textToType_Converter(value)
    );
}
//EOF

#endif //LINKED_LIST_WRAPPER_CLASS_H