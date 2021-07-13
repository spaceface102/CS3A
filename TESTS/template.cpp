#include <iostream>
#include <vector>

class dumb
{
private:
    int number;
public:
    dumb(int num = 42)
    {
        number = num;
    }

    bool operator >(const dumb& obj) const
    {
        static int count = 1;
        std::cout << count << ". dumb class operator >, rhs is a const dumb&\n";
        count++;
        return number > obj.number;
    }

    bool operator <(const dumb& obj) const
    {
        static int count = 1;
        std::cout << count << ". dumb class operator <, rhs is a const dumb&\n";
        //return obj > *this; even though a nice short cut, don't want to
        //output the message related with operator >
        count++;
        return number < obj.number;
    }

    bool operator >(int _number)
    {
        static int count = 1;
        std::cout << count << ". dumb class operator >, rhs is an int\n";
        count++;
        return number > _number;
    }

    bool operator <(int _number)
    {
        static int count = 1;
        std::cout << count << ". dumb class operator <, rhs is an int\n";
        count++;
        return number < _number;
    }

    int GetNumber(void) const
    {
        return number;
    }
};



template <typename T>
T max(T x, T y)
{
    return (x > y) ? x : y;
}
//EOF

template <typename T>
T min(T x, T y)
{
    return (x < y) ? x : y;
}
//EOF

std::ostream& operator <<(std::ostream& out, const dumb& obj)
{
    out << obj.GetNumber();
    return out;
}

template <typename T>
bool operator <(const std::vector<T>& lhsV, const std::vector<T>& rhsV)
{
    if (lhsV.empty() || rhsV.empty())
    {
        std::cout << "One of the vectors is empty!\n";
        return false; //error
    }
    
    return lhsV.at(0) < rhsV.at(0);
}
//EOF

template <typename T>
bool operator >(const std::vector<T>& lhsV, const std::vector<T>& rhsV)
{
    return rhsV < lhsV;
}

template <typename T, typename U>
void operator >(const T& lhs, const U& rhs)
{
    static int count = 1;
    std::cout << count << ". operator > for any two general types!\n"; 
    count++;
}

template <typename T, typename U>
void operator <(const T& lhs, const U& rhs)
{
    static int count = 1;
    std::cout << count << ". operator < for any two general types!\n";
    count++;
}

template <typename T, typename U>
void operator !=(const T& lhs, const U& rhs)
{
    static int count = 1;
    std::cout << count << ". operator != for any two general types!\n"; 
    count++;
}

void operator >(int number, const dumb& obj)
{
    static int count = 1;
    std::cout << count << ". operator > for a lhs int and a rhs const dumb&!\n";
    count++;
}

int main(void)
{
    int* x = nullptr;
    432.0 > dumb(20);
    3 > dumb(30); //> lhs int rhs const dumb&
    3U > dumb(30); //gen since 3 is now an unsigned int
    3L > dumb(434);
    '\3' > dumb(434);
    (short)3 > dumb(3);
    3.0 > dumb(); //if the templated > is not defined, will use the int overload... intresting
    struct hello
    {
        int a;
    } g;
    g > 3;
    g > dumb();
    3 != dumb(336); //gen
    dumb() != 42; //gen
    dumb(30) > 3;  //> dumb rhs int
    dumb(50) > dumb(); //> dumb rhs const dumb&
    dumb() < dumb(50); //< dumb rhs const dumb&
    3 < dumb(); //gen
    return 0;
}