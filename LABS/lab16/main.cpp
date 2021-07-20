#include "matrix.h"
#include <iostream>

int main(void)
{
    const int size = 40;
    Matrix<int, 4, 10> m;
    int y[4][10];
    int x[size];

    m.setMatrix(y);
    m.setMatrix(x);
}