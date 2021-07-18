/****************************************************************
 * AUTHOR           : Osbaldo Gonzalez Jr.
 * ASSIGNMENT 06    : IntList Recursive && IntListIterator
 * CLASS            : CS 3A
 * SECTION          : 71206
 * DUE DATE         : 7/15/2021
****************************************************************/

#include "doublyLinkedList.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

/*****************************************************************************
 * 
 *   IntList && IntListIterator tester
 *______________________________________________________________________________
 *   This program acts to test the IntList class and the IntListIterator
 *   class. It is put through its paces.
 *______________________________________________________________________________
 *  INPUT:
 *      none
 *  OUTPUT:
 *      IntList emptylist   //PROC - a list
 *      IntList temp        //PROC - a list
 *      IntList sorted      //PROC - a list
 *      IntList listarray   //PROC - a list
*****************************************************************************/

/*****************************************************************************
 * FillIntList
 *  Just a convince function to fill in a list randomly. Can either
 *  push_front, push_back, or pop_front. Takes in a list by reference,
 *  the number of passes to try to add elements, and a max value for 
 *  the random number inserted.
*****************************************************************************/
static void FillIntList(DoublyLinkedList& list, int numPasses, int maxValue);

int main(void)
{
    DoublyLinkedList emptylist;      //PROC - just keep an empty list around
    DoublyLinkedList temp;           //PROC - used for temp storage of other lists
    DoublyLinkedList sorted;         //PROC - a sorted list
    DoublyLinkedList listarray[4];   //PROC - 4 sorted lists to play with
    time_t currentTime;     //PROC - number used to seed srand.
    
    currentTime = time(NULL);
    srand(currentTime);  //seed random number generator

    #if DEBUG
    std::cout << "Time used to seed srand(): " << currentTime << "\n";
    #endif

    //fill each list in listarray with values
    for (int i = 0; i < 4; i++)
        FillIntList(listarray[i], 25, 500);
    
    //see what happens with the overloaded "=" operator
    std::cout << "listarray[2] originally:\n";
    listarray[2].display(); std::cout << "\n\n";
    
    std::cout << "\nCopying listarray[2] into temp variable....\n";
    temp = listarray[2];
    std::cout << "Executing: listarray[2] = emptyList;\n";
    listarray[2] = emptylist;
    std::cout << "Displaying temp (copied listarray[2] with operator=)\n";
    temp.display(); std::cout << "\n";
    std::cout << "Display listarray[2] after executing previous code:\n";
    listarray[2].display(); std::cout << "\n";

    std::cout << "Modifying temp....(push_back rand number)\n";
    temp.push_back(rand()%100);
    std::cout << "Displaying temp again:\n";
    temp.display(); std::cout << "\n";
    std::cout << "Displaying listarray[2] again\n";
    listarray[2].display(); std::cout << "\n";

    std::cout << "Modifying listarray[2].\n";
    listarray[2].push_back(rand()%100);
    std::cout << "Displaying temp again:\n";
    temp.display(); std::cout << "\n";
    std::cout << "Displaying listarray[2] again\n";
    listarray[2].display(); std::cout << "\n\n";

    listarray[2] = temp;
    std::cout << "Executing: listarray[2] = temp\n";
    std::cout << "Displaying temp again:\n";
    temp.display(); std::cout << "\n";
    std::cout << "Displaying listarray[2] again\n";
    listarray[2].display(); std::cout << "\n";
    std::cout << "\n";

    //Testing iterator
    std::cout << "Displaying listarray[0]:\n";
    listarray[0].display(); std::cout << "\n";
    std::cout << "Displaying listarray[0] using IntListIterator:\n";
    for (IntListIterator i = listarray[0].begin();i != listarray[0].end(); ++i)
        std::cout << *i << " ";
    std::cout << "\n\n";

    std::cout << "Displaying emptylist:\n";
    emptylist.display(); std::cout << "\n";
    std::cout << "Displaying emptylist using IntListIterator:\n";
    for (IntListIterator i = emptylist.begin(); i != emptylist.end(); ++i)
        std::cout << *i << " ";
    std::cout << "\n\n";

    FillIntList(sorted, 15, 100);
    sorted.select_sort();
    std::cout << "Displaying sorted:\n";
    sorted.display(); std::cout << "\n";
    std::cout << "Changing sorted list, while using IntListIterator.\n";
    std::cout << "Will insert a number sorted if rand()%2 == 1\n";
    for (IntListIterator i = sorted.begin(); i != sorted.end(); ++i)
    {
        std::cout << *i << " ";
        if (rand()%2)
            sorted.insert_sorted(rand()%100);
    }
    std::cout << "\nDisplaying sorted after:\n";
    sorted.display(); std::cout << "\n";
    std::cout 
    << "Should be usually different, as when inserting a\n"
    << "random number, it might go ahead or behind\n"
    << "the node that IntListIterator is pointing too, the point\n"
    << "is to see that still, we don't access any memory we are\n"
    << "not supposed to, and end iterating correctly\n\n";

    //Testing front, back, length, sum, reverseDisplay
    std::cout << "Displaying listarray[3]:\n";
    listarray[3].display(); std::cout << "\n";

    if (listarray[3].length() == 0)
        listarray[3].push_back(rand()%100);
    std::cout
    << "The following methods will all be performed on lisarray[3]\n"
    << "Testing front():  " << listarray[3].front() << "\n"
    << "Testing back():   " << listarray[3].back() << "\n"
    << "Testing length(): " << listarray[3].length() << "\n"
    << "Testing display(false):\n";
    listarray[3].display(false); std::cout << "\n\n";

    //note testing front or back since its a emptylist,
    //and I made the decision 
    std::cout 
    << "The follwing methods will all be perform on emptylist\n"
    << "Testing length(): " << emptylist.length() << "\n"
    << "Testing display(false):\n";
    emptylist.display(false); std::cout << "\n\n";


    DoublyLinkedList acopy(listarray[1]);    //TEST - copy constructor
    std::cout << "Testing the copy constructor\n";
    std::cout << "Displaying copy of listarray[1]\n";
    acopy.display(); std::cout << "\n";
    std::cout << "Displaying listarray[1]\n";
    listarray[1].display(); std::cout << "\n\n";

    std::cout << "Modifying the copied list\n";
    acopy.push_back(rand()%100);
    acopy.push_front(rand()%100);
    std::cout << "Done pushing back and pushing front rand values!\n";
    std::cout << "Displaying copy of listarray[1]\n";
    acopy.display(); std::cout << "\n";
    std::cout << "Displaying listarray[1]\n";
    listarray[1].display(); std::cout << "\n\n";

    std::cout << "Modifying listarray[1]:\n";
    listarray[1].push_back(rand()%10000);
    listarray[1].push_front(rand()%10000);
    std::cout << "Done pushing back and pushing front rand values!\n";
    std::cout << "Displaying copy of listarray[1]\n";
    acopy.display(); std::cout << "\n";
    std::cout << "Displaying listarray[1]\n";
    listarray[1].display(); std::cout << "\n";
    std::cout << "\n";

    return 0;
}

/****************************************************************
 * 
 *  FUNCTION: FillIntList()
 *  //Static function
 * --------------------------------------------------------------
 *  Fill in a list randomly. Randomly chosen to push_back, or
 *  push_front, pop_back or pop_front
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Can be a filled or empty list.
 *  POST-CONDITIONS
 *      The final list is possible to not have any elements if
 *      you get unlucky and all the cases are just pop_front.
 *      The more passes, the more you are assured to have
 *      a list of length > 0.
****************************************************************/
static void FillIntList(DoublyLinkedList& list, int numPasses, int maxValue)
{
    for (int i = 0; i < numPasses; i++)
    {
        switch (rand()%5)
        {
            case 0: case 4: //used so on average have something in the list
                list.push_back(rand()%(maxValue+1));
                break;
            case 1:
                list.push_front(rand()%(maxValue+1));
                break;
            case 2:
                list.pop_front();
                break;
            case 3:
                list.pop_back();
                break;
        }
    }
}