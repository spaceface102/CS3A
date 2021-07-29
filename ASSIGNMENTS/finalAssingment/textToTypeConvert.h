#ifndef TEXT_TO_TYPE_CONVERT_NAMESPACE_H
#define TEXT_TO_TYPE_CONVERT_NAMESPACE_H

/****************************************************************
 * AUTHOR                   : Osbaldo Gonzalez Jr.
 * ASSIGNMENT 10 (FINAL)    : LinkedList GUI
 * CLASS                    : CS 3A
 * SECTION                  : 71206
 * DUE DATE                 : 7/29/2021
****************************************************************/

#include "rational.h"
#include "date.h"
#include "complex.h"
#include <string>

//Using namespace just to organize and have
//a clear place to add more converting functions
//if in the future I decide to support more types
namespace textConvert
{
    int toInt(const char* text);
    double toDouble(const char* text);
    std::string toString(const char* text);
    Rational toRational(const char* text);
    Date toDate(const char* text);
    Complex toComplex(const char* text);
} // namespace textConvert


#endif //TEXT_TO_TYPE_CONVERT_NAMESPACE_H
