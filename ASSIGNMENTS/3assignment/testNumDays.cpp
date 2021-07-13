#include <iostream>
#include <cstdlib>
#include <ctime>

int IsLeap(long year)
{
    return (year != 0) && ( (year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0)) );
}

long GetDaysSinceYearZero(long year)
{
    if (year <= 0)
        return 0L;
    return year*365 + (year/4) - (year/100) + (year/400);
    //can't really simplify this expression, since division is also a floor operation
}

long YearBasedOnDaysSinceYearZero(long days)
{
    return ((days*400)/146097);
}

long DaysBetweenYears(long startYear, long endYear)
{
    long days = 0;
    for (long year = startYear; year < endYear; year++)
        days += 365 + IsLeap(year);
    return days;
}

long PredictDaysBetweenYears(long startYear, long endYear)
{   //startYear must be smaller than endYear!
    return GetDaysSinceYearZero(endYear - 1)
           - GetDaysSinceYearZero(startYear - 1)
           + (startYear == 0)*365;
}

unsigned Random(long lower, long upper)
{
    return ((unsigned)rand() % (upper - lower + 1)) + lower;
}

int main(void)
{
    long max_iter;
    srand(time(NULL));
    
    std::cout << "Numebr of iterations: ";
    std::cin >> max_iter;

    for (long i = 0; i < max_iter; i++)
    {
        unsigned startYear, endYear;
        startYear = Random(0, 9999);
        endYear = Random(startYear, 10000);
        if (PredictDaysBetweenYears(startYear, endYear)
            != DaysBetweenYears(startYear, endYear))
            std::cout << "Error: " << startYear 
            << " -> " << endYear << "\n";
    }
    return 0;
}

/*
Error: 0 -> 7398
Error: 0 -> 4250
Error: 0 -> 9680
Error: 0 -> 4223
Error: 0 -> 650
Error: 0 -> 7987
Error: 0 -> 7997
Error: 0 -> 191
Error: 0 -> 7627
Error: 0 -> 748
Error: 0 -> 5639
Error: 0 -> 465
Error: 0 -> 2983
Error: 0 -> 3363
*/