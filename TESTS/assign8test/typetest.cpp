#include "typedef.cpp"
#include <iostream>

int main(void)
{
    int a, b;
    a = 1, b = 4;
    std::cout << a << " " << b << "\n";
    swap(a, b);
    std::cout << a << " " << b << "\n";
}