#include <iostream>
#include <string>

class dumb
{
    private:
        int data;
    public:
        int operator+(const dumb &obj);
        int operator+(int a_number);
        int operator++(void); //prefix
        int operator++(int); //postfix (parameter must be of type int)

        int operator+(unsigned aNum);
        int operator+(unsigned long aNum);
        int operator+(short aNum);
        int operator+(char aChar);
        int operator+(float aFloat);
        int operator+(double aFloat);

        int operator+(void);    //unary operator
        int operator-(void);    //unary operator

        bool operator<(int);
        bool operator!=(int);
        friend std::ostream& operator<<(std::ostream &out, const dumb &obj);

        dumb(int number);
        dumb(void);
        ~dumb(void);
};

dumb::dumb(void)
{
    data = 42;
}

dumb::dumb(int number)
{
    data = number; 
}
//EOF

dumb::~dumb(void)
{
    std::cout << "I am fucking crumbling\n";
}
//EOF

int dumb::operator+(const dumb &obj)
{
    return data + obj.data;
}

int dumb::operator+(int a_number)
{
    return data+a_number;
}


int dumb::operator++(void) //prefix
{
    return data+1;
}

int dumb::operator++(int) //postfix
{
    return operator++(); //use the prefix function overload
}

std::ostream& operator<<(std::ostream &out, const dumb &obj) //friend
{
    out << obj.data << "\n";
    out << "hello, I am being overloaded!\n";
    return out;
}

bool dumb::operator<(int number)
{
    return data < number;
}


int dumb::operator+(unsigned aNum)
{
    return 1;
}
int dumb::operator+(unsigned long aNum)
{
    return 2;
}
int dumb::operator+(short aNum)
{
    return 3;
}
int dumb::operator+(char aChar)
{
    return 4;
}
int dumb::operator+(float aFloat)
{
    return 5;
}
int dumb::operator+(double aFloat)
{
    return 6;
}

int dumb::operator+(void)    //unary operator
{
    return 420;
}

int dumb::operator-(void)   //unary operator
{
    return -420;
}

int main(void)
{
    dumb x(420);

    std::cout << x + 42U << "\n";
    std::cout << x + 42UL << "\n";
    std::cout << x + (short)42 << "\n";
    std::cout << x + (char)42 << "\n";
    std::cout << x + 42.0f << "\n";
    std::cout << x + 42.0 << "\n";

    std::cout << "\n\n";
    std::cout << +x << "\n" << -x << "\n";
}