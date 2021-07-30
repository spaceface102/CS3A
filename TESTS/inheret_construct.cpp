#include <iostream>

using std::cout;
using std::string;
using std::endl;

class First
{
    private:
        int a;
    public:
        First( int x = 1)
        { 
            a = x; 
            std::cout << "First constructor\n";    
        }

        virtual void twist()
            {  a *= 2;}

        int getVal()
            { twist(); return a; }
};

class Second : public First
{
    private:
        int b;
    public:
        Second(int y = 5)
        { 
            b = y;
            std::cout << "Second constructor\n";
        }
        virtual void twist()
            { b *= 10; }
};

int prob13(void)
{
    First object1;
    Second object2;
    First* test;

    test = &object2;
    cout << object1.getVal() << endl;
    cout << object2.getVal() << endl;
    cout << test->getVal() << "\n";
    return 0;
}

class IntVector{
    private:
        unsigned sz;
        unsigned cap;
        int *data;        
    public:
        IntVector();
        IntVector( unsigned size );
        IntVector( unsigned size, int value );
        ~IntVector();
    void doublesArray();
    void appendDouble(void);
};

void IntVector::appendDouble(void)
{
    unsigned oldSize;
    int *tempArray;

    if (sz*2 > cap)
    {
        oldSize = sz;
        sz *= 2;
        tempArray = new int[sz];
        for (unsigned i = 0; i < oldSize; i++)
            tempArray[i] = data[i];
        for (unsigned i = oldSize, k = 0; i < sz; i++, k++)
            tempArray[i] = data[k]*2;
        
        delete [] data;
        data = tempArray;
    }
    else
    {
        for (unsigned i = sz, k = 0; i < sz*2; i++, k++)
            data[i] = data[k]*2;
        sz *= 2;
    }
}


class yeyo
{
public:
    yeyo(void) = default;
    yeyo(int);
};

int atest_0(void)
{
    yeyo test;    
    return 0;
}


 class Name
 {
 public:
     string firstName;
     char mi;
     string lastName;
 
    Name(void) = default;
     Name(string firstName1, char mi1, string lastName1)
     {
         firstName = firstName1;
         mi = mi1;
         lastName = lastName1;
     }
 };

template<typename T>
void swap(T& var1, T& var2)
{
    T temp = var1;
    var1 = var2;
    var2 = temp;
}

template<typename T = int>
class Stack
{
public:
  Stack() = default;
};

 class ParentClass
 {
 public:
     int id;
     ParentClass(int id)
     {
         this->id = id;
     }
     void print()
     {
         cout << id << endl;
     }
 };

 class ChildClass: public ParentClass
 {
 public:
     int id;
     ChildClass(int id): ParentClass(1)
     {
         this->id = id;
     }
 };

using std::cin;

int main()
{
    // Read two integers
    cout << "Enter two integers: ";
    int number1, number2;
    cin >> number1 >> number2;
    try
    {
        if (number2 == 0)
            throw number1;
        cout << number1 << " / " << number2 << " is "
             << (number1 / number2) << endl;
        cout << "C" << endl;
    }
    catch (int e)
    {
        cout << "A" << endl;
    }
    cout << "B" << endl;
 
    return 0;
}