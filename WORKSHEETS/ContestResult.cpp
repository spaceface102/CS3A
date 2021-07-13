#include <iostream>
#include <string>

using namespace std;

class ContestResult
{
private:
        string winner;
        string secondPlace;
        string thirdPlace;
public:
    ContestResult(void);
    ContestResult(const string&, const string&, const string&);
    void setWinner(const string &Pwinner);
    void setSecondPlace(const string &PsecondPlace);
    void setThirdPlace(const string &PthirdPlace);
    string getWinner(void);
    string getSecondPlace(void);
    string getThirdPlace(void);
};


ContestResult::ContestResult(void)
{
    winner = "";
    secondPlace = "";
    thirdPlace = "";
}
    
ContestResult::ContestResult(const string &win, 
const string &sec,
const string &third
)
    {
        winner = win;
        secondPlace = sec;
        thirdPlace = third;
}

void ContestResult::setWinner(const string &Pwinner)
{
    winner = Pwinner;
}

void ContestResult::setSecondPlace(const string &PsecondPlace)
{
    secondPlace = PsecondPlace;
}

void ContestResult::setThirdPlace(const string &PthirdPlace)
{
    thirdPlace = PthirdPlace;
}

string ContestResult::getWinner(void)
{
    return winner;
}

string ContestResult::getSecondPlace(void)
{
    return secondPlace;
}

string ContestResult::getThirdPlace(void)
{
    return thirdPlace;
}
