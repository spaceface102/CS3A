#ifndef COMPLEX_CLASS_H
#define COMPLEX_CLASS_H

#include <iostream>

class Complex
{
private:
    double real;        //IN - real_part of complex number (a)
    double imaginary;   //IN - imaginary part of complex number (b)

public:
    Complex(void);
    Complex(double realPart);
    Complex(double realPart, double imaginaryPart);

    bool operator==(const Complex& obj) const;
    Complex operator+(const Complex& obj) const;
    Complex operator-(const Complex& obj) const;
    Complex operator*(const Complex& obj) const;

    double GetReal(void) const;
    double GetImaginary(void) const;

    void SetReal(double realPart);
    void SetImaginary(double imaginaryPart);

    static Complex ExpressionParser(const std::string& complexString);
};

//CONSTANTS
const Complex i(0,1);
//EOC

//Decided to not make friend function, just use accessors and mutator.
std::ostream& operator<<(std::ostream& out, const Complex& obj);
std::istream& operator>>(std::istream& in, Complex& obj);

#endif
//COMPLEX_CLASS_H