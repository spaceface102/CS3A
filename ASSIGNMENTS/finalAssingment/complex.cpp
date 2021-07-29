#include "complex.h"
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <string>

/****************************************************************
 * 
 *  Method Complex: Class Complex   
 * --------------------------------------------------------------
 *  This method revives no arguments, it initializes all
 *  the attributes.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      An object must be instanitated, either a variable or a
 *      simple Complex() default constructor call.
 *  POST-CONDITIONS
 *      The object's attribute will have a default value. 
 *      real = imaginary = magnitude = 0;
****************************************************************/
Complex::Complex(void)
{
    real = 0;
    imaginary = 0;
    magnitude = 0;
}
//EOF

/****************************************************************
 * 
 *  Method Complex: Class Complex   
 * --------------------------------------------------------------
 *  This method revives one argument to set
 *  the realpart, it initializes all
 *  the attributes.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      An object must be instanitated, either a variable or a
 *      simple Complex() default constructor call.
 *  POST-CONDITIONS
 *      The object's attribute will have a default value. 
 *      imaginary = 0
 *      real = passed in realPart
 *      magnitude is calculated accordinly.    
****************************************************************/
Complex::Complex(double realPart)
{
    real = realPart;
    imaginary = 0;
    calculateMagnitude();
}
//EOF

/****************************************************************
 * 
 *  Method Complex: Class Complex   
 * --------------------------------------------------------------
 *  This method revives two arguments to set
 *  the realpart, and the imaginary part. It initializes all
 *  the attributes.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      An object must be instanitated, either a variable or a
 *      simple Complex() default constructor call.
 *  POST-CONDITIONS
 *      The object's attribute will have a default value. 
 *      imaginary = passed in imaginaryPart
 *      real = passed in realPart
 *      magnitude is calculated accordinly.    
****************************************************************/
Complex::Complex(double realPart, double imaginaryPart)
{
    real = realPart;
    imaginary = imaginaryPart;
    calculateMagnitude();
}
//EOF

/****************************************************************
 * 
 *  Method operator=: Class Complex 
 * --------------------------------------------------------------
 *  Checks for equality (exact same position on the cartisian
 *  2D imaginary plane). If eq. returns true, else false.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      There must be two objects, lhs (calling) object, and
 *      a rhs(compared object)
 *  POST-CONDITIONS
 *      Neither of the Complex objects will be modified
****************************************************************/
bool Complex::operator==(const Complex& obj) const
{
    return (real == obj.real) && (imaginary == obj.imaginary);
}
//EOF

/****************************************************************
 * 
 *  Method operator+: Class Complex   
 * --------------------------------------------------------------
 *  Adds to complex numbers together.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      An object must be instanitated, either a variable or a
 *      simple Complex() default constructor call.
 * 
 *  POST-CONDITIONS
 *      A new object is returned, and the objects used to do
 *      the summation are assured to not change state.
****************************************************************/
Complex Complex::operator+(const Complex& obj) const
{
    return Complex(real+obj.real, imaginary+obj.imaginary);
}
//EOF

/****************************************************************
 * 
 *  Method operator-: Class Complex 
 * --------------------------------------------------------------
 *  Subtracts to complex numbers together.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      An object must be instanitated, either a variable or a
 *      simple Complex() default constructor call.
 * 
 *  POST-CONDITIONS
 *      A new object is returned, and the objects used to do
 *      the subtraction are assured to not change state.
****************************************************************/
Complex Complex::operator-(const Complex& obj) const
{
    return Complex(real-obj.real, imaginary-obj.imaginary);
}
//EOF

/****************************************************************
 * 
 *  Method operator*: Class Complex   
 * --------------------------------------------------------------
 *  Multiplies to complex numbers together.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      An object must be instanitated, either a variable or a
 *      simple Complex() default constructor call.
 * 
 *  POST-CONDITIONS
 *      A new object is returned, and the objects used to do
 *      the multiplication are assured to not change state.
****************************************************************/
Complex Complex::operator*(const Complex& obj) const
{
    //(a + bi)(c + di) = (ac - db) + (ad + bc)i
    return Complex( 
        (real*obj.real)      -  (imaginary*obj.imaginary),
        (real*obj.imaginary) +  (imaginary*obj.real)
    ); 
}
//EOF

/****************************************************************
 * 
 *  Method GetReal: Class Complex   
 * --------------------------------------------------------------
 *  Return the real part of calling Complex object.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      An object must be instanitated, either a variable or a
 *      simple Complex() default constructor call.
 * 
 *  POST-CONDITIONS
 *      The object's state is assured not change
****************************************************************/
double Complex::GetReal(void) const
{
    return real;
}
//EOF

/****************************************************************
 * 
 *  Method GetImaginary: Class Complex   
 * --------------------------------------------------------------
 *  Return the imaginary part of calling Complex object.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      An object must be instanitated, either a variable or a
 *      simple Complex() default constructor call.
 * 
 *  POST-CONDITIONS
 *      The object's state is assured not change
****************************************************************/
double Complex::GetImaginary(void) const
{
    return imaginary;
}
//EOF

