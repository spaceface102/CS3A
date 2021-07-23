#include <iostream>
#include <vector>

class Dumb
{
public:
    virtual void speak(int)
        {std::cout << "DUMB\n";}
    virtual void operator=(const Dumb&)
        {std::cout << "=DUMB\n";}
};

class Stupid: public Dumb
{
public:
    void speak(int) override
        {std::cout << "STUPID\n";}
    void operator=(const Stupid& s)
    {
        std::cout << "=STUPID\n";
        Dumb::operator=(s);
    }
    void operator=(const Dumb& d) override
    {
        std::cout
        << "Overriding the mfn Dumb copy constructor\n"
        << "I GO STUPID\n";
    }
};

class Idiot: public Stupid
{
public:
    void speak(int) override
        {std::cout << "IDIOT\n";}
};

int main(void)
{
    
}