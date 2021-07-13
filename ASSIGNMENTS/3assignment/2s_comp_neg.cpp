#include <iostream>
#include <string>

int main(void)
{
    unsigned h = 0;
    int g = ((1<<30)-1);
    
    h -= g;
    if (h>>31)
        std::cout << "0. Negative\n";
    
    if (h&(1<<31))
        std::cout << "1. Negative\n";

    std::cout << "Done\n";
    std::cout << (int)true << " " << (int)false << "\n";

    std::string month = "January";
    const char *cmonth = "January";
    const char *shortMonth = "Jan";
    char another[4] = {'J', 'a', 'n', 0};

    std::cout << *((int *)(&another[0])) << "\n";
    std::cout << *((int *)shortMonth) << "\n";
    std::cout << *((int *)"Jan") << "\n";
    
    return 0;
}