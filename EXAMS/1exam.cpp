#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class dumb
{
    private:
        int j;
    public:
        dumb()
        {
            a = 42;
            b = 69;
        }
        dumb(int Pa, int Pb = 12)
        {
            a = Pa;
            b = Pb;
            dumb t;
            t.j =12;
        }
        int a, b;
};

int operator++(const dumb& obj, int)
{
    return obj.a;
}
int operator++(dumb& obj)
{
    obj.a += 1;
    return obj.a;
}


void find(int a, int& b, int& c)
{
    int temp;
    c = 2*a - b;
    temp = a;
    a = b;
    b = 3*temp;
}

int func1(int x, int y, int z)
{
    if (x <= y && x <= z)
        return (y + z - x);
    else if (y <= z && y <= x)
        return (z + x - y);
    else
        return (x + y - z);
}

int MyFct(const vector<int>& v)
{
    int i, x;
    x = v.at(0);
    for (int i = 0; i < v.size(); ++i)
    {
        if (v.at(i) > x)
        {
            x = v.at(i);
        }
    }
    return x;
}

int main(void)
{
    vector<int> test = {0, 3, 9, 7, 7};
    cout << MyFct(test);
}

//Question 11 adds a comma
//3711,15
//should be: 371115