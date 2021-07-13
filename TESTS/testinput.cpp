#include <iostream>
#include <fstream>

int main(void)
{
    std::basic_ifstream<char> file; //= std::ifstream file;

    std::string temp;
    file.getline(temp.c_str(),3);
    return 0;
}