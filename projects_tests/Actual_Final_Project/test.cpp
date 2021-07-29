
#include "linkedList_Wrapper.h"
#include "textToTypeConvert.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

int main(void)
{
    LinkedList_Wrapper<Date> test(textConvert::toDate);

    test.pushBack("");
    test.pushBack("nov");
    test.pushBack("febu 29, 2012");
    test.pushBack("MAY 28, 2020");
    test.pushBack("july 22, 1999");

    test.makeCopyOfActiveList();
    test.setNextListAsActive();
    test.pushBack("november 9 2000");

    test.display(std::cout);
    std::cout << "\n";

    test.setActiveList(0);
    test.display(std::cout);
    std::cout << "\n";
}