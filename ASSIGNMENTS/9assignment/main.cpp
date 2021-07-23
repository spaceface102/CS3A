/****************************************************************
 * AUTHOR           : Osbaldo Gonzalez Jr.
 * ASSIGNMENT 06    : LinkedList Template
 * CLASS            : CS 3A
 * SECTION          : 71206
 * DUE DATE         : 7/22/2021
****************************************************************/

#include "linkedList.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

/*****************************************************************************
 * 
 *   LinkedList && Iterator tester
 *______________________________________________________________________________
 *   This program acts to test the LinkedList class and the Iterator
 *   class. It is put through its paces.
 *______________________________________________________________________________
 *  INPUT:
 *      none
 *  OUTPUT:
 *      none
*****************************************************************************/

/*****************************************************************************
 * FillLinkedList
 *  Just a convince function to fill in a list randomly. Can either
 *  push_front, push_back, or pop_front. Takes in a list by reference,
 *  the number of passes to try to add elements, and a max value for 
 *  the random number inserted. If pop_front gets used on an empty list,
 *  it also conveniently handles the exception, and continues execution.
 * 
 * FullTest
 *  A function that does the whole range of test on a specified templated
 *  Linked List type.
*****************************************************************************/
template<typename E>
void FillLinkedList(LinkedList<E>& list, int numPasses, int minValue, int maxValue);
template<typename E>
void FullTest(void);

//Spefic to CustomTest class (used for extensive LinkeList class testing)
class CustomTest; //class decleration
std::ostream& operator<<(std::ostream& out, const CustomTest&);


int main(void)
{    
    #ifdef EXTRA_TEST
    FullTest<CustomTest>();
    std::cout 
    << "\n\n\n\n\nTHE TEST IS SO LONG SINCE HAVE SO MUCH OUTPUT TEXT\n"
    << "WITH CustomTest Class. Every time you call any method\n"
    << "Associated CustomTest class, there is \"logging\" output\n\n\n\n";
    #else
    std::cout <<"\n\n\n\n\n\nTesting LinkedList with TYPE: double\n\n\n\n\n\n";
    FullTest<double>();
    std::cout <<"\n\n\n\n\n\nTesting LinkedList with TYPE: int\n\n\n\n\n\n\n";
    FullTest<int>();
    std::cout <<"\n\n\n\n\n\nTesting LinkedList with TYPE: char\n\n\n\n\n\n\n";
    FullTest<char>();
    std::cout <<"\n\n\n\n\n\nTesting LinkedList with TYPE: CustomTest\n\n\n\n";
    #endif //EXTRA_TEST
    return 0;
}

/****************************************************************
 * 
 *  FUNCTION: FillLinkedList()
 * --------------------------------------------------------------
 *  Fill in a list randomly. Randomly chosen to push_back, or
 *  push_front, or pop_front. Will also use exceptions in the
 *  event that pop_front throws an exception.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Can be a filled or empty list.
 *  POST-CONDITIONS
 *      The final list is possible to not have any elements if
 *      you get unlucky and all the cases are just pop_front.
 *      The more passes, the more you are assured to have
 *      a list of length > 0.
 *      
 *      In the event that pop_front is used on an empty list,
 *      will handle the exception, and display .what() method.
****************************************************************/
template<typename E>
void FillLinkedList(LinkedList<E>& list, int numPasses, int minValue, int maxValue)
{
    double rand_tail;   //PROC - used to add obvious floating point component
    for (int i = 0; i < numPasses; i++)
    {
        rand_tail = 1.0/((rand()%10)+1);
        switch (rand()%3)
        {
            case 0:
                list.push_back(rand()%(maxValue - minValue + 1) + 
                minValue + rand_tail);
                break;
            case 1:
                list.push_front(rand()%(maxValue - minValue + 1) 
                + minValue + rand_tail);
                break;
            case 2:
                try
                    {list.pop_front();}
                catch (const ListEmpty& empty)
                    {std::cout << empty.what() << "\n";}
                break;
        }
    }
}

