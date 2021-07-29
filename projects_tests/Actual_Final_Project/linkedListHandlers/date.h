#ifndef CLASS_DATE_H
#define CLASS_DATE_H

#include <string>
#include <cstdint>

class Date
{
private:
    unsigned day;           //IN/OUT - day integer value 0 -> 31
    unsigned month;         //IN/OUT - month integer value 1 -> 12
    std::string monthName;  //IN/OUT - month name, January -> December
    unsigned year;          //IN/OUT - year integer value 0 -> 2**32 - 1

public:
    /*****************************
    ** CONSTRUCTOR & DESTRUCTOR **
    *****************************/
    Date();
    Date(unsigned m, unsigned d, unsigned y);
    Date(const std::string &mn, unsigned d, unsigned y);

    /**************
    ** ACCESSORS **
    **************/
    void printNumeric() const;
    void printAlpha() const;

    /***************
    **  CREATORS  ** //makes a new object and returns that object
    ***************/
    Date addDays(int d) const; //extra credit

private:
    /*********************
    ** HELPER FUNCTIONS **
    *********************/
    bool isLeap(unsigned y) const;
    unsigned daysPerMonth(unsigned m, unsigned y) const;
    std::string name(unsigned m) const;
    unsigned number(const std::string &mn) const;
    
    /*****************************************
    ** Specifically Used For addDays Method **
    *****************************************/
    long YearsToDays(unsigned y) const;
    long DaysToYears(long d) const;
    unsigned DaysToMonths(long d, unsigned y) const;
    unsigned MonthsToDays(unsigned m, unsigned y) const;

    long ConvertToDays(void) const;

//ADDITIONS FOR FINAL ASSIGNMENT
private: //extra fields
    uint64_t totalDays; //PROC - set in constructor, stores date
                        //converted to only days

public: 
    //necessary overloads for select_sort, insert_sorted and remove
    //duplicates from the templated LinkedList class (I created)
    bool operator<(const Date& that) const;
    bool operator>=(const Date& that)const;
    bool operator>(const Date& that) const;
    bool operator==(const Date& that) const;
    friend std::ostream& operator<<(std::ostream& out, const Date obj);
};

#endif //CLASS_DATE_H