#include "complex.h"
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <string>

Complex::Complex(void)
{
    real = 0;
    imaginary = 0;
    magnitude = 0;
}
//EOF

Complex::Complex(double realPart)
{
    real = realPart;
    imaginary = 0;
    calculateMagnitude();
}
//EOF

Complex::Complex(double realPart, double imaginaryPart)
{
    real = realPart;
    imaginary = imaginaryPart;
    calculateMagnitude();
}
//EOF

bool Complex::operator==(const Complex& obj) const
{
    return (real == obj.real) && (imaginary == obj.imaginary);
}
//EOF

Complex Complex::operator+(const Complex& obj) const
{
    return Complex(real+obj.real, imaginary+obj.imaginary);
}
//EOF

Complex Complex::operator-(const Complex& obj) const
{
    return Complex(real-obj.real, imaginary-obj.imaginary);
}
//EOF

Complex Complex::operator*(const Complex& obj) const
{
    //(a + bi)(c + di) = (ac - db) + (ad + bc)i
    return Complex( 
        (real*obj.real)      -  (imaginary*obj.imaginary),
        (real*obj.imaginary) +  (imaginary*obj.real)
    ); 
}
//EOF

double Complex::GetReal(void) const
{
    return real;
}
//EOF

double Complex::GetImaginary(void) const
{
    return imaginary;
}
//EOF

void Complex::SetReal(double realPart)
{
    real = realPart;
    calculateMagnitude();
}
//EOF

void Complex::SetImaginary(double imaginaryPart)
{
    imaginary = imaginaryPart;
    calculateMagnitude();
}
//EOF

Complex Complex::ExpressionParser(const std::string& complexString)
{
    double realPart;
    double imaginaryPart;
    std::string number;
    int i;
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

bool Complex::operator<(const Complex& that) const
    {return magnitude < that.magnitude;}
//EOF

bool Complex::operator>=(const Complex& that) const
{
    return (magnitude > that.magnitude) ||
           ((real == that.real) && (imaginary == that.imaginary));
}
//EOF

bool Complex::operator>(const Complex& that) const
    {return magnitude > that.magnitude;}
//EOF