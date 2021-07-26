#include <iostream>

namespace duh
{
    int x = 42;
} // namespace name


int main(void)
{
    std::cout << duh::x << "\n";
    duh::x = 90;
    std::cout << duh::x << "\n";
}