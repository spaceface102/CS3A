#include "typedec.h"

template<typename T>
void swap(T& a, T& b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}