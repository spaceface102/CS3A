#include <iostream>
#include "date.h"

#define EC 1

using namespace std;

/*******************************************************************
 * Date Class
 * _________________________________________________________________
 * The program would test the Date class constructors and print
 *    functions. Constructors work with both name and number for
 *    months, work with leap years and includes a addDays() function
 *    that add days on a date and returns a valid new date.
 * _________________________________________________________________
 * INPUT:
 *    - none
 *
 * OUTPUT:
 *    - d1 : valid day
 *    - d2 : valid day after adding/subtracting days
 ******************************************************************/

void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();
void test8();
void test9();
void test10();
void test11();
void test12();
void test13();
void test14();
void test15();

int main()
{
    int testNum;
    
    cout << "Enter test number: \n";
    cin >> testNum;
    
    switch(testNum)
    {
        case 1:
            //Default
            test1();
            break;
        case 2:
            //Correct numeric
            test2();
            break;
        case 3:
            //Correct alpha
            test3();
            break;
        case 4:
            //Invalid Numeric: Month
            test4();
            break;
        case 5:
            //Invalid Alpha: Month
            test5();
            break;
        case 6:
            //Invalid Numeric: day (non-leap February)
            test6();
            break;
        case 7:
            //Invalid Numeric: day (leap - February)
            test7();
            break;
        case 8:
            //Invalid Numeric: day (not February and greater than max days)
            test8();
            break;
        case 9:
            //Invalid Numeric: day (not February and equal to zero)
            test9();
            break;
        case 10:
            //Invalid Alpha day: (non-leap February)
            test10();
            break;
        case 11:
            //Invalid Alpha day: (leap - February)
            test11();
            break;
        case 12:
            //Invalid Alpha day: (not February and greater than max days)
            test12();
            break;
        case 13:
            //Invalid Alpha day: (not February and equal to zero)
            test13();
        case 14:
            //Adding Days
            test14();
            //Subtracting Days
            test15();
            break;
    }
    


    return 0;
}

void test1()
{
    cout << "1. Default" << endl;
    Date d1 = Date();
    cout << "numeric:  ";
    d1.printNumeric();
    cout << endl;
    cout << "alpha:\t";
    d1.printAlpha();
    cout << endl;
    cout << "-------------------" << endl;
}

void test2()
{
    cout << "2. Numeric date 7.3.1991" << endl;
    Date d1 = Date(7, 3, 1991);
    cout << "numeric:  ";
    d1.printNumeric();
    cout << endl;
    cout << "alpha:\t";
    d1.printAlpha();
    cout << endl;
    cout << "-------------------" << endl;
}

void test3()
{
    cout << "3. Alpha date: July 3, 1991" << endl;
    Date d1 = Date("July", 3, 1991);
    cout << "numeric:  ";
    d1.printNumeric();
    cout << endl;
    cout << "alpha:\t";
    d1.printAlpha();
    cout << endl;
    cout << "-------------------" << endl;
}

void test4()
{
    cout << "4. Invalid Numeric Date: 0.3.1991 > 1.3.1991" << endl;
    Date d1 = Date(0, 3, 1991);
    cout << "numeric:  ";
    d1.printNumeric();
    cout << endl;
    cout << "alpha:\t";
    d1.printAlpha();
    cout << endl;
    cout << "-------------------" << endl;
}

void test5()
{
    cout << "5. Invalid Alpha Date: asdf 1,1991 > January 1, 2000" << endl;
    Date d1 = Date("asdf", 1, 1991);
    cout << "numeric:  ";
    d1.printNumeric();
    cout << endl;
    cout << "alpha:\t";
    d1.printAlpha();
    cout << endl;
    cout << "-------------------" << endl;
}

void test6()
{
    cout << "6. Invalid Numeric Date: 2.34.1991 > 2.28.1991" << endl;
    Date d1 = Date(2, 34, 1991);
    cout << "numeric:  ";
    d1.printNumeric();
    cout << endl;
    cout << "alpha:\t";
    d1.printAlpha();
    cout << endl;
    cout << "-------------------" << endl;
}

void test7()
{
    cout << "7. Invalid Numeric Date: 2.34.2000 > 2.29.2000" << endl;
    Date d1 = Date(2, 34, 2000);
    cout << "numeric:  ";
    d1.printNumeric();
    cout << endl;
    cout << "alpha:\t";
    d1.printAlpha();
    cout << endl;
    cout << "-------------------" << endl;
}

void test8()
{
    cout << "8. Invalid Numeric Date: 8.34.2000 > 8.31.2000" << endl;
    Date d1 = Date(8, 34, 2000);
    cout << "numeric:  ";
    d1.printNumeric();
    cout << endl;
    cout << "alpha:\t";
    d1.printAlpha();
    cout << endl;
    cout << "-------------------" << endl;
}

void test9()
{
    cout << "9. Invalid Numeric Date: 8.0.2000 > 8.1.2000" << endl;
    Date d1 = Date(8, 0, 2000);
    cout << "numeric:  ";
    d1.printNumeric();
    cout << endl;
    cout << "alpha:\t";
    d1.printAlpha();
    cout << endl;
    cout << "-------------------" << endl;
}

void test10()
{
    cout << "10. Invalid Alpha day: February 34, 1991 > February 28, 1991" << endl;
    Date d1 = Date("February", 34, 1991);
    cout << "numeric:  ";
    d1.printNumeric();
    cout << endl;
    cout << "alpha:\t";
    d1.printAlpha();
    cout << endl;
    cout << "-------------------" << endl;
}

void test11()
{
    cout << "11. Invalid Alpha day: February 34, 2000 > February 29, 2000" << endl;
    Date d1 = Date("February", 34, 2000);
    cout << "numeric:  ";
    d1.printNumeric();
    cout << endl;
    cout << "alpha:\t";
    d1.printAlpha();
    cout << endl;
    cout << "-------------------" << endl;
}

void test12()
{
    cout << "12. Invalid Alpha day: July 34, 2000 > July 31, 2000" << endl;
    Date d1 = Date("July", 34, 2000);
    cout << "numeric:  ";
    d1.printNumeric();
    cout << endl;
    cout << "alpha:\t";
    d1.printAlpha();
    cout << endl;
    cout << "-------------------" << endl;
}

void test13()
{
    cout << "13. Invalid Alpha day: July 0, 2000 > July 1, 2000" << endl;
    Date d1 = Date("July", 0, 2000);
    cout << "numeric:  ";
    d1.printNumeric();
    cout << endl;
    cout << "alpha:\t";
    d1.printAlpha();
    cout << endl;
    cout << "-------------------" << endl;
}

#if EC

void test14()
{
    int days;
    days = 2000;
    Date d1 = Date(3,23, 2012);
    Date d2 = d1.addDays(days);

    cout << "14. Adding days" << endl;
    cout << "Output should be September 13, 2017\n";
    d1.printAlpha();
    cout << " == " << days << " days ==> ";
    d2.printAlpha();
    cout << endl << "-------------------" << endl;
}

void test15()
{
    int days;
    days = -2000;
    Date d1 = Date(2, 1, 2000);
    Date d2 = d1.addDays(days);

    cout << "15. Subtracting days" << endl;\
    cout << "Output should be August 11, 1994\n";
    d1.printAlpha();
    cout << " == " << days << " days ==> ";
    d2.printAlpha();
    cout << endl << "-------------------" << endl;
}

#endif
