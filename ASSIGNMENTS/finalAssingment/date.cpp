#include "date.h"
#include <ctype.h>
#include <iostream>

/****************************************************************
 * 
 *  Method Constructor: Class Date       //DEFAULT CONSTRUCTOR
 * --------------------------------------------------------------
 * This is a constructor method. The new object will use this 
 * constructor if no arguments are used. The date will
 * automatically be set to January 1st, 2000
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must make an object, or call the constructor with no
 *      arguments.
 *  POST-CONDITIONS
 *      The object is now ready to do everything that is able
 *      to do anything in the public interface as intdended.
****************************************************************/
Date::Date()
{
    day = 1;
    month = 1;
    monthName = "January";
    year = 2000;
    totalDays = ConvertToDays();
}
//EOF

/****************************************************************
 * 
 *  Method Constructor: Class Date       //CONSTRUCTOR
 * --------------------------------------------------------------
 * This is a constructor method. The new object will use this 
 * constructor if the passed in arguments are unsigned 
 * (month arg), unsigned (day arg), and unsigned (year arg)
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must make an object, or call the constructor with the
 *      parameters described in the Method decleration
 *  POST-CONDITIONS
 *      The object is now ready to do everything that is able
 *      to do anything in the public interface as intdended.
****************************************************************/
Date::Date(unsigned m, unsigned d, unsigned y)
{
    bool invalidDates;  //PROC - Keep track if there are invalid dates
    
    invalidDates = false;   //default value

    //Check month
    if (m > 12)
    {
        invalidDates = true;
        month = 12;
    }
    else if ((int)m <= 0) //m (month arg) is zero or negative
    {
        invalidDates = true;
        month = 1;
    }
    else
        month = m;


    //Check year
    if ((int)y < 0) //y (year arg) is negative
    {
        invalidDates = true;
        year = 2000;   //Just set value like default constructor
    }
    else
        year = y;


    //Check day
    if (d > daysPerMonth(month, year))
    {
        invalidDates = true;
        day = daysPerMonth(month, year);
    }
    else if ((int)d <= 0)
    {
        invalidDates = true;
        day = 1;
    }
    else 
        day = d;


    monthName = name(month);
    //Final conditional output
    if (invalidDates)
    {
        std::cerr << "Invalid date values: Date corrected to ";
        printNumeric();
        std::cerr << ".\n";
    }

    totalDays = ConvertToDays();
}
//EOF

/****************************************************************
 * 
 *  Method Constructor: Class Date       //CONSTRUCTOR
 * --------------------------------------------------------------
 * This is a constructor method. The new object will use this 
 * constructor if the passed in arguments are std::string 
 * (month name arg), unsigned (day arg), and unsigned (year arg)
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must make an object, or call the constructor with the
 *      parameters described in the Method decleration
 *  POST-CONDITIONS
 *      The object is now ready to do everything that is able
 *      to do anything in the public interface as intdended.
****************************************************************/
Date::Date(const std::string &mn, unsigned d, unsigned y)
{
    bool invalidDates;  //PROC - Keep track if there are invalid dates

    invalidDates = false;   //default value

    if (number(mn) == 0)    //check if mn (monthname arg) is recognizable
    {
        day = 1;
        month = 1;
        monthName = "January";
        year = 2000;
        std::cerr << "Invalid month name: the Date was set to ";
        printNumeric();
        std::cerr << ".\n";
    }
    else
    {
        month = number(mn);
        monthName = name(month); //ensure designated name
            //Check year
        if ((int)y < 0) //y (year arg) is negative
        {
            invalidDates = true;
            year = 2000;   //Just set value like default constructor
        }
        else
            year = y;


        //Check day
        if (d > daysPerMonth(month, year))
        {
            invalidDates = true;
            day = daysPerMonth(month, year);
        }
        else if ((int)d <= 0)
        {
            invalidDates = true;
            day = 1;
        }
        else 
            day = d;

        if (invalidDates)
        {
            std::cout << "Invalid date values: Date corrected to ";
            printNumeric();
            std::cout << ".\n";
        }
    }
    totalDays = ConvertToDays();
}
//EOF

/****************************************************************
 * 
 *  Method printNumeric: Class Date       //PUBLIC INTERFACE
 * --------------------------------------------------------------
 * This method will simply format the output. Will print a
 * fully numerical, United States format of the date
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The object must have all it's value set already. This
 *      should always be true, since when making the object,
 *      at least the default constructor will be called.
 * 
 *  POST-CONDITIONS
 *      The output will be displayed on std::cout. Can not
 *      change the output stream.
****************************************************************/
void Date::printNumeric() const
{
    std::cout << month << '/' << day << '/' << year;
}
//EOF

