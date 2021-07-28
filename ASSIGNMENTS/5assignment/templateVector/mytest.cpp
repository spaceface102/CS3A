#include "myVector.h"
#include <iostream>
#include <string>

template<typename E>
std::ostream& operator<<(std::ostream& out, const MyVector<E>& obj)
{
    for (unsigned long i = 0; i < obj.size(); i++)
    {
        out << obj.at(i) << ", ";
    }

    out << "\n";
    return out;
}

int main(void)
{
    MyVector<MyVector<MyVector<int>>> test(4);

    for (long i = 0; i < 4; i++)
    {
        for (long k = 0; k < 3; k++)
        {
            test.at(i).push_back(MyVector<int>());
            for (long q = 0; q < 3; q++)
                test.at(i).at(k).push_back((i*9) + (k*3) + q);
        }
    }

    std::cout << test;

    std::cout << std::string(5, '\n');
    MyVector<int> test1(10);
    std::cout << test1 << "\n";

}