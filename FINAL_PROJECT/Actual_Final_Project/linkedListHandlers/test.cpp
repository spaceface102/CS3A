
#include "linkedList_Wrapper.h"
#include "textToTypeConvert.h"
#include <iostream>
#include <string>

int main(void)
{
    LinkedList_Wrapper<int> test(textConvert::toInt);

    for (long i = 1; i < 10; i++)
        test.pushBack(std::to_string(i).c_str());

    test.makeCopyOfActiveList();
    test.setNextListAsActive();
    test.popFront();
    test.setActiveList(0);
    test.display(std::cout); std::cout << "\n";
    test.setActiveList(1);
    test.display(std::cout); std::cout << "\n";
}