/****************************************************************
 * 
 *  Method printAlpha: Class Date       //PUBLIC INTERFACE
 * --------------------------------------------------------------
 * This method will simply format the output, will print a 
 * string version of month.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The object must have all it's value set already. This
 *      should always be true, since when making the object,
 *      at least the default constructor will be called.
 * 
 *  POST-CONDITIONS
 *      The output will be displayed on std::cout. Can not
 *      change the output stream.
****************************************************************/
void Date::printAlpha() const
{
    std::cout << monthName << ' ' << day << ", " << year;
}
//EOF

/****************************************************************
 * 
 *  Method addDays: Class Date       //PUBLIC INTERFACE
 * --------------------------------------------------------------
 * This method takes in an int d (day arg) and adds the value
 * of d accordingly to make a new date object with virtual
 * the calling object's Data "value" + d (day arg)
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The passed in value can be both positive or negative. If 
 *      negative, this has the affect of subtracting days.
 * 
 *  POST-CONDITIONS
 *      The calling object will NOT be modified. Function 
 *      will account for leap years and calculate accordinly.
 *      The new object swill go through the exact same constructor
 *      checks as any other object, just in case anything really goes
 *      south
****************************************************************/
Date Date::addDays(int d) const
{
    long tempTotalDays; //PROC - convert current Date object
                        //to a measurement of only days.
    unsigned newYear;   //PROC/OUT - used to create new Date obj, years
    unsigned newMonth;  //PROC/OUT - used to create new Date obj, months
    unsigned newDay;    //PROC/OUT - used to create new Date obj, days

    tempTotalDays = ConvertToDays() + d;
    newYear = DaysToYears(tempTotalDays);
    tempTotalDays -= YearsToDays(newYear);   //adjust for next calculations
    if (tempTotalDays == 0) //we are exactly at the begining of the year!
    {
        newMonth = 1;  //Jan.
        newDay = 1;    //first day
    }
    else
    {
        newMonth = DaysToMonths(tempTotalDays, newYear);
        newDay = tempTotalDays - MonthsToDays(newMonth, newYear);
    }

    return Date(newMonth, newDay, newYear);
}
//EOF





//ONLY PRIVATE FUNCTIONS BELOW





/****************************************************************
 * 
 *  Method isLeap: Class Date       //PRIVATE
 * --------------------------------------------------------------
 * This method takes in an unsigned integer y (year), and 
 * a boolean defining if the value year is leap (true) or
 * is not leap (false)
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The year value can be anything. Do note since y (year)
 *      is UNSIGNED, negative values will have unexpected values.
 *      Year 0 is not leap for this implementation.
 * 
 *  POST-CONDITIONS
 *      The return value will only be true or false.
 *      If y (year) is divisible by 400 or if y (year)
 *      is not divisible by 100 and divisible by 4, it defined
 *      as a leap year. Else, not a leap year.
****************************************************************/
bool Date::isLeap(unsigned y) const
{
    return (y != 0) && ( (y % 400 == 0) || ((y % 100 != 0) && (y % 4 == 0)) );
}
//EOF

/****************************************************************
 * 
 *  Method daysPerMonth: Class Date     //PRIVATE
 * --------------------------------------------------------------
 * This method takes in an unsigned integer m (month) and
 * an unsigned integer y (year), and returns the number of 
 * days associated with the month and year passed in.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The month value, m, must be between 1 and 12 inclusive.
 *      Please avoid passing in a negative value; Remember,
 *      UNSIGNED m, UNSIGNED y. 
 *      The year value can really be anything, just note that 
 *      it decides if February has 28 or 29 days.
 * 
 *  POST-CONDITIONS
 *      If m (month) is between 1 and 12 inclusive, the return
 *      number of days will be as expected, also acconting for
 *      leap year. 
 *      If m (month) is out of range, will return 0.
****************************************************************/
unsigned Date::daysPerMonth(unsigned m, unsigned y) const
{
    static const unsigned DAY_TABLE[13] = //CONST/PROC - process m (month)
    {   //there is no 0th month, just set to 0
        0, 31, 28, 31, 30,  //0th, Jan, Feb, March, April
        31, 30, 31, 31, 30, //May, June, July, Aug, Sept
        31, 30, 31          //Oct, Nov, Dec
    };

    if (m > 12 || m == 0)
        return 0;  //days in January

    //(int)true = 1, (int)false = 0  ALSO: when m = 2 -> February
    return DAY_TABLE[m] + (int)(isLeap(y) && m == 2);
}
//EOF

