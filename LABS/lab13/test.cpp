#include <iostream>

bool yup(void)
{
    std::cout << "Got here!";
    return true;
}

int main(void)
{
    std::cout << ((1 < 0) && yup()) << "\n";
    std::cout << ((1 > 0) && yup()) << "\n";
    std::cout << ((1 < 0) || yup()) << "\n";
    std::cout << "\u25A0";
    return 0;
}