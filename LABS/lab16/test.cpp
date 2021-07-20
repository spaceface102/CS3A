#include <iostream>
#include <time.h>
#include <array>

template<typename T, int MAXROW, int MAXCOL>
class test
{
private:
    T array2d[MAXROW][MAXCOL];
    const int row = MAXROW;
    const int col = MAXCOL;
public:

public:
};

struct TempData
{
public:
    int StationId;
    time_t timeSet;
    double current;
    double maxTemp;
    double minTemp;
};

void DisplayTempData(const TempData& data)
{
    std::cout
    << "Station ID: " << data.StationId << "\n"
    << "time set  : " << data.timeSet << "\n"
    << "current   : " << data.current << "\n"
    << "max temp  : " << data.maxTemp << "\n"
    << "min temp  : " << data.minTemp << "\n\n";
}

struct Foo {
    Foo() {}

    Foo(std::initializer_list<Foo>) {
        std::cout << "initializer list" << std::endl;
    }

    Foo(const Foo&) {
        std::cout << "copy ctor" << std::endl;
    }
};

template<typename T, size_t size_template_param>
class MyArray
{
private:
    T data[size_template_param];

public:


    MyArray(std::initializer_list<T> list)
    {
        size_t i;
        for (i = 0; i < list.size() && i < size_template_param; i++)
            data[i] = *(list.begin()+i);
        for (;i < size_template_param; i++)
            data[i] = 0;
    }

    size_t size(void)
    {
        return size_template_param;
    }

    void print(void)
    {
        for (size_t i = 0; i < size_template_param; i++)
            std::cout << data[i] << " ";
    }

    T operator[](size_t index)
    {
        return data[index];
    }
};

int main(void)
{
    MyArray<int, 10> test = {1, 2, 3, 4, 5, 10, 42, 78, 321, 21932130, 21};
    test.print();
    std::cout << "\n" << test[4] << "\n";
    std::cout << test.size() << "\n";

    int da[0];

    std::cout << "\n";
    return 0;
}