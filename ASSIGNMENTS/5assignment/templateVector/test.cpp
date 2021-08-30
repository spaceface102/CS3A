#include <iostream>

const int size = 10000;
int main(void)
{
    int *old = new int[size];

    for (int i = 0; i < 5; i++)
        old[i] = 42;

    int& ref = old[0];
    int *nw = new int[size*2];

    for (int i = 0; i < 5; i++)
        nw[i] = old[i];
    
    std::cout << "Old before switching pointer: " << old << "\n";
    std::cout << "Nw address: " << nw << "\n";

    delete [] old;
    old = nw;

    std::cout << "\n";
    std::cout << "Old after switching pointer: " << old << "\n";
    std::cout << "Nw address: " << nw << "\n";
    std::cout << "Address of ref: " << &ref << "\n";
 
    old[0] = 9;
    std::cout << "Old[0]: " << old[0] << "\n";
    std::cout << "Old[1]: " << old[1] << "\n";
    std::cout << "Ref: " << ref << "\n";

    delete [] old;
    return 0;
}

void resize(void)
{

}

void push_back(const int& data)
{
    int *o;
    int cap;
    int size;

    if (size + 1 > cap)
        resize();
    int x = data;
    o[size] = x;
}