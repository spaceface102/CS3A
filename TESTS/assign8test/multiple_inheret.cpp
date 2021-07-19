#include <iostream>

class dumb
{
public:
    void test(void)
    {
        std::cout << "DUMB\n";
    }

    dumb()
    {
        std::cout << "Entering Dumb\n";
    }

    virtual ~dumb()
    {
        std::cout << "Leaving Dumb\n";
    }
};

class idiot
{
public:
    void test(void)
    {
        std::cout << "IDIOT\n";
    }
};

class stupid : public dumb, public idiot
{
public:
    void test(double a, int b, char c)
    {
        std::cout << "STUPID\n";
    }
    void test()
    {
        std::cout << "I am lazy!\n";
    }
};

class Sky
{
protected:
    Sky() = default;
    Sky(int c)
    {
        std::cout << c << " Entering the sky.\n";
    }
    ~Sky()
    {
        std::cout << "Leaving the sky.\n";
    }
};

class Ground : public dumb, private Sky
{
public:
    Ground()
    {
        std::cout << "Default Ground.\n";
    }

    Ground(int x) : Sky(x)
    {   
        std::cout << x << " Entering the Ground.\n";
    } 
    ~Ground()
    {
        std::cout << "Leaving the Ground.\n";
    }
};

int main(void)
{
    stupid yuh;
    yuh.test();
    return 0;
}