/*****************************************************************************
 * AUTHOR   : Osbaldo Gonzalez Jr. && William Ho
 * LAB #1   : Roman Numerals
 * CLASS    : CS 3A
 * SECTION  : 71206
 * DUE DATE : 6/21/2021
*****************************************************************************/

#include <iostream>
#include <string>

using namespace std;

/*****************************************************************************
*
* CONVERTING ROMAN NUMERALS
*_________________________________________________
*  This program converts a positive integer into
*  Roman numerals, or standard numbers into Roman
*  numerals.
*_________________________________________________
* INPUT:
*  int option: Let's the user decide whether they want
*          convert a standard number to Roman
*          Roman numerals, or vice versa.
*  int number: A standard number the user enters to
*          convert to Roman numerals.
*  string roman: A Roman numeral the user enters
*          to convert to a standard number.
*
* OUTPUT:
*   roman_to_int() return value:
*       return value according to the user defined "number"
*       int variable, that should be a base 10 "normal" number
*   int_to_roman() return value:
*       return value according to the user defined "roman"
*       string variable, which is a Roman Number
******************************************************************************/


// FUNCTION PROTOTYPES
/*****************************************************************************
 * roman_to_int()
 *  This function receives a roman number string, can be more than one character,
 *	and returns a "normal" base 10 integer number
 
 * get_roman_digit()
 *  This function receives a roman digit and converts it to its corresponding integer
 * 
 * int_to_roman()
 *  This function receives an integer number and converts it into a roman number string
 * 
 * roman_digit()
 *  This function is used by the int_to_roman() function.
 *  It recives the parsed digits (separated by digit place
 *  such as 10s, 100s, etc.) and converts the passed in number 
 *  to a valid roman digit, defined by the passed in roman digits strings.
*****************************************************************************/
int roman_to_int(const string &roman);
int get_roman_digit(char roman_digit);
string int_to_roman(int number);
string roman_digit(int n, const string &onedigit, const string &fourdigit,
                   const string &fivedigit, const string &ninedigit);

int main()
{
    int option; //INPUT - used to decide menu options for conversion
    cout  
    << "Type 1 for standard -> Roman numeral conversion. \n" 
    << "Type 2 for Roman numeral -> Standard numeral conversion.";
    
    
    cin >> option;
    if (option == 1)
    {
        int number; //INPUT - The standard number entered by the user
        cout << "Enter standard number to convert: ";
        cin >> number;

        if (number > 3999 || number < 1)
            cout << "invalid\n";
        else
            cout << int_to_roman(number) << "\n";  
    }
    else if(option == 2)
    {
        string roman; //INPUT - The Roman numeral entered by the user
        cout << "Enter Roman numeral to convert: \n";
        cin >> roman;

        int c = roman_to_int(roman);
        if (int_to_roman(c) != roman)
            cout << "invalid\n";
        else
            cout << c << "\n";
    }

    return 0;
    /*
    EXTRA TEST TO SEE IF EVERYTHING IS WOKRING
    string roman_value;
    for (int i = 1; i < 4000; i++)
    {
        roman_value = int_to_roman(i);
        if (i != roman_to_int(roman_value))
            cout << "OOPS: " << i << "\n";
    }
    */
}
//EOF

/******************************************************************************
 * FUNCTION roman_to_int
 *________________________________________________
 *  The function takes in a roman numeral
 *  string entered by the user, and returns
 *  the convereted integer value of the roman numeral
 *________________________________________________
 * PRE-CONDITIONS
 * The following needs previous defined values:
 * roman, the roman numeral string, defined by the user
 *
 * POST-CONDITIONS
 * The return value will always be an integer, and 
 * along with that, it will always be a positive integer
 * 
/****************************************************************************/
int roman_to_int(const string &roman)
{
    int total = 0;
    int current_roman_digit, next_roman_digit;
    for (unsigned long int i = 0; i < (roman.size() - 1); i++)
    {
        current_roman_digit = get_roman_digit(roman[i]);
        next_roman_digit = get_roman_digit(roman[i+1]);
        if (current_roman_digit < next_roman_digit)
            total -= current_roman_digit;
        else
            total += current_roman_digit;
    }
    total += get_roman_digit(roman[roman.size()-1]);
    return total;
}
//EOF

/******************************************************************************
 * FUNCTION get_roman_digit
 *________________________________________________
 * The function takes in a single roman_digit as a char
 * and evaluates it to it's integer value, such as C = 100
 * and V = 5, etc.
 *________________________________________________
 * PRE-CONDITIONS
 * The passed in digit must be a char, and therefore, you can
 * only pass in one character at a time
 * POST-CONDITIONS
 * The return value is guaranteed to be between 1 and 1000
 * inclusive, unless it is an invalid input in which case
 * the output is 0. 
/****************************************************************************/
int get_roman_digit(char roman_digit)
{
    switch (roman_digit)
    {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            cout << "Invalid Numeral";
            return 0; 
    }
}
//EOF


/******************************************************************************
 * FUNCTION int_to_roman
 *________________________________________________
 * The function receives a standard number 
 *  entered by the user and determines the
    corresponding roman numeral 
 * PRE-CONDITIONS
 * The following needs previous defined values:
 * number: user inputted standard number
 *
 * POST-CONDITIONS
 * The maximum roman numeral outputted can be up to MMMCMXCIX 
 *
/****************************************************************************/
string int_to_roman(int number)
{
    //Parse number into it's digits
    int ones_place, tens_place, hundreds_places, thousands_place;
    ones_place = number%10; number /= 10;
    tens_place = number%10; number /= 10;
    hundreds_places = number%10; number /= 10;
    thousands_place = number%10; number /= 10;
    
    //Convertion to roman
    string roman;
    for (int i = 0; i < thousands_place; i++)
        roman += 'M';
    roman += roman_digit(hundreds_places, "C", "CD", "D", "CM");
    roman += roman_digit(tens_place, "X", "XL", "L", "XC");
    roman += roman_digit(ones_place, "I", "IV", "V", "IX");

    return roman;
}
//EOF

/******************************************************************************
 * FUNCTION roman_digit
 *________________________________________________
 * The function takes in a integer value between 0 to 9
 * which is a digit 
 *________________________________________________
 * PRE-CONDITIONS
 * The passed in digit must be a char, and therefore, you can
 * only pass in one character at a time
 * If a non valid numeral is passed in, it will simply return 0
 * POST-CONDITIONS
 * The result will, at maximum, have three times the characters in
 * in the onedigit parameter plus the characters found in the
 * fivedigit parameter
 * 
/****************************************************************************/
string roman_digit(int n, const string &onedigit, const string &fourdigit,
                   const string &fivedigit, const string &ninedigit)
{
    string result = "";

    if (n == 9)
    {
        result += ninedigit;
        n -= 9;
    }
    else if (n >= 5)
    {
        result += fivedigit;
        n -= 5;
        for (int i = 0; i < n; i++)
            result += onedigit;
    }
    else if (n == 4)
    {
        result += fourdigit;
        n -= 4;
    }
    else
    {
        for (int i = 0; i < n; i++)
            result += onedigit;
    }

    return result;
}