/****************************************************************
 * 
 *  Method name: Class Date     //PRIVATE
 * --------------------------------------------------------------
 * This method takes in an unsigned integer m (month) and
 * returns the related Month string in a std::string.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The month value, m, must be between 1 and 12 inclusive.
 *      Please avoid passing in a negative value; Remember,
 *      UNSIGNED m. 
 * 
 *  POST-CONDITIONS
 *      Assuming passed in arg is in the valid 1 to 12 range,
 *      The method will return a std::string object with the
 *      approbate month. ex. 10 -> "October".
 *      If not a valid value, will return an empty string "".
****************************************************************/
std::string Date::name(unsigned m) const
{
    static const char *MONTH_TABLE[13] =
    {
        "", "January", "February", "March", //there is no 0th month
        "April", "May", "June", "July",
        "August", "September", "October",
        "November", "December"
    };

    if (m > 12 || m == 0)
        return std::string("");

    return std::string(MONTH_TABLE[m]);
}
//EOF

/****************************************************************
 * 
 *  Method number: Class Date       //PRIVATE
 * --------------------------------------------------------------
 * This method takes a const reference to a std::string which
 * contains a month name like "January" and returns the numerical
 * constant associated with it, ex. "March" = 3
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The month must not be misspled! 
 *      The string can be lower case or upper case.
 *      **The passed in string must be 3 or more characters long.
 *      Three character long month abbreviations are OK.
 * 
 *  POST-CONDITIONS
 *      The return value will be a value between 1 to 12 
 *      inclusive if the passed in string is valid. 
 *      Else, returns 0.
****************************************************************/
unsigned Date::number(const std::string &mn) const
{
    char tempMonth[4];  //PROC - store a copy of the first three chars
    int  tempMonthVal;  //PROC - store the actual value of the character array

    if (mn.length() < 3)  //mn must have a length of atleast 3
        return 0;

    tempMonth[0] = tolower(mn[0]);
    tempMonth[1] = tolower(mn[1]);
    tempMonth[2] = tolower(mn[2]);
    tempMonth[3] = '\0';            //NULL Terminating character

    //basically now reading the memory associated with tempMonth
    //as an int. Type casting a character pointer to an integer
    //pointer. Note, having the size of the character array be
    //4 is crucial, since when using an int * and derefrencing
    //the address, we will be reading 4 bytes from memory.
    //Making the character array tempMonth would mean we would
    //access memory we are not supposed to.

    tempMonthVal = *((int *)tempMonth);

    if (tempMonthVal == *((int *)"jan"))
        return 1;
    else if (tempMonthVal == *((int *)"feb"))
        return 2;
    else if (tempMonthVal == *((int *)"mar"))
        return 3;
    else if (tempMonthVal == *((int *)"apr"))
        return 4;
    else if (tempMonthVal == *((int *)"may"))
        return 5;
    else if (tempMonthVal == *((int *)"jun"))
        return 6;
    else if (tempMonthVal == *((int *)"jul"))
        return 7;
    else if (tempMonthVal == *((int *)"aug"))
        return 8;
    else if (tempMonthVal == *((int *)"sep"))
        return 9;
    else if (tempMonthVal == *((int *)"oct"))
        return 10;
    else if (tempMonthVal == *((int *)"nov"))
        return 11;
    else if (tempMonthVal == *((int *)"dec"))
        return 12;
    else
        return 0;
}
//EOF





//BELOW ARE ALL THE METHOD IMPLEMENTATIONS
//FOR THE HELPER METHODS USED BY addDays





/****************************************************************
 * 
 *  Method YearsToDays: Class Date       //PRIVATE
 * --------------------------------------------------------------
 * Takes a year value and returns the days associated with start
 * with January 1st, 1  (1/1/1) up to the (12/31/year - 1).
 * Note the -1, this means that instead of getting the number of
 * days in up the end of the year arg, the function returns the
 * number of days up to NEW YEAR Morning
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Negative years are allowed, (will return 0 days if so).
 * 
 *  POST-CONDITIONS
 *      The calling object will not be modified.
 *      The function will take into account leap years
 *      into the days calculation.
****************************************************************/
long Date::YearsToDays(unsigned y) const
{   
    /*There are always at least 365 days,
    usually, every four years is a leap year
    (therefore 25 leap years in 100 years),
    but usually if the year is divisibale by
    100 not a leap year (have to reduce by one
    from (y/4) expression) unless it is divisible
    by 400 (in which case we nullify some of the
    (y/100) expression with (y/400)*/

    y -= 1;             //to ensure we are only calculating the days
                        //as the previous year finished, kind of 
                        //like range() in python

    if ((int)y <= 0)    //just in case negative value is passed
        return 0;

    return y*365 + (y/4) - (y/100) + (y/400);
}
//EOF

