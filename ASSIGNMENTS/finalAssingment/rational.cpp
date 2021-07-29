#include "rational.h"
#include <iostream>


/****************************************************************
 * 
 *  Method Rational: Class Rational  //Constructor
 * --------------------------------------------------------------
 *  This method revives no arguments, it initializes all
 *  the attributes.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      An object must be instanitated, either a variable or a
 *      simple Rational() default constructor call.
 *  POST-CONDITIONS
 *      The object's attribute will have a default value. 
 *      numer = 0, denom = 1;
****************************************************************/
Rational::Rational()
{
    numer = 0;
    denom = 1;
}
//EOF

/****************************************************************
 * 
 *  Method Rational: Class Rational  //Constructor
 * --------------------------------------------------------------
 *  This method revives one argument, it initializes all
 *  the attributes. The argument passed in sets the numer
 *  attribute of the new object
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      An object must be instanitated, either a variable or a
 *      simple Rational(number) call with one arg
 *  POST-CONDITIONS
 *      The object's attribute will be set as the following: 
 *      numer = numerator int arg
 *      denom = 1;
****************************************************************/
Rational::Rational(int numerator //IN - numerator to be used for new object
                    )
{
    numer = numerator;
    denom = 1;
}
//EOF


/****************************************************************
 * 
 *  Method Rational: Class Rational  //Constructor
 * --------------------------------------------------------------
 *  This method revives two arguments. The first arg sets the
 *  value of numer for the new object and the second arg set the 
 *  value of denom for the new object as well
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      An object must be instanitated, either a variable or a
 *      simple Rational(number1, number2) call with two args
 *  POST-CONDITIONS
 *      The object's attribute will be set as the following: 
 *      numer = numerator int arg
 *      denom = denominator int arg;
****************************************************************/
Rational::Rational(int numerator,   //IN - numerator to be used for new object
                   int denominator  //IN - denominator to be used for new obj
                )
{
    numer = numerator;
    denom = denominator;
    euclidGCD();
}
//EOF


/****************************************************************
 * 
 *  Method add: Class Rational
 * --------------------------------------------------------------
 * This method recives one argument, a Rational object.
 * The object is passed by constant reference. The operation
 * done in addition
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      An object must be instanitated, in order to call the 
 *      method. The passed in Rational object should also already
 *      have values for numer and denom.
 *  POST-CONDITIONS
 *      Nor the calling or the passed in object will be modified
 *      in any sort of way. A new Rational object is created, and
 *      that is what is returned.
****************************************************************/
const Rational Rational::add(const Rational &rational//IN - Rational Object
                            ) const
{
    return Rational(
        (numer*rational.denom) + (denom*rational.numer),
        (denom*rational.denom)
    );
}
//EOF

/****************************************************************
 * 
 *  Method subtract: Class Rational
 * --------------------------------------------------------------
 * This method recives one argument, a Rational object.
 * The object is passed by constant reference. The operation done
 * is subtraction
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      An object must be instanitated, in order to call the 
 *      method. The passed in Rational object should also already
 *      have values for numer and denom.
 *  POST-CONDITIONS
 *      Nor the calling or the passed in object will be modified
 *      in any sort of way. A new Rational object is created, and
 *      that is what is returned.
****************************************************************/
const Rational Rational::subtract(const Rational &rational//IN - Rational Object
                                ) const
{
    return Rational(
        (numer*rational.denom) - (denom*rational.numer),
        (denom*rational.denom)
    );
} 
//EOF

/****************************************************************
 * 
 *  Method multiply: Class Rational
 * --------------------------------------------------------------
 * This method recives one argument, a Rational object.
 * The object is passed by constant reference. The operation done
 * is multiplication
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      An object must be instanitated, in order to call the 
 *      method. The passed in Rational object should also already
 *      have values for numer and denom.
 *  POST-CONDITIONS
 *      Nor the calling or the passed in object will be modified
 *      in any sort of way. A new Rational object is created, and
 *      that is what is returned.
****************************************************************/
const Rational Rational::multiply(const Rational &rational//IN - Rational Object
                                ) const
{
    /*
    3     7     21
    -- * --  =  --
    2     5     10
    */
   return Rational(
       (numer*rational.numer),
       (denom*rational.denom)
   );
}

/****************************************************************
 * 
 *  Method divide: Class Rational
 * --------------------------------------------------------------
 * This method recives one argument, a Rational object.
 * The object is passed by constant reference. The operation done
 * is division
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      An object must be instanitated, in order to call the 
 *      method. The passed in Rational object should also already
 *      have values for numer and denom.
 *  POST-CONDITIONS
 *      Nor the calling or the passed in object will be modified
 *      in any sort of way. A new Rational object is created, and
 *      that is what is returned.
****************************************************************/
const Rational Rational::divide(const Rational &rational//IN - Rational Object
                                ) const
{
    /*
    3     7     3     5     15
    -- / --  =  -- *  -- =  --
    2     5     2     7     14
    */
   return multiply(Rational(rational.denom, rational.numer));
}

/****************************************************************
 * 
 *  Method display: Class Rational
 * --------------------------------------------------------------
 * This method has no passed in arguments. It simply displays
 * the two private attributes for numerator and denominator 
 * in a fromated fashion: numerator/denominator
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      An object must be instantiated with valid numerator and
 *      denominator values.
 *  POST-CONDITIONS
 *      The output goes to std::cout, it does not return any
 *      sort of string related to formated output. There is 
 *      no way to get the fromated values from any other method
 *      so you are stuck just printing to the console.
****************************************************************/
void Rational::display() const
{
    std::cout << numer << "/" << denom;
}

void Rational::euclidGCD(void)
{
    int r;  //PROC - remainder
    int n;  //PROC - dividened
    int m;  //PROC - divisor

    n = numer;
    m = denom;
    r = n%m;
    while (r != 0)
    {
        n = m;
        m = r;
        r = n%m;
    }

    //simplify fraction
    numer /= m;
    denom /= m;
}
//EOF

bool Rational::operator<(const Rational& that) const
    {return (numer * that.denom) < (that.numer * denom);}
//EOF

bool Rational::operator>=(const Rational& that)const
    {return (numer * that.denom) >= (that.numer * denom);}
//EOF

bool Rational::operator>(const Rational& that) const
    {return (numer * that.denom) > (that.numer * denom);}
//EOF

bool Rational::operator==(const Rational& that) const
    {return (numer * that.denom) == (that.numer * denom);}
//EOF

std::ostream& operator<<(std::ostream& out, const Rational obj)
{
    out << obj.numer << "/" << obj.denom;
    return out;
}
//EOF