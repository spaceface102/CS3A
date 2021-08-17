#include "myVector.h"
#include <string>
#include <iostream>

template <typename E>
std::ostream& operator<<(std::ostream& out, MyVector<E> vector)
{
    for (size_t i = 0; i < vector.size() - 1; i++)
        out << vector.at(i) << " ";
    out << vector.at(vector.size() - 1);

    return out;
}

int main(void)
{
    MyVector<int> test(1e9, 42);

    test.push_back(3);
    test.push_back(test.at(0));

    std::cout << test.at(test.size() - 1);
    return 0;
}