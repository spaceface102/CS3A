#include "distance.h"
#include <iostream>
#include <cmath>  //for fmod()
/****************************************************************
 * 
 *  Method Distance: Class Distance //Constructor(void)
 * --------------------------------------------------------------
 * This method is the default constructor. It sets both the
 * values of feet and inches to 0. 
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      An object must be instanitated, either a variable or a
 *      simple Distance() default constructor call.
 *  POST-CONDITIONS
 *      The new object's priavte attribute are always going
 *      to be set to feet = 0, and inches = 0.0
****************************************************************/
Distance::Distance()
{
  feet = 0;
  inches = 0.0;
}
//EOF

/****************************************************************
 * 
 *  Method Distance: Class Distance //Constructor(int, double)
 * --------------------------------------------------------------
 * This method is a constructor. It takes two arguments, 
 * unsigned ft (feet arg), and double inch. It will automatically
 * reformat the values if inches >= 12.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      An object must be instanitated. Args must be passed in
 *      order, such that the first (left most arg) is related
 *      to feet, and then next arg is related to inches.
 *  POST-CONDITIONS
 *      The private attribute inches will always be greater than
 *      or equal to 0.0 and less than 12.0. The private attribute
 *      feet is limited to the max value an unsigned int can hold
 *      on your system, usually 2**32 -1.
****************************************************************/
Distance::Distance(unsigned ft, //
                   double inch  //
                  )
{
  feet = ft;
  inches = inch;
  init();
}
//EOF

/****************************************************************
 * 
 *  Method Distance: Class Distance //Constructor(double)
 * --------------------------------------------------------------
 * This method is a constructor. It takes one argument, double
 * inch, which is used to set both the inches value and the 
 * feet value.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      An object must be instanitated. An argument must also be
 *      passed; it will be treated as the inches value.
 *  POST-CONDITIONS
 *      The private attribute inches will always be greater than
 *      or equal to 0.0 and less than 12.0. The private attribute
 *      feet is limited to the max value an unsigned int can hold
 *      on your system, usually 2**32 -1.
****************************************************************/
Distance::Distance(double inch  //
                  )
{
  feet = 0; //have to init or else garbage
  inches = inch;
  init();
}
//EOF

/****************************************************************
 * 
 *  Method converttoInches: Class Distance
 * --------------------------------------------------------------
 *  This method returns the object's length in only inches.
 *  Aka, feet*12.0 + inches
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      An object must be instanitated, in order to call the 
 *      method. The private methods should all be initlized
 *      before calling this method. Really useful and 
 *      integral to the code.
 *  POST-CONDITIONS
 *      The return value is a double, so the bigger the
 *      return value is, the less it's trust worthy, and becomes
 *      more and more of an aproximation (this is just due to 
 *      it being a floating point). Should be fine for most 
 *      values none the less. 
****************************************************************/
double Distance::convertToInches() const
{
  return feet*12.0 + inches;
}
//EOF

/****************************************************************
 * 
 *  Method init: Class Distance //PRIVATE //HELPER
 * --------------------------------------------------------------
 *  This method ensures that the formating of the numerical values
 *  is correct. inches < 12, and both values are not negative.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      An object must be instanitated, and only the calling
 *      object's attributes will be modified. This is a 
 *      private method!
 *  POST-CONDITIONS
 *      The the private attributes, inches and feet, are both
 *      assured to be positive, and the inches is also assured
 *      to be less then 12
****************************************************************/
void Distance::init()
{
  if ((int)feet < 0)
    feet = -1*feet; //or can do ~(feet) + 1 (2s comp)
  if (inches < 0.0)
    inches = -1.0*inches;
  
  //fmod used to get remainder of a double inches
  feet += ( inches - (fmod(inches, 12.0)) )/12;
  inches = fmod(inches, 12);
}
//EOF

/****************************************************************
 * 
 *  Method Distance operator+: Class Distance
 * --------------------------------------------------------------
 * This method defines what happens when two Distance objects
 * use the binary addition operator. It sums up the lenghts of 
 * both and returns a new object
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      This is not a unarary addition, there must be two objects.
 *  POST-CONDITIONS
 *      Both the objects are assured to not be modified. A new 
 *      object will be returned, and their values are ensured
 *      to meet with the previous specifications: inches >= 0.0
 *      feet >= 0 and inches < 12,0
****************************************************************/
const Distance Distance::operator+(const Distance &obj //
                                  ) const
{
  return Distance(convertToInches() + obj.convertToInches());
}
//EOF

/****************************************************************
 * 
 *  Method Distance operator-: Class Distance
 * --------------------------------------------------------------
 * This method defines what happens when two Distance objects
 * use the binary subtraction operator. It subtracts the lenghts of 
 * both and returns a new object.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      This is not a unarary subtraction, there must be two objects.
 *  POST-CONDITIONS
 *      Both the objects are assured to not be modified. A new 
 *      object will be returned, and their values are ensured
 *      to meet with the previous specifications: inches >= 0.0
 *      feet >= 0 and inches < 12,0.
 *      Note: even though with subtraction, there is the posibility
 *      of negative length, it is automatically converted to a 
 *      positive value.
****************************************************************/
const Distance Distance::operator-(const Distance &obj //
                                  ) const
{
  return Distance(convertToInches() - obj.convertToInches());
}
//EOF

/****************************************************************
 * 
 *  Method display: Class Distance
 * --------------------------------------------------------------
 * This method has no passed in arguments. It simply displays
 * the two private attributes for feet and inches
 * in a fromated fashion: feet' inches"
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      An object must be instantiated with valid feet and
 *      inch values.
 *  POST-CONDITIONS
 *      The output goes to std::cout, it does not return any
 *      sort of string related to formated output. There is 
 *      no way to get the fromated values from any other method
 *      so you are stuck just printing to the console.
****************************************************************/
void Distance::display() const
{
    std::cout << feet << "' " << inches << "\"";
}
//EOF