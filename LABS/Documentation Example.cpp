
/*****************************************************************************
 * AUTHOR   : Juan Leon
 * LAB #1   : Roman Numerals
 * CLASS    : CS 3A
 * SECTION  : 71206
 * DUE DATE : 8/27/19
*****************************************************************************/


#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


/*****************************************************************************
*
* CONVERTING ROMAN NUMERALS
*_________________________________________________
* This program converts a positive integer into
*  Roman numerals, or standard numbers into Roman
*  numerals.
*_________________________________________________
* INPUT:
*  int x: Let's the user decide whether they want
*          convert a standard number to Roman
*          Roman numerals, or vice versa.
*  int n: A standard number the user enters to
*          convert to Roman numerals.
*  string roman: A Roman numeral the user enters
*          to convert to a standard number.
*
* OUTPUT:
*  string answer: The Roman numeral of the
*          standard number entered by the user.
*  int c: The standard number of the Roman
*          numeral entered by the user.
******************************************************************************/


// FUNCTION PROTOTYPES

/*****************************************************************************
 * roman_thousand
 * This function receives the standard number
 *	entered by the user and determines the
 *	number in the thousands place, and outputs
 *	the Roman numeral.
 *	- returns each number's appropriate Roman
 *	numeral in that place
*****************************************************************************/
string rom_thous(int n);  // IN - user input of number


int main()
{
    int x;          // INOUT - menu indicator for conversion
    int n;          // INPUT - The standard number entered by the user
    string roman;   // INPUT - The Roman numeral entered by the user
    string answer;  // CALC & OUT - Output of converted number
    int c;       	// CALC & OUT - Output of converted numeral

    // INPUT -- A menu for the user to select indicator, entering 1 or 0
    cout << "Type 1 for standard -> Roman numeral conversion. "
		 << "\nType 2 for Roman numeral -> Standard numeral conversion." << endl;
    cin >> x;

	return 0;
}

/*****************************************************************************
 * FUNCTION rom_thous
 *________________________________________________
 * This function receives the standard number
 *	entered by the user and determines the
 *	number in the thousands place, and outputs
 *	the Roman numeral.
 *	- returns each number's appropriate Roman
 *	numeral in that place
 *________________________________________________
 * PRE-CONDITIONS
 * The following needs previous defined values:
 * n: user inputted standard number
 *
 * POST-CONDITIONS
 * This function will output the appropriate Roman numerals for parts
 *of the standard number
*****************************************************************************/
string rom_thous (int n) // IN - num entered by the user
{
    string num; // OUTPUT -- number placeholder
    n = n/1000; // CALC -- Gets the number in the thousands place


	
	
	
