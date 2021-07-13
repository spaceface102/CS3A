#include <iostream>
using namespace std;

class Pairs
{
   private:
       int f;
       int s;
   public:
       Pairs( );
       Pairs(int first, int second);
       //other members and friends
       friend istream& operator >>(istream& ins, Pairs& obj);
       friend ostream& operator <<(ostream& outs, const Pairs& obj);
};
 
Pairs::Pairs()
{
   f = 0;
   s = 0;
}

Pairs::Pairs(int first, int second)
{
   f = first;
   s = second;
}

istream& operator>>(istream& ins, Pairs& obj)
{
    ins >> obj.f >> obj.s;
       return ins;
}
 
ostream& operator<<(ostream& outs, const Pairs& obj)
{
    outs << '(' << obj.f << ',' << obj.s << ')';
    return outs;
}

int main(void)
{
    std::cout << Pairs(1,2) << "\n";
    std::cout << Pairs() << "\n";
    std::cout << Pairs(3,8) << "\n";

    Pairs x;
    std::cin >> x;
    std::cout << x << "\n";
    return 0;
}