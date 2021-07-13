#include <iostream>


class test
{
    private:
        int a, b;
    public:
        friend std::ostream& operator<<(std::ostream&, const test& obj);

        test()
        {
            a = 42;
            b = 42;
        }
        test (int Pa, int Pb)
        {
            a = Pa;
            b = Pb;
        }

};


int main(void)
{
    test a(1, 2);
    std::cout << a;
    return 0;
}

std::ostream& operator<<(std::ostream& out, const test& obj)
{
    out << "a = " << obj.a << "\n";
    out << "b = " << obj.b << "\n";

    return out;
}
