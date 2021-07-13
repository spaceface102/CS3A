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

    void PrintFormatedDate(void) const;
};

Date::Date()
{
    month = day = year = 1;
}

Date::Date(int m, int d, int y)
{
    month = m;
    day = d;
    year = y;
}

void Date::SetMonth(int m)
{
        month = m;
}

void Date::SetDay(int d)
{
    day = d;
}

void Date::SetYear(int y)
{
    year = y;
}

int Date::GetMonth(void) const
{
    return month;
}
int Date::GetDay(void) const
{
    return day;
}

int Date::GetYear(void) const
{
    return year;
}

void Date::PrintFormatedDate(void) const
{
    std::cout
    << month << "/"
    << day << "/"
    << year << "\n";
}


int main(void)
{
    Date test(4, 20, 1969);
    Date another();
    test.PrintFormatedDate();
}