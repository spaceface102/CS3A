/*****************************************************************************
 * AUTHOR   : Osbaldo Gonzalez Jr. && William Ho
 * LAB #2   : Array Histogram
 * CLASS    : CS 3A
 * SECTION  : 71206
 * DUE DATE : 6/22/2021
*****************************************************************************/

#include <iostream>
#include <cstdlib> //used of srand() && rand()
#include <cstring> //memset
#include <iomanip> //used for std::setw() && std::left


/*****************************************************************************
 * 
 *   RANDOM DICE ROLL GAUSSIAN DISTRIBUTION
 *______________________________________________________________________________
 *   This program takes a seed value from the user and ask how many rolls
 *   the user want. After the simulated dice rolls are completed, the user
 *   is presented with a histogram displaying how many times each roll landed
 *   on a certain value.
 *______________________________________________________________________________
 *  INPUT:
 *      int seed:      Seed value for the srand() function, controls distribution
 *      int numbrolls: Used to set the number of rolls the program does
 *  OUTPUT:
 *      int counts[]:  Used to track the times of each roll, used by printHistogram()
*****************************************************************************/

//CONSTANTS
const int DICESIDES = 6;  //CONSTANT - Defines the number of dice sides each die has
const int NUMDICE = 4;    //CONSTANT - Defines the number of dice in total to roll
//EOC

//FUNCTION DECLERATIONS/PROTOTYPES
/*****************************************************************************
 * Roll
 *  The function takes no arguments. It will return an integer value between
 *  1 and DICESIDES inclusive. It is dependent on the global DICESIDES const
 * 
 * Total Roll
 *  The function takes no arguments, It will return an integer value between
 *  1*NUMDICE and DICESIDES*NUMDICE inclusive. The function is dependent 
 *  on the Roll() func, and the global NUMDICE const
 * 
 * DoTheRolls
 *  The function takes in an int array, counts[], used to track rolls; inside
 *  the function, the rolls are done, and counts is therfore modified in inside
 *  the function. The function also takes a seed value, used to seed the random
 *  number generator. Lastly, the function takes the number of rolls, which 
 *  has a direct affect on how many times count is touched/modified 
 * 
 * PrintHistogram
 *  The function takes in an int array, counts[], that should have all the
 *  tracking information from all the rolls done in the DoTheRolls() func.
*****************************************************************************/
int Roll(void);
int TotalRoll(void);
void DoTheRolls(int counts[], const int seed, const int numbrolls);
void PrintHistogram(const int counts[]);
//EOD/P

//MAIN
int main(void)
{
    int seed;                          //INPUT      - defines the seed used for srand()
    int numbrolls;                     //INPUT      - defines how many roles the dice do
    int counts[(DICESIDES*NUMDICE)+1]; //PROC & OUT - tracks the times a certain value is rolled
    //+1 to have an valid index at DICESIDE*NUMDICE

    //INPUT: Take in seed val for srand() and numbrolls for doTheRolls() func
    std::cout << "Enter the seed value: \n";
    std::cin >> seed;
    std::cout << "Enter the number of Rolls: \n";
    std::cin >> numbrolls;
    std::cout << "\n";
    

    //PROCESSING: Use doTheRolls() func to do the defined rolls with correct seed
    DoTheRolls(counts, seed, numbrolls);


    //OUTPUT: printHistogram() will print all the rolls related to a specific number line by line
    PrintHistogram(counts);
    return 0;
}
//EOF


/*****************************************************************************
 * FUNCTION Roll
 *______________________________________________________________________________
 *  This function takes no arguments. It will return an integer value between
 *  1 and DICESIDES inclusive. It is dependent on the global DICESIDES const
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The constant int DICESIDES must NOT be equal to zero.
 * 
 * POST-CONDITIONS
 *  The value range is between 1 and DICESIDES inclusive
*****************************************************************************/
int Roll(void)
{
    return (rand()%DICESIDES)+1;
}
//EOF


/*****************************************************************************
 * FUNCTION TotalRoll
 *______________________________________________________________________________
 *  The function takes no arguments, It will return an integer value between
 *  1*NUMDICE and DICESIDES*NUMDICE inclusive. The function is dependent 
 *  on the Roll() func, and the global NUMDICE const
 * _____________________________________________________________________________
 * PRE-CONDITIONS
 *  The Roll() function must exist/be declared. Can not change the number
 *  of consecutive rolls without chaning the global NUMDICE variable
 * 
 * POST-CONDITIONS
 *  The value range is between 1*NUMDICE and DICESIDE*NUMDICE inclusive
*****************************************************************************/
int TotalRoll(void) 
{
    int total = 0; //CALC & OUT - Total roll value of NUMDICE dice, with DICESIDES
    for (int i = 0; i < NUMDICE; i++)
        total += Roll();
    return total;
}
//EOF


/*****************************************************************************
 * FUNCTION PrintHistogram
 *______________________________________________________________________________
 *  The function takes in an int array, counts[], that should have all the
 *  tracking information from all the rolls done in the DoTheRolls() func.
 * _____________________________________________________________________________
 * PRE-CONDITIONS
 *  The counts[] int array, must already have been processed by the DoTheRolls()
 *  function in order for there to be any significant output. 
 *
 * POST-CONDITIONS
 *  The histogram is not assured to fit fully on the horizontal section of the console.
 *  The histogram's height will always be (NUMDICE*DICESIDES) - NUMDICE
*****************************************************************************/
void PrintHistogram(const int counts[])
{
    const int maxpossibleroll = DICESIDES*NUMDICE;  //CONST - Gives name to DICESIDE*NUMDICE
                                                    //to increase readability

    //PREPROCESSING - Setting up for nice formated output in the output section                                              
    int maxdigits;  //CALC - used to store how many digits there are in maxpossibleroll
    maxdigits = 0;  //used to for std::setw() to have a good looking, formatted, output
    for (int maxnum = maxpossibleroll; maxnum != 0; maxdigits++, maxnum /= 10)
        ;

    //OUTPUT section, prints formated output to console based on counts array
    for (int i = NUMDICE; i <= maxpossibleroll; i++)
    {
        //std::left for left justified text
        std::cout << std::setw(maxdigits) << std::left << i << ": ";
        for (int j = counts[i]; j != 0; j--)
            std::cout << "X";
        std::cout << "\n";
    }
}
//EOF


/*****************************************************************************
 * FUNCTION DoTheRolls
 *______________________________________________________________________________
 *  The function takes in an int array, counts[], that will be filled/modified.
 *  The seed for the random number generator stays constants throughout the life
 *  of the function, along with the passed in numbrolls
 * _____________________________________________________________________________
 * PRE-CONDITIONS
 *  The counts[] array size must be DICESIDE*NUMDICE + 1, aka, it's max index
 *  must be DICESIDE*NUMDICE. If any work is expected to be done, numbrolls
 *  must be greater than zero.
 *
 * POST-CONDITIONS
 *  counts[] will have been modified/touched numbrolls times. If you add all
 *  the values from each index in the counts[] array together, the value
 *  will be numbrolls.
 *  The values between the indicies of 0 and NUMDICE - 1 inclusive will remain
 *  to be zero, since the TotalRoll() function will never produce such values.
*****************************************************************************/
void DoTheRolls(int counts[], const int seed, const int numbrolls)
{
    srand(seed);
    memset(counts, 0x0, sizeof(int)*((DICESIDES*NUMDICE) + 1)); //set counts[] to all zeros
    for (int i = 0; i < numbrolls; i++)
        counts[TotalRoll()]++; //totalRoll() is ensured to return a valid index value
}