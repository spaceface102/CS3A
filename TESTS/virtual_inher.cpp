#include <iostream>
using namespace std;

class A
{
public:
    virtual void name(void) = 0;
};

//base class I
class B : public A{
public:
        void name() override{
         cout << "This is class A \n";
    }
};

//base class II 
class C : public A{
public:
        void name() override{
         cout << "This is class A \n";
    }
};
 
//derived class
class D: public B, public C{};
 
int main()
{
    D d;
    d.C::name();
 
    return 0;
}