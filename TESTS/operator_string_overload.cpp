#include <string>
#include <iostream>

bool operator>(const std::string& lhs, const std::string& rhs);

int main(void)
{
    std::string lhs = "abc";
    std::string rhs = "ABC";

    std::cout << (lhs < rhs) << "\n";
    return 0;
}

bool operator>(const std::string& lhs, const std::string& rhs)
{

}