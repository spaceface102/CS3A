#include <iostream>
#include <vector>

class my_vector
{
public:
    my_vector(void) : size(0), cap(1)
    {
        data = new int[cap];
        for (int i = 0; i < cap; i++)
            data[i] = int();
    }
    //EOF

    ~my_vector(void)
    {
        delete [] data;
    }

    int& operator[](unsigned index)
    {
        return data[index];
    }
    void push_back(const int& value)
    {
        if (size == cap)
            resize();
        data[size++] = value;
    }
    void reserve(unsigned cap)
    {
        resize(cap);
    }

private:
    int* data;
    unsigned size;
    unsigned cap;

    void resize(void)
    {
        resize(cap*2);
    }

    void resize(unsigned int cap)
    {
        std::cout << "Resizing...\n";
        this->cap = cap;
        int* temp = new int[cap];
        for (int i = 0; i < size; i++)
            temp[i] = data[i];
        delete [] data;
        data = temp;
    }
};

int main(void)
{
    const int SIZE = 100000; //min value for segfault 32763 (at least on my system)

    my_vector v;
    v.reserve(SIZE); //set capacity to SIZE, avoid Reserving

    for (int i = 0; i < SIZE; i++)
        v.push_back(42);

    std::cout << "Next instruction is to push_back(v[0]): \n";
    v.push_back(v[0]);

    return 0;
}