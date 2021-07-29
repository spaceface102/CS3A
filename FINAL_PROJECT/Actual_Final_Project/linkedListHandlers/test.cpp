
#include "linkedList_Wrapper.h"
#include "textToTypeConvert.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

int main(void)
{
    CurrentLinkedList_Handler *ptr;
    LinkedList_Wrapper<int>    list0(textConvert::toInt);
    LinkedList_Wrapper<double> list1(textConvert::toDouble);

    double tail;
    srand(time(NULL));
    for (long i = 1; i < 10; i++)
    {
        tail = 1.0/((rand()%10) + 1);
        list0.pushBack(std::to_string(i).c_str());
        list1.pushBack(std::to_string(i + tail).c_str());
    }

    ptr = &list0;
    ptr->display(std::cout);
    ptr = &list1;
    ptr->display(std::cout);
}