/****************************************************************
 * 
 *  FUNCTION: FillTest
 *  //Template
 * --------------------------------------------------------------
 *  Run the LinkedList class through it's paces using a wide
 *  variety of types.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The templated class must have all the required operator
 *      overloads, described in the linkedlist.h note under class
 *      definition, in order to full work. Else, will refuse to
 *      compile.
 * 
 *  POST-CONDITIONS
 *      All exceptions will be caught, and dealt with.
****************************************************************/
template<typename E>
void FullTest(void)
{
    LinkedList<E> emptylist;      //PROC - just keep an empty list around
    LinkedList<E> temp;           //PROC - used for temp storage of other lists
    LinkedList<E> sorted;         //PROC - a sorted list
    LinkedList<E> listarray[4];   //PROC - 4 sorted lists to play with
    time_t currentTime;     //PROC - number used to seed srand.

    currentTime = time(NULL);
    srand(currentTime);  //seed random number generator

    #if DEBUG
    std::cout << "Time used to seed srand(): " << currentTime << "\n";
    #endif

    //fill each list in listarray with values
    for (int i = 0; i < 4; i++)
        FillLinkedList(listarray[i], 25, ' ', 'z');
        //min value ' ' and max value 'z' used to ensure
        //char type also looks printable, with defining chars!
    
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
    std::cout << "Displaying listarray[0] using Iterator:\n";
    for (Iterator<E> i = listarray[0].begin();i != listarray[0].end(); ++i)
        std::cout << *i << " ";
    std::cout << "\n\n";

    std::cout << "Displaying emptylist:\n";
    emptylist.display(); std::cout << "\n";
    std::cout << "Displaying emptylist using Iterator:\n";
    for (Iterator<E> i = emptylist.begin(); i != emptylist.end(); ++i)
        std::cout << *i << " ";
    std::cout << "\n\n";

    FillLinkedList(sorted, 15, ' ', 'z');
    sorted.select_sort();
    std::cout << "Displaying sorted:\n";
    sorted.display(); std::cout << "\n";
    std::cout << "Changing sorted list, while using Iterator.\n";
    std::cout << "Will insert a number sorted if rand()%2 == 1\n";
    for (Iterator<E> i = sorted.begin(); i != sorted.end(); ++i)
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
    << "the node that Iterator is pointing too, the point\n"
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
    << "Testing sum():    " << listarray[3].sum() << "\n";

    //note testing front or back since its a emptylist,
    //and I made the decision 
    std::cout 
    << "\n\nThe follwing methods will all be perform on emptylist\n"
    << "Testing length(): " << emptylist.length() << "\n"
    << "Testing sum():    " << emptylist.sum() << "\n";
    //Force to throw exception
    std::cout << "Testing front():\n";
    try
        {emptylist.front();}
    catch (const ListEmpty& exc)
        {std::cout << exc.what() << "\n";}
    std::cout << "Testing back():\n";
    try
        {emptylist.back();}
    catch (const ListEmpty& exc)
        {std::cout << exc.what() << "\n";}
    std::cout << "Testing pop_front():\n";
    try
        {emptylist.pop_front();}
    catch (const ListEmpty& exc)
        {std::cout << exc.what() << "\n";}

    LinkedList<E> acopy(listarray[1]);    //TEST - copy constructor
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



    std::cout << "\n\nFor old times sake, lets see\n"
              << "that we didn't break anything\n";
    //OLD TEST FROM THE PREVIOUS ASSIGNMENT
    using namespace std;
    LinkedList<E> L1, L2;
    
    cout << "Testing display function on empty List\n";
    L1.display();
    
    cout << "\nTesting display function on one item List\n";
    L1.push_front(100);
    L1.display();
    cout << endl;
    
    cout << "\nTesting display function on two item List\n";
    L1.push_front(200);
    L1.display();
    cout << endl;
    
    cout << "\nTesting push_front function (by calling it 10 times)\n";
    for (int i = 0; i < 10; i++){
        L1.push_front(i);
    }
    
    cout << "Testing display function on list with several items\n";
    L1.display();
    cout << endl;
    
    cout << "\nTesting the pop_front function\n";
    for (int i = 0; i < 5; i++){
        L1.pop_front();
    }
    
    cout << "Testing display function after calling pop_front 5 times\n";
    L1.display();
    cout << endl;
        
    cout << "\nTesting push_back function (by calling it 10 times)\n";
    for (int i = 0; i < 10; i++){
        L1.push_back(rand()%10);
    }
    
    L1.display();
    cout << endl;
    
    cout << "\nTesting select_sort() function\n";
    L1.select_sort();
    L1.display();
    cout << endl;
    
    cout << "\nTesting push_back function (by calling it 10 times)\n";
    for (int i = 0; i < 10; i++){
        L1.insert_sorted(rand()%10);
        cout << endl;
        L1.display();
    }
    
    cout << "\nTesting remove_duplicates() function\n";
    L1.remove_duplicates();
    L1.display();
    cout << endl;
}
//EOF

class CustomTest
{
public:
    CustomTest(void)
    {
        static int i = 0;
        std::cout << "Class CustomTest default constructor "
        << "instance number: " << i++ << "\n";
    }
    CustomTest(int)
    {
        static int i = 0;
        std::cout << "Class CustomTest int copy constructor "
        << "instance number: " << i++ << "\n";
    }
    CustomTest& operator=(const CustomTest&)
    {   
        static int i = 0;
        std::cout << "operator= instance number: " << i++ << "\n";
        return *this;
    }
    CustomTest operator+(const CustomTest&) const
    {
        static int i = 0;
        std::cout << "operator+ instance number: " << i++ << "\n";
        return CustomTest();    //just return default constructor.
    }
    bool operator<(const CustomTest&) const
    {
        srand(time(NULL));
        static int i = 0;
        std::cout << "operator< instance number: " << i++ << "\n";
        return rand()%2;
    }
    bool operator>=(const CustomTest&) const
    {        
        srand(time(NULL));
        static int i = 0;
        std::cout << "operator>= instance number: " << i++ << "\n";
        return rand()%2;
    }
    bool operator>(const CustomTest&) const
    {
        srand(time(NULL));
        static int i = 0;
        std::cout << "operator> instance number: " << i++ << "\n";
        return rand()%2;
    }
    bool operator==(const CustomTest&) const
    {
        srand(time(NULL));
        static int i = 0;
        std::cout << "operator== instance number: " << i++ << "\n";
        return rand()%2;
    }
};

//Part of the CustomTest class
std::ostream& operator<<(std::ostream& out, const CustomTest&)
{
    static int i = 0;
    std::cout << "operator<< instance number: " << i++ << "\n";
    return out;
}