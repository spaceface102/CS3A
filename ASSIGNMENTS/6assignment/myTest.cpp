#include <iostream>
#include "IntList.h"
#include <cstdlib>
#include <ctime>

int main(void)
{
    srand(time(NULL));
    IntList list;
    int max;
    
    std::cout << "Max value: ";
    std::cin >> max;

    for (int i = 0 ; i < 20; i ++)
        list.push_back(rand()%(max+1));
    
    list.display(); std::cout << "\n";
    list.select_sort();
    list.display(); std::cout << "\n";
    return 0;
}