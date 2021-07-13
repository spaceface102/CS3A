#include <iostream>
#include <ctype.h>

int main(void)
{
    int sum = 0;
    const char *months[12] = 
    {
        "jan", "feb", "mar",
        "apr", "may", "jun",
        "jul", "aug", "sep",
        "oct", "nov", "dec" 
    };

    for (int i = 0; i < 12; i++)
        std::cout << "*((int *)" 
        << months[i] << ") = "
        << *((int *)months[i]) << "\n";
}