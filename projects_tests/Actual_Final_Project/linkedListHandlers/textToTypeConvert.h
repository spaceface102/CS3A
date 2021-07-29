#ifndef TEXT_TO_TYPE_CONVERT_NAMESPACE_H
#define TEXT_TO_TYPE_CONVERT_NAMESPACE_H

#include "rational.h"
#include "date.h"
#include "complex.h"

namespace textConvert
{
    int toInt(const char* text);
    double toDouble(const char* text);
    const char* toString(const char* text); //no converstion done!
    Rational toRational(const char* text);
    Date toDate(const char* text);
    Complex toComplex(const char* text);
} // namespace textConvert


#endif //TEXT_TO_TYPE_CONVERT_NAMESPACE_H