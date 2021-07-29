#include <cstdlib>
#include <iostream>
#include <sstream>

int main(int argc, char* argv[])
{
    std::ostringstream test;

    std::cout << "\"" << test.str() << "\"";
    return 0;
}