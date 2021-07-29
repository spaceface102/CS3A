
#include "linkedList_Wrapper.h"
#include "textToTypeConvert.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

int main(void)
{
    LinkedList_Wrapper<int> test = textConvert::toInt;

    test.pushBack("1");
    test.pushBack("2");
    test.pushBack("4");
    test.pushBack("9");
    test.pushBack("0");
    test.sort();
    test.insertSorted("5");
    test.display(std::cout, "1", "6");
    std::cout << "\n";
}