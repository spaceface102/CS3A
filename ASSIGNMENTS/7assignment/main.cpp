#include "intList.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

void FillIntList(IntList& list, int numPasses, int maxValue)
{
    for (int i = 0; i < numPasses; i++)
    {
        switch (rand()%3)
        {
            case 0:
                list.push_back((rand()%maxValue)+1);
                break;
            case 1:
                list.push_front((rand()%maxValue)+1);
                break;
            case 2:
                list.pop_front();
                break;
        }
    }
}

int main(void)
{
    IntList emptylist;
    IntList temp;
    IntList listarray[4];
    time_t currentTime;
    
    currentTime = time(NULL);
    srand(currentTime);  //seed random number generator

    #if DEBUG
    std::cout << "Time used to seed srand(): " << currentTime << "\n";
    #endif

    //fill each list in listarray with values
    for (int i = 0; i < 4; i++)
        FillIntList(listarray[i], 42, 1000);
    
    //see what happens with the overloaded "=" operator
    std::cout << "listarray[2] originally: ";
    listarray[2].display(); std::cout << "\n";
    
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
    
    std::cout << "\n";

    //Testing iterator
    std::cout << "Displaying listarray[0]:\n";
    listarray[0].display(); std::cout << "\n";
    std::cout << "Displaying listarray[1]:\n";
    listarray[1].display(); std::cout << "\n";

    for (IntListIterator i = listarray[0].begin(); i != listarray[0].end(); ++i)
    {
        if (rand()%2)
        {
        }
    }
    return 0;
}