/****************************************************************
 * 
 *  Method DaysToYears: Class Date       //PRIVATE
 * --------------------------------------------------------------
 * It takes d (day arg) and returns the year value associated
 * with it
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      d (day arg) value should be in context of starting from
 *      1/1/1 which would be day 1, up to day d (value passed in).
 * 
 *  POST-CONDITIONS
 *      The returned year will either be worth the exact same number
 *      of days as passed in, or up to 365 days less. It will be the
 *      correct year for sure!
 *      Note, if d (value passed in) is negative, then the return
 *      value will be 0 years.
****************************************************************/
long Date::DaysToYears(long d) const
{
    /*NOTE:, can not really do an inverse calculation of YearsToDays()
    because of how integer division works and it is more or less like
    using floor of the division result. For the reason that it is implicitly
    using floor, making an inverse is a lot harder. This should be effiecent
    enough though!*/
    unsigned numYears;  //PROC & RETURN - number of years according to days

    if (d < 365)   //first year, do this to cover negative nums
                    //and also when d < 365 which would result in numYear = 0
        return 0; 

    numYears = d/365;   //rough approx. can be greater then the actual num years
                        //(day arg) calculated to include a leap year.
    //here we get exact numYears
    while (d < YearsToDays(numYears))
        numYears--;
    //d will be >= YearsToDays(numYears), if equal, then it's the
    //start of the year, if it is not equal, then there are months
    //in the year to account for in d
    return numYears;
}
//EOF


/****************************************************************
 * 
 *  Method DaysToMonths: Class Date       //PRIVATE
 * --------------------------------------------------------------
 *  This method takes in d (day arg) and y (year arg) and figures
 *  out what month d value relates to. There are 12 months.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      d (day arg) value should be in context of starting from
 *      the start of y (year arg). The range therefore of values
 *      is between 1 up to 365 if y does not indicate leap year,
 *      or up to 366 if y is a leap year.
 * 
 *  POST-CONDITIONS
 *      The month return value is 1 through 12; the numerical
 *      representation of a month. If the d value (day agr) is
 *      either too small or too big, the return value will simply
 *      be 0 (not a valid month value)
****************************************************************/
unsigned Date::DaysToMonths(long d, unsigned y) const
{
    int leap;   //PROC - if leap, have to shift range by 1

    leap = (int)isLeap(y);

    if (d < 0)
        return 0;   //ERROR, days must be positive
    else if (d <= 31)
        return 1;   //Januraray
    else if (d <= 59 + leap)
        return 2;   //Feb.
    else if (d <= 90 + leap)
        return 3;   //March
    else if (d <= 120 + leap)
        return 4;   //April
    else if (d <= 151 + leap)
        return 5;   //May
    else if (d <= 181 + leap)
        return 6;   //June
    else if (d <= 212 + leap)
        return 7;   //July
    else if (d <= 243 + leap)
        return 8;   //Aug.
    else if (d <= 273 + leap)
        return 9;   //Sept.
    else if (d <= 304 + leap)
        return 10;  //Oct.
    else if (d <= 334 + leap)
        return 11;  //Nov.
    else if (d <= 365 + leap)
        return 12;  //Dec.
    else
        return 0;   //ERROR, to big day count
}
//EOF

/****************************************************************
 * 
 *  Method MonthToDays: Class Date       //PRIVATE
 * --------------------------------------------------------------
 *  This method takes in m (month arg) and y (year arg) and figures
 *  out how many days have elapsed between January 1st and the
 *  first day of the month. Values will change if y is a leap year.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      m (month arg) is a value between 1 and 12.
 *      There are no restrictions for the y (year arg)
 *      value
 * 
 *  POST-CONDITIONS
 *      The value returned, if m is a value between 1 and 12,
 *      will be between 0 and 334 (for December). If out of
 *      range, will return 0.
****************************************************************/
unsigned Date::MonthsToDays(unsigned m, unsigned y) const
{
    static const int NUMDAYS_ELAPSED[13] = //CONST/PROC - how many days up
                                           //             to a certain month
    {   //there is no 0th month, just set to 0
          0,   0,  31,  59,  90,    //0th, Jan,   Feb, Mar, April
        120, 151, 181, 212, 243,    //May, June, July, Aug, Sept
        273, 304, 334               //Oct, Nov, Dec
    };  //number of days elapsed since the start of a month
        //Ex. at the start of January, elapsed 0 days, at the
        //start of February, elapsed 31 days!
    
    if (static_cast<int>(m) < 0 || m > 12)    //Just in case month is out of range
        return 0;

    //only count extra leap day if month is after feb
    return NUMDAYS_ELAPSED[m] + (int)( (m > 2) && isLeap(y) );
}
//EOF

