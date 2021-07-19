#include <iostream>

using namespace std;

class dumb
{
public:
    void say(void)
    {
        cout << "DUMB";
    }
};

class stupid : public dumb
{
public:
};

double PowerRecPos(double base, int power)
{
    if (power == 0)
        return 1;
    return base * PowerRecPos(base, power - 1);
}

double PowerRecNeg(double base, int power)
{
    if (power == 0)
        return 1;
    return (1/base)*PowerRecNeg(base, power + 1);
}

double Power(double base, int power)
{
    if (power >= 0)
        return PowerRecPos(base, power);
    else
        return PowerRecNeg(base, power);
}

int main(void)
{
    double base;
    int power;

    std::cin >> base >> power;
    std::cout << Power(base, power) << "\n";
}