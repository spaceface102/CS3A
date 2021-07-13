#include <iostream>
#include <cstdlib>

class dumb
{
    int a;
public:
    bool sameAddress(const dumb& obj)
    {
        return this == &obj;
    }

    dumb(int num = 42) : a(num) {}

    int Get_a(void)
    {
        return a;
    }

    dumb(const dumb& obj)
    {
        std::cout << "We out here! Copying n shit\n";
        a = obj.a;
    }

    dumb& operator =(const dumb& obj)
    {
        std::cout << "We out here using = n shit\n";
        a = obj.a;
        return *this;
    }
};

int main(void)
{
    dumb x(555);
    dumb y(x);
    dumb z = x;

    free((void *)1);
    return 0;
}