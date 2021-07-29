#include "textToTypeConvert.h"
#include <cstdlib>
#include <string>
#include <cctype>
#include <cstring>

//Function Prototypes 
static bool isRationalToken(char c);
static bool isDateToken(char c);

int textConvert::toInt(const char* text)
{
    //atoi will return 0 if empty string
    return atoi(text);
    //also stops as soon as it reaches invalid
    //non numeric char! (left to right)
}
//EOF

double textConvert::toDouble(const char* text)
{
    return atof(text); //atof will return 0 if empty string
    //also stops as soon as it reaches invalid
    //non numeric char! (left to right)
}
//EOF

const char* textConvert::toString(const char* text) //no converstion done!
{
    return text;
}
//EOF

/****************************************************************
 * 
 *  Function toRational: Namespace textConvert
 * --------------------------------------------------------------
 *  This function takes a cstring and parses it for numerator
 *  and denominator. Returns a Rational object with said numerator
 *  and denominator.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Passed in cstring MUST have a null terminainting
 *      character.
 *      Allows for either '\\' or '/' as seperating characters,
 *      where they can also be more than one seperating characters
 *      back to back.
 *  POST-CONDITIONS
 *      
****************************************************************/
Rational textConvert::toRational(const char* text)
{
    int numerator;          //PROC - used for Rational object init
    int denominator;        //PROC - used for Rational object init
    long i;                 //PROC - keep last index of text
    bool foundToken;        //PROC - used to figure out is token was found

    //empty string or no numerator
    if (text[0] == '\0' || isRationalToken(text[0]))
        return Rational(); //default object


    foundToken = false;
    for (i = 0; text[i] != '\0' && (!foundToken); i++)
    {
        if (isRationalToken(text[i]))
            foundToken = true;
        else if (!isdigit(text[i]))
            return Rational(); //invalid input
    }

    //if foundToken = false
        //text[i] = '\0' and all chars in text are digits
    //if foundToken = true
        //text[i] is the character after a token, which
        //also has the possibility to be end of the string
        //but also assured all chars in text previous to the
        //token were valid digits

    //if text did not have a valid token, then atoi runs as
    //expected, if it did, atoi retturns an integer representation
    //of all the characters before the token.
    numerator = atoi(text);

    //allow duplicate tokens
    while (text[i] != '\0' && isRationalToken(text[i]))
        i += 1;

    //assured that there is no denomiantor
    if (text[i] == '\0')
        return Rational(numerator);

    //might have a valid denomiantor, if not numeric, atoi returns 0
    denominator = atoi(text + i);

    //ensure denominator is not zero
    denominator = (denominator == 0) ? 1 : denominator;
    return Rational(numerator, denominator);
}
//EOF

Date textConvert::toDate(const char* text)
{
    unsigned day;           //STORE - used to init Date object;s day
    unsigned month;         //STORE - used to init Date object's month
    std::string monthStr;   //STORE - used in case input is spelled out
    unsigned year;          //STORE - used to init Date object's year

    if (text[0] == '\0') //empty string
        return Date();
}
//EOF

Complex textConvert::toComplex(const char *text)
{
    return Complex::ExpressionParser(text);
}
//EOF

//decided not to include these functions in the textConvert
//namespace just to reduce the api and keep these functions
//restrected to this file.
static bool isRationalToken(char c)
{
    return (c == '/') || (c == '\\');
}
//EOF

static bool isDateToken(char c)
{
    return  (c == '/') || (c == '\\') || (c == ' ')
            || (c == ',');
}
//EOF