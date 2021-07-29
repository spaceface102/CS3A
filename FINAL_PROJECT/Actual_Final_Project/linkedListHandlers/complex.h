#ifndef COMPLEX_CLASS_H
#define COMPLEX_CLASS_H

#include <iostream>

class Complex
{
private:
    double real;        //IN - real_part of complex number (a)
    double imaginary;   //IN - imaginary part of complex number (b)

public:
    /*****************************
    ** CONSTRUCTOR & DESTRUCTOR **
    *****************************/
    Complex(void);
    Complex(double realPart);
    Complex(double realPart, double imaginaryPart);

    /***************
    **  CREATORS  ** //makes a new object and returns that object
    ***************/
    bool operator==(const Complex& obj) const;
    Complex operator+(const Complex& obj) const;
    Complex operator-(const Complex& obj) const;
    Complex operator*(const Complex& obj) const;

    /**************
    ** ACCESSORS **
    **************/
    double GetReal(void) const;
    double GetImaginary(void) const;

    /*************
    ** MUTATORS **
    *************/
    void SetReal(double realPart);
    void SetImaginary(double imaginaryPart);

    /**************
    **  HELPERS  **
    **************/
    static Complex ExpressionParser(const std::string& complexString);


//ADDITIONS FOR FINAL ASSIGNMENT
private: //extra fields
    double magnitude;


public: 
    //necessary overloads for select_sort, insert_sorted and remove
    //duplicates from the templated LinkedList class (I created)
    void calculateMagnitude(void); //used to be able to do comparisons
    bool operator<(const Complex& that) const;
    bool operator>=(const Complex& that) const;
    bool operator>(const Complex& that) const;
};

//CONSTANTS
const Complex i(0,1);
//EOC

//Decided to not make friend function, just use accessors and mutator.
std::ostream& operator<<(std::ostream& out, const Complex& obj);
std::istream& operator>>(std::istream& in, Complex& obj);

#endif
//COMPLEX_CLASS_H