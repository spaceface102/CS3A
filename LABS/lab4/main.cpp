/*****************************************************************************
 * AUTHOR   : Osbaldo Gonzalez Jr. && George Vong
 * LAB #4   : Rational Class
 * CLASS    : CS 3A
 * SECTION  : 71206
 * DUE DATE : 6/28/2021
*****************************************************************************/

#include "rational.h"
#include <iostream>

/*************************************************************************** *    
 * Distance Handler using classes
 *______________________________________________________________________________
 * This program further continue to practice the use of classes
 * and also allows us to practice operator overloading. The classes
 * handles length with two private attributes: inches and feet.
 *______________________________________________________________________________
 *  INPUT:
 *      none (everything is hard coded)
 *  OUTPUT:
 *      std::cout (no use of variables)
*****************************************************************************/
int main(void)
{
    //OUTPUT - based on what the Rational object is, such as making an object 
    //         with the default constructor
    std::cout << "Testing default constructor.\n";
    Rational().display(); 
    std::cout << "\n\n"; //spacer

    std::cout << "Testing one argument constructor with 5 as the argument.\n";
    Rational(5).display();
    std::cout << "\n\n"; //spacer

    std::cout << "Testing two argument constructor with (2,3) as the argument.\n";
    Rational(2,3).display();
    std::cout << "\n\n"; //spacer

    std::cout << "Testing add function by adding 5 and 2/3.\n";
    Rational(5).add(Rational(2,3)).display();
    std::cout << "\n\n"; //spacer

    std::cout << "Testing subtract function by subtracting 5 and 2/3.\n";
    Rational(5).subtract(Rational(2,3)).display();
    std::cout << "\n\n"; //spacer

    std::cout << "Testing multiply function by multiplying 5 and 2/3.\n";
    Rational(5).multiply(Rational(2,3)).display();
    std::cout << "\n\n"; //spacer

    std::cout << "Testing divide function by dividing 5 and 2/3.\n";
    Rational(5).divide(Rational(2,3)).display();
    std::cout << "\n"; //spacer


    std::cout << "\n\n\n\n\n\n\n\n";
    Rational(3, 4).add(Rational(4)).display();
    return 0;
}