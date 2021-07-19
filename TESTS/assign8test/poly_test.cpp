#include <iostream>
#include <array>

class Base;
class Derived;

class Base
{
public:
    virtual void speak(void) const
    {
        std::cout << "I am base >:)\n";
    }
};

class Derived : public Base
{
public:
    void speak(void) const override
    {
        std::cout << "I am the derived :)))\n";
    }
};

void SpeakPoly(const Base& obj)
{
    obj.speak();
}

template<typename T, typename F> T f(T* a)
{
    std::cout << *a << "\n";
    return 42;
}

template<typename T> T g(int a)
{
    return 42;
}

template <typename T>
class dumber
{
private:
    T *ptr;

public:
    void print(void);
};

template <typename G>
void dumber<G>::print(void)
{
    std::cout << "Yer\n";
}


template<typename T, int SIZE>
int func4(T a)
{
    std::cout << SIZE << "\n";
    return 42;
}


template<typename T>
int DUMBEST(int a)
{
    std::cout << "SMOKE WEED, yum yum donuts\n";
    return 42;
}
int main(void)
{
    DUMBEST<double>(4);
    return 0;
}