/****************************************************************
 * 
 *  Method ConvertToDays: Class Date       //PRIVATE
 * --------------------------------------------------------------
 * This method uses the private attributes of the calling method
 * to convert all the values to a single type day value. For
 * example if the object has the date 1/1/2, it will return a
 * total of 365 days. It will of course handle the case of 
 * leap years. It will start counting from 1/1/1, this will be
 * the "1st" day that everything is relative to.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The object must have gone through the constructor already.
 * 
 *  POST-CONDITIONS
 *      The calling function will NOT be modified. The value
 *      is simply returned. Programmer can use as they wish, 
 *      (I personally use it for the addDays method)
****************************************************************/
long Date::ConvertToDays(void) const
{       
    return day  + MonthsToDays(month, year)
                + YearsToDays(year);
}
//EOF







//ADDITIONS FOR FINAL ASSIGNMENT







/****************************************************************
 * 
 *  Method operator<: Class Date       //PUBLIC
 * --------------------------------------------------------------
 *  Compare the values of two data classes, specifically the 
 *  total number of days since 1/1/1 (the date at which all the
 *  days for this Date class are relative to.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The object must have gone through the constructor already.
 * 
 *  POST-CONDITIONS
 *      The calling function will NOT be modified.
 *      If the totalDays of the calling object is SMALLER than
 *      that of the passed in Date object, returns TRUE, else
 *      FALSE.
****************************************************************/
bool Date::operator<(const Date& that) const
    {return totalDays < that.totalDays;}
//EOF

/****************************************************************
 * 
 *  Method operator>=: Class Date       //PUBLIC
 * --------------------------------------------------------------
 *  Compare the values of two data classes, specifically the 
 *  total number of days since 1/1/1 (the date at which all the
 *  days for this Date class are relative to.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The object must have gone through the constructor already.
 * 
 *  POST-CONDITIONS
 *      The calling function will NOT be modified.
 *      If the totalDays of the calling object is GRATER THAN
 *      OR EQUAL TO that of the passed in Date object, 
 *      returns TRUE, else FALSE.
****************************************************************/
bool Date::operator>=(const Date& that)const
    {return totalDays >= that.totalDays;}
//EOF

/****************************************************************
 * 
 *  Method operator>: Class Date       //PUBLIC
 * --------------------------------------------------------------
 *  Compare the values of two data classes, specifically the 
 *  total number of days since 1/1/1 (the date at which all the
 *  days for this Date class are relative to.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The object must have gone through the constructor already.
 * 
 *  POST-CONDITIONS
 *      The calling function will NOT be modified.
 *      If the totalDays of the calling object is GREATER than
 *      that of the passed in Date object, returns TRUE, else
 *      FALSE.
****************************************************************/
bool Date::operator>(const Date& that) const
    {return totalDays > that.totalDays;}
//EOF

/****************************************************************
 * 
 *  Method operator==: Class Date       //PUBLIC
 * --------------------------------------------------------------
 *  Compare the values of two data classes, specifically the 
 *  total number of days since 1/1/1 (the date at which all the
 *  days for this Date class are relative to.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The object must have gone through the constructor already.
 * 
 *  POST-CONDITIONS
 *      The calling function will NOT be modified.
 *      If the totalDays of the calling object is EQUAL TO
 *      that of the passed in Date object, returns TRUE, else
 *      FALSE.
****************************************************************/
bool Date::operator==(const Date& that) const
    {return totalDays == that.totalDays;}
//EOF

/****************************************************************
 * 
 *  Function operator<<
 *  //Class Date FRIEND
 * --------------------------------------------------------------
 *  Overloads operator<<, displays as printAlpha(). Thats is 
 *  the only way it will print
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The object must have gone through the constructor already.
 * 
 *  POST-CONDITIONS
 *      The Date object stays untouched.
 *      Output Format as follows:
 *      monthName <space> day <comma && space> year
 *      Notice that there is NO new line!
****************************************************************/
std::ostream& operator<<(std::ostream& out, const Date obj)
{
    //added the extra space at the end just for
    //formating with LinkedList::display makes 
    //it look nicer
    out << obj.monthName << " " << obj.day << ", " << obj.year << " ";
    return out;
}