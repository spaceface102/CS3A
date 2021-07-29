#ifndef TEXT_TO_TYPE_CONVERT_NAMESPACE_H
#define TEXT_TO_TYPE_CONVERT_NAMESPACE_H

#include "rational.h"
#include "date.h"
#include "complex.h"
#include <string>

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
