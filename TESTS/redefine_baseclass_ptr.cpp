#include <iostream>

class dumb
{
public:
    virtual void speak(void)
        {std::cout << "dumb class speak\n";}
};

class stupid : public dumb
{
public:
    void speak(void) override
        {std::cout << "stupid class speak\n";}
    virtual void speak(int)
        {std::cout << "stupid class speak INT\n";}
};


class idiot : public stupid
{
public:    
    void speak(int) override
        {std::cout << "idiot class speak\n";}
};

int main(void)
{
    idiot test;
    stupid* sptr;
    dumb*   dptr;

    sptr = &test;
    dptr = &test;
    
    test.speak(42);
    sptr->speak(4);
    dptr->speak();
    return 0;
}