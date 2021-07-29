#ifndef CLASS_RATIONAL_H
#define CLASS_RATIONAL_H

#include <iostream>
class Rational
{
private:
    int numer;  //IN/OUT -  numerator integer value
    int denom;  //IN/OUT -  denominator integer value

public:
    /******************************
     ** CONSTRUCTOR & DESTRUCTOR **
    ******************************/
    Rational();         //default constructor
    Rational(int);      //constructor, takes in numerator
    Rational(int, int); //constructor, takes in numerator and denominator
   
    /***************
     ** CREATORS ** //makes a new object and returns that object
     ***************/
    const Rational add(const Rational &) const; 
    const Rational subtract(const Rational &) const; 
    const Rational multiply(const Rational &) const; 
    const Rational divide(const Rational &) const; 

    /***************
     ** ACCESSORS **
     ***************/
    void display() const;

//ADDITIONS FOR FINAL ASSIGNMENT
private:
    /**************
    **  HELPERS  **
    **************/
    void euclidGCD(void);


public: 
    //necessary overloads for select_sort, insert_sorted and remove
    //duplicates from the templated LinkedList class (I created)
    bool operator<(const Rational& that) const;
    bool operator>=(const Rational& that)const;
    bool operator>(const Rational& that) const;
    bool operator==(const Rational& that) const;
    friend std::ostream& operator<<(std::ostream& out, const Rational obj);
}; 
#endif //CLASS_RATIONAL_H

/****************************************************************
 * Rational Class
 *  This class represents a rational number. It manages two
 *  attributes, numer, and denom.
****************************************************************/

/******************************
 ** CONSTRUCTOR & DESTRUCTOR **
******************************/
/****************************************************************
 * Rational();
 *  Default constructor; Initialize class attributes, numer = 0,
 *  denom = 1.
 *  Parameters: none
 *  Return: none
****************************************************************/

/****************************************************************
 * Rational(int);
 *  Default constructor; Initialize class attributes, numer =
 *  int numerator paramter, denom = 1.
 * --------------------------------------------------------------
 *  Parameters: int numerator   //in for new numerator
 * --------------------------------------------------------------
 *  Return: none
****************************************************************/

/****************************************************************
 * Rational(int, int);
 *  Default constructor; Initialize class attributes, numer =
 *  int numerator paramter, denom = int denominator paramter.
 * --------------------------------------------------------------
 *  Parameters: int numerator   //in for new numerator
 *              int denominator //in for new denominator
 * --------------------------------------------------------------
 *  Return: none
****************************************************************/

/***************
 ** CREATORS ** //makes a new object and returns that object
***************/
/****************************************************************
 * const Rational add(const Rational &) const;
 *  Creator; This method will create a whole new object to
 *  return, this new Rational object will contain numer and denom
 *  based on the passed in Rational object and the calling object.
 *  The operation being done is ADDING
 * --------------------------------------------------------------
 *  Paramter: const Rational &rational_object //IN - holds all
 *                                            //information needed
 *                                            //to do add operation
 * --------------------------------------------------------------
 *  Return: new Rational object with the new calculated values
****************************************************************/

/****************************************************************
 * const Rational subtract(const Rational &) const;
 *  Creator; This method will create a whole new object to
 *  return, this new Rational object will contain numer and denom
 *  based on the passed in Rational object and the calling object.
 *  The operation being done is SUBTRACTING
 * --------------------------------------------------------------
 *  Paramter: const Rational &rational_object //IN - holds all
 *                                            //information needed
 *                                            //to do add operation
 * --------------------------------------------------------------
 *  Return: new Rational object with the new calculated values
****************************************************************/

/****************************************************************
 * const Rational multiply(const Rational &) const;
 *  Creator; This method will create a whole new object to
 *  return, this new Rational object will contain numer and denom
 *  based on the passed in Rational object and the calling object.
 *  The operation being done is MULTIPLYING
 * --------------------------------------------------------------
 *  Paramter: const Rational &rational_object //IN - holds all
 *                                            //information needed
 *                                            //to do add operation
 * --------------------------------------------------------------
 *  Return: new Rational object with the new calculated values
****************************************************************/

/****************************************************************
 * const Rational divide(const Rational &) const;
 *  Creator; This method will create a whole new object to
 *  return, this new Rational object will contain numer and denom
 *  based on the passed in Rational object and the calling object.
 *  The operation being done is DIVIDING
 * --------------------------------------------------------------
 *  Paramter: const Rational &rational_object //IN - holds all
 *                                            //information needed
 *                                            //to do add operation
 * --------------------------------------------------------------
 *  Return: new Rational object with the new calculated values
****************************************************************/


/***************
 ** ACCESSORS **
***************/
/****************************************************************
 * void display() const; 
 *  Accessor; This method will print out the formated rational
 *  number
 * --------------------------------------------------------------
 *  Paramter: none
 * --------------------------------------------------------------
 *  Return: none (fromated output to std::cout)
****************************************************************/