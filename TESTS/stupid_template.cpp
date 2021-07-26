#include <iostream>


template<int i>
class FACTOR
{
public:
    enum {RESULT = i * FACTOR<i - 1>::RESULT};
};

template<>
class FACTOR< 1 >
{
public:
    enum {RESULT = 1};
};



template<int i>
int func(void)
{
    return i*2;
}

template<>
int func<0>(void)
{
    std::cout << "Damn Bucko, wachu doing?";
    return 42;
}


template<long i>
class FIB
{
public:
    enum : unsigned long
    {RESULT = FIB<i - 1>::RESULT + FIB<i - 2>::RESULT};
};

template<>
class FIB<0>
{
public:
    enum : unsigned long
    {RESULT = 0};
};

template<>
class FIB<1>
{
public:
    enum : unsigned long
    {RESULT = 1};
};

int main(void)
{
    std::cout << FIB<200>::RESULT << "\n";
    return 0;
}