/****************************************************************
 * 
 *  Method SetReal: Class Complex   
 * --------------------------------------------------------------
 *  Change the real part of calling Complex object.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      An object must be instanitated, either a variable or a
 *      simple Complex() default constructor call.
 * 
 *  POST-CONDITIONS
 *      The object's state is assured to change
****************************************************************/
void Complex::SetReal(double realPart)
{
    real = realPart;
    calculateMagnitude();
}
//EOF

/****************************************************************
 * 
 *  Method SetImaginary: Class Complex   
 * --------------------------------------------------------------
 *  Change the imaginary part of calling Complex object.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      An object must be instanitated, either a variable or a
 *      simple Complex() default constructor call.
 * 
 *  POST-CONDITIONS
 *      The object's state is assured to change
****************************************************************/
void Complex::SetImaginary(double imaginaryPart)
{
    imaginary = imaginaryPart;
    calculateMagnitude();
}
//EOF

/****************************************************************
 * 
 *  Method ExpressionParser: Class Complex   
 * --------------------------------------------------------------
 *  Takes in a std::string an parses it to create a new
 *  Complex object.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Is a static method; no preexisting object required.
 * 
 *  POST-CONDITIONS
 *      A whole new object is returned
****************************************************************/
Complex Complex::ExpressionParser(const std::string& complexString)
{
    double realPart;
    double imaginaryPart;
    std::string number;
    long unsigned int i;
    bool isNegative;
    bool forcedExit;

    forcedExit = false;
    realPart = imaginaryPart = 0;
    number += complexString.at(0);
    for (i = 1; !forcedExit && i < complexString.size(); i++)
    {
        if (complexString.at(i) == '-' || complexString.at(i) == '+'
            || complexString.at(i) == 'i')
        {
            forcedExit = true;
            break;
        }
        else
            number += complexString.at(i);
    }

    if (number.at(0) == 'i' && i == 1)  //only has a complex number
        imaginaryPart = 1;
    else if (forcedExit)  //loop ended early, hit '-', '+', or 'i'
    {
        if (complexString.at(i) == 'i') //complex num start with '-' || number
        {
            if (number.at(0) == '-') //only one char
            {
                if (number.size() == 1) //only have '-' character
                    imaginaryPart = -1;
                else    //actually has numbers 
                    imaginaryPart = std::stod(number);
            }
            else
                imaginaryPart = std::stod(number);
        }
        else //must be either '+' or '-' at complexString[i]
        {
            if (complexString.at(i) == '-')
                isNegative = true;
            realPart = std::stod(number); //first part is realPart
            number.clear();
            //just have to collect imaginary part
            for (i += 1; i < complexString.size(); i++) //+=1 skip '-' or '+'
            {
                if (complexString.at(i) == 'i')
                    break; //end the loop
                number += complexString.at(i);
            }

            imaginaryPart = std::stod(number) *( (isNegative) ? -1 : 1 );
        }
    }
    else    //went through the whole loop, nor '-' or '+' or 'i' appeared
        realPart = std::stod(number);

    return Complex(realPart, imaginaryPart);
}
//EOF

std::ostream& operator<<(std::ostream& out, const Complex& obj)
{
    out << obj.GetReal();
    if (obj.GetImaginary() < 0)
        out << obj.GetImaginary();
    else
        out << '+' << obj.GetImaginary();
    out << 'i';
    return out;
}
//EOF

std::istream& operator>>(std::istream& in, Complex& obj)
{
    std::string complexExpression;  //IN - a+bi or a-bi
    
    in >> complexExpression;
    obj = Complex::ExpressionParser(complexExpression);
    return in;
}
//EOF

void Complex::calculateMagnitude(void)
{
    magnitude = std::sqrt((real*real) + (imaginary*imaginary));
}

/****************************************************************
 * 
 *  Method operator<: Class Complex   
 * --------------------------------------------------------------
 *  Checks if less than (compares magnitude). If 
 *  calling object's magnitude is smaller returns true.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      There must be two objects, lhs (calling) object, and
 *      a rhs(compared object)
 *  POST-CONDITIONS
 *      Neither of the Complex objects will be modified
****************************************************************/
bool Complex::operator<(const Complex& that) const
    {return magnitude < that.magnitude;}
//EOF

/****************************************************************
 * 
 *  Method operator>=: Class Complex   
 * --------------------------------------------------------------
 *  Checks if greater than (compares magnitude). If 
 *  calling object's magnitude is greater return true. It
 *  also checks if they are the exact same point in the imaginary
 *  plane, and if so, will also return true.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      There must be two objects, lhs (calling) object, and
 *      a rhs(compared object)
 *  POST-CONDITIONS
 *      Neither of the Complex objects will be modified
****************************************************************/
bool Complex::operator>=(const Complex& that) const
{
    return (magnitude > that.magnitude) ||
           ((real == that.real) && (imaginary == that.imaginary));
}
//EOF

/****************************************************************
 * 
 *  Method operator>: Class Complex   
 * --------------------------------------------------------------
 *  Checks if greater than (compares magnitude). If 
 *  calling object's magnitude is greater return true.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      There must be two objects, lhs (calling) object, and
 *      a rhs(compared object)
 *  POST-CONDITIONS
 *      Neither of the Complex objects will be modified
****************************************************************/
bool Complex::operator>(const Complex& that) const
    {return magnitude > that.magnitude;}
//EOF
