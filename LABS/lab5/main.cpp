/*****************************************************************************
 * AUTHOR   : Osbaldo Gonzalez Jr. && George Vong
 * LAB #7   : Distance Class
 * CLASS    : CS 3A
 * SECTION  : 71206
 * DUE DATE : 6/29/2021
*****************************************************************************/
#include <iostream>
using namespace std;
#include "distance.h"
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
int main()
{
  Distance d1;
  cout << "d1: ";
  d1.display(); cout << endl;
  Distance d2 = Distance(2, 5.9);
  Distance d3 = Distance(3.75);
  cout << "d2: "; d2.display(); cout << endl;
  cout << "d3: "; d3.display(); cout << endl;

  //test init helper function
  Distance d4 = Distance(5, 19.34);
  Distance d5 = Distance(100);
  cout << "d4: "; d4.display(); cout << endl;
  cout << "d5: "; d5.display(); cout << endl;

  //test add (<12 inches)
  cout << "d4 + d5: "; (d4 + d5).display(); cout << endl;
  //test add (>12 inches)
  cout << "d2 + d4: "; (d2 + d4).display(); cout << endl;

  //test sub (0 ft)
  cout << "d3 - d1: "; (d3 - d1).display(); cout << endl;
  //test sub (0 ft, negative conversion)
  cout << "d1 - d3: "; (d1 - d3).display(); cout << endl;

  //test sub (positive ft & inch)
  cout << "d4 - d2: "; (d4 - d2).display(); cout << endl;
  //test sub (negative ft & inch)
  cout << "d2 - d4: "; (d2 - d4).display(); cout << endl;

  //test sub (negative ft, positive inch)
  cout << "d4 - d5: "; (d4 - d5).display(); cout << endl;
  //test sub (positive ft, negative inch)
  cout << "d5 - d2: "; (d5 - d2).display(); cout << endl;


  //add more tests of your own ...

  return 0;
}