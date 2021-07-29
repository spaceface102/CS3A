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
 *      The resulting Rational object can either be the default
 *      object created through the default constructor, a 
 *      Rational object with a non default defined numerator,
 *      or a Rational object with user defined numerator and
 *      denominator. This all just depends on the "correctness"
 *      of the input.
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
    long i;                 //PROC - keep last index of text
    long startOfDaysindex;  //PROC - keep the index of the start of day portion
    bool foundToken;        //PROC - used to figure out is token was found

    if (text[0] == '\0' || isDateToken(text[0])) //empty string or just a token
        return Date();
    
    foundToken = false;
    //first get month 
    for (i = 0; text[i] != '\0' && (!foundToken); i++)
    {
        if (isDateToken(text[i]))
            foundToken = true;
    }

    //if foundToken = false
        //text[i] = '\0'
    //if foundToken = true
        //text[i] is the character after a token, which
        //also has the possibility to be end of the string

    //is using spelled out month format
    if (isalpha(text[0]))
        //copy i characters from text and store in monthStr
        //i - 1 if token is found, since ensured that i will
        //be the index of the character after the token.
        monthStr = std::string(text, i - static_cast<int>(foundToken));
    else //assume digits, even if not atoi will return 0
        month = atoi(text);

    //allow for copies of the same token, just skip them
    while (text[i] != '\0' && isDateToken(text[i]))
        i += 1;
    
    //user only input month
    if (text[i] == '\0')
    {
        if (monthStr.size() > 0)
            return Date(monthStr, 1, 2000);
        else
            return Date(month, 1, 2000);
    }


    //get days
    foundToken = false;
    startOfDaysindex = i;
    for(; text[i] != '\0' && (!foundToken); i++)
    {
        if (isDateToken(text[i]))
            foundToken = true;
    }

    //always assume day is numerical
    day = atoi(text + startOfDaysindex);

    //allow for copies of the same token, just skip them
    while (text[i] != '\0' && isDateToken(text[i]))
        i += 1;
    
    //user only input month and day
    if (text[i] == '\0')
    {
        if (monthStr.size() > 0)
            return Date(monthStr, day, 2000);
        else
            return Date(month, day, 2000);
    }


    //get years
    year = atoi(text + i);

    //fully successful return
    if (monthStr.size() > 0)
        return Date(monthStr, day, year);
    else
        return Date(month, day, year);
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
    return  (c == '/') || (c == ',') || (c == ' ')
            || (c == '\\');
}
//EOF