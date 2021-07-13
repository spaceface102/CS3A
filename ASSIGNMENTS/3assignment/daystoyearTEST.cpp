#include <cstdio>

long YearsToDays(unsigned y)
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

long Classic_DaysToYears(long d)
{
    /*NOTE:, can not really do an inverse calculation of YearsToDays()
    because of how integer division works and it is more or less like
    using floor of the division result. For the reason that it is implicitly
    using floor, making an inverse is a lot harder. This should be effiecent
    enough though!*/
    unsigned numYears;  //PROC & RETURN - number of years according to days

    if (d < 365)    //first year, do this to cover negative nums
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

long Experimental_DaysToYears(long d)
{
    //num days for every specific time period

    //a normal, non leap year only has 365 days
    static const long normalYear =  365;
    //3 normal years of 365, one year with an extra day (leap)
    static const long fourYears = (3*normalYear) + normalYear+1;
    //24 four year periods (96 years) with one leap year, 
    //and the last four year period does not have a leap year
    //since divisible by 100
    static const long hundredYears = 24*fourYears + (4*normalYear);
    //3 one hundred year periods (300 years) where the last 
    //year is not a leap year, and 25 four year periods (100 years)
    //where every four years there is a leap year. The year 400
    //is a leap year since it is divisible by 400 evenly,
    //(it doesn't matter that its divisible by 100, those are just
    // the rules)
    static const long fourHundredYears = 3*hundredYears + 25*fourYears;

    long totalYears, totalDays;

    totalYears = 0;
    totalDays = d;
    
    totalYears += 400*(totalDays/fourHundredYears);
    totalDays = totalDays%fourHundredYears;
    totalYears += 100*(totalDays/hundredYears);
    totalDays = totalDays%hundredYears;
    totalYears += 4*(totalDays/fourYears);
    totalDays = totalDays%fourYears;
    
    return totalYears + (totalDays/normalYear);
}

int main(void)
{
    long days;
    for (long i = 1; i < 100000; i++)
    {
        days = YearsToDays(i);
        if (Classic_DaysToYears(days) != Experimental_DaysToYears(days))
        {
            printf(
            "\nOops!!!"
            "Year: %ld\n"
            "Days in Year: %ld\n"
            "Classic_DaysToYears() = %ld\n"
            "Experimental_DaysToYears() = %ld\n",
            i, days, Classic_DaysToYears(days), Experimental_DaysToYears(days));
        }
    }
    return 0;
}