#include "date.h"
#include <iostream>

void test14()
{
    int days;
    days = 2000;
    Date d1 = Date(3,23, 2012);
    Date d2 = d1.addDays(days);

    std::cout << "14. Adding days" << std::endl;
    std::cout << "Output should be September 13, 2017\n";
    d1.printAlpha();
    std::cout << " == " << days << " days ==> ";
    d2.printAlpha();
    std::cout << std::endl << "-------------------" << std::endl;
}

void test15()
{
    int days;
    days = -2000;
    Date d1 = Date(2, 1, 2000);
    Date d2 = d1.addDays(days);

    std::cout << "15. Subtracting days" << std::endl;\
    std::cout << "Output should be August 11, 1994\n";
    d1.printAlpha();
    std::cout << " == " << days << " days ==> ";
    d2.printAlpha();
    std::cout << std::endl << "-------------------" << std::endl;
}

int main(void)
{
    test14();
    test15();
}