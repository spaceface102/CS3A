#!/usr/bin/python3
import sys

def isLeap(year:int) -> bool:
    return (year != 0) and ((year%400==0) or ((year%100!=0) and (year%4==0)))

def howMany(startYear:int, endYear:int) -> int:
    sumLeap = 0
    for year in range(startYear, endYear + 1):
        sumLeap += int(isLeap(year))
    return sumLeap

def ShowLeapCount(startYear:int, endYear:int, step:int) -> None: 
    for year in range(startYear, endYear, step): 
        print("Years: ", year, "\t->\t", year+step, end = ' ') 
        print("\t =", howMany(year, year+step))

def Sweep(startYear:int, endYear:int, offset:int) -> None:
    for year in range(startYear, endYear+1, offset):
        print("Years: ", year, "\t->\t", year+offset, end = ' ') 
        print("\t =", howMany(year, year+offset))

def DaysBetweenYears(startYear:int, endYear:int) -> int:
    days = 0
    for year in range(startYear, endYear):
        days += 365 + int(isLeap(year))
    return days

def GetDaysSinceYearZero(year:int) -> int:
    ''' each year is assured to at least have 365 days
        every four years, it is usually a leap year,
        every 100 years, it is not leap year, unless 
        it is every 400 year'''
    if year <= 0:
        return 0
    return year*365 + (year//4) - (year//100) + (year//400)

def PredictDaysBetweenYears(startYear:int, endYear:int) -> int:
    '''since I want to get the days between, non inclusive to endYear
    I need to do -1'''
    if (startYear == 0):
        add = 365
    else:
        add = 0
    return GetDaysSinceYearZero(endYear - 1) - GetDaysSinceYearZero(startYear - 1) + add


if __name__ == '__main__':
    DaysBetweenYears(0, 1)

    if (len(sys.argv) > 2):
        print( howMany(int(sys.argv[1]), int(sys.argv[2])) ) 
    else:
        startYear = int(input("Start Year: "))
        endYear   = int(input("End Year:   "))
        print(howMany(startYear, endYear))