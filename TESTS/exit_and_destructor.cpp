#include <iostream>
#include <cstring>
#include <cstdlib>


void* operator new(size_t size)
{
    std::cout << "Allocating " << size << " bytes!\n";
    return malloc(size);
}

void operator delete(void* address, size_t size)
{
    std::cout << "Freeing " << size << " bytes\n";
    free(address);
}

void operator delete [](void *ptr, size_t size)
{
    std::cout << "Freeing [] " << size << " bytes\n";
    free(ptr);
}

class dumb
{
private:
    int *array;
    int size;
public:
    dumb(void)
    {
        size = 1;
        array = new int[size];
        memset(array, 0x0, sizeof(int)*size);
    }
    dumb(int Psize)
    {
        size = Psize;
        array = new int[size];
        memset(array, 0x0, sizeof(int)*size);
    }
    ~dumb(void)
    {
        std::cout << "Delete this bitch!\n";
        delete [] array;
        //I have a feeling that because
    }
    int operator[](int index)
    {
        #ifdef DEBUG
        if (index < size && index >= 0)
            return array[index];
        else
        {   
            std::cout << "Index = " << index << "\n";
            std::cout << "Slow down there bucko, "
                      << "that index is not valid!\n"; 
            return 0;
        }
        #else
            return array[index];
        #endif

    }
};

int main(void)
{
    dumb x;
    dumb y(20);
    dumb *z = new dumb(25);
    double *ptr = new double;
    exit(0); //yup, it doesn't run the destructors...
    std::cout << y[20] << "\n";
    std::cout << y[1] << "\n";

    delete z;
    delete ptr;
    return 0;
}