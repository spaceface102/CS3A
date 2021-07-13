#include <iostream>

class Date
{
private:
    int month;
    int day;
    int year;
public:
    Date();
    Date(int m, int d, int y);
    void SetMonth(int m);
    void SetDay(int d);
    void SetYear(int y);
    int GetMonth(void) const;
    int GetDay(void) const;
    int GetYear(void) const;

    //Checking Methods
    bool CheckMonth(int m);
    bool CheckDay(int m, int d);
    bool CheckYear(int y);
    //Output Method
    void PrintFormatedDate(void) const;
};

void Date::PrintFormatedDate(void) const
{
    std::cout
    << month << "/"
    << day << "/"
    << year << "\n";
}

Date::Date()
{
    month = day = year = 1;
}
Date::Date(int m, int d, int y)
{
    if (CheckMonth(m))
    month = m;
    else 
    {
        month = 1; //default value
        std::cout << "Bad month!\n";
    }
    if (CheckDay(month, d))
        day = d;
    else    
    {
        day = 1; //default value
        std::cout << "Bad day!\n";
    }
    
    if (CheckYear(y))
        year = y;
    else
    {
        year = 1; //default value
        std::cout << "Bad year\n";
    }
}
//EOF

void Date::SetMonth(int m)
{
    if (CheckMonth(m))
        month = m;
    else
        std::cout << "Bad month!\n";
}
//EOF

void Date::SetDay(int d)
{
    if (CheckDay(month, d))
        day = d;
    else
        std::cout << "Bad day!\n";
}
//EOF

void Date::SetYear(int y)
{
    if (CheckYear(y))
        year = y;
    else
        std::cout << "Bad year!\n";
}
//EOF

int Date::GetMonth(void) const
{
    return month;
}
//EOF

int Date::GetDay(void) const
{
    return day;
}
//EOF

int Date::GetYear(void) const
{
    return year;
}
//EOF

bool Date::CheckMonth(int m)
{
    return (m >= 1 && m <= 12);
}            

bool Date::CheckDay(int m, int d)
{
    switch (m) //month
    {
        case 1:
            return (d >= 1 && d <= 31);
        case 2:
            return (d >= 1 && d <= 28);
        case 3:
            return (d >= 1 && d <= 31);
        case 4:
            return (d >= 1 && d <= 30);
        case 5:
            return (d >= 1 && d <= 31);
        case 6:
            return (d >= 1 && d <= 30);
        case 7:
            return (d >= 1 && d <= 31);
        case 8:
            return (d >= 1 && d <= 31);
        case 9:
            return (d >= 1 && d <= 30);
        case 10:
            return (d >= 1 && d <= 31);
        case 11:
            return (d >= 1 && d <= 30);
        case 12:
            return (d >= 1 && d <= 31);
        default:
            return false;
    }
}
//EOF

bool Date::CheckYear(int y)
{
    return (y >= 0);
}