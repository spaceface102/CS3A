#include <iostream>
#include <string>

int main(void)
{
    struct test
    {
        int a;
        int b;
    }   hello;

    hello.a = 42;
    std::cout << hello.a << "\n";  
    std::cout << std::stod("-3.14") << "\n";
    return 0;
}