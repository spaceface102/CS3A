#include <iostream>

class test
{
public:
    std::string hello(std::string yeah)
    {
        return "hello world";
    }
    std::string hello(std::string &yeah)    //note if you try use an rvalue, there will be error
    {
        return "hello world";
    }
    std::string hello(const std::string &yeah)  //there will be no error if you try to use rvalue,
                                                //const qualifer on std::string does some magic here
    {
        return "hello world";
    }

  
/*
    const std::string& hello(int yeah)
    {
        return "hello world";
    }
    NOPE NVM, the comment made below about this being kosher
    is WRONG!

    g++ lvalue_rvalue.cpp
    lvalue_rvalue.cpp: In member function ‘const string& test::hello(int)’:
    lvalue_rvalue.cpp:21:16: warning: returning reference to temporary [-Wreturn-local-addr]
    21 |         return "hello world";
        |                ^~~~~~~~~~~~~
    lvalue_rvalue.cpp: In function ‘const int& GetValue()’:
    lvalue_rvalue.cpp:38:12: warning: returning reference to temporary [-Wreturn-local-addr]
    38 |     return 10;
        |            ^~
*/

/*
    std::string& hello(double yeah)
    {
        //note, that without the const qualifier on 
        //the std::string reference, there is an error
        //with it though, as you see above, everything
        //is kosher.
        return "hello world"; 
    }
*/
};

/*
const int& GetValue(void)
{
    return 10;
}
    yeah... this bih don't work...
*/

int& integerValue(void)
{
    static int x = 4;
    return x;
}

int* integerValue2(void)
{
    static int x = 420;
    return &x;
}


class dumb
{
    private:
        int a,b;
    public:
        dumb() {a = 0; b = 0;}
        dumb(int Pa, int Pb) : a(Pa), b(Pb) {}
        
        dumb operator+(const dumb& obj);    //this will technically accept both lvalues and 
                                            //rvalues fine, but since we have defined an overload
                                            //using dumb&&, any rvalue will use the other version

        dumb operator+(dumb&& obj);         //only accepts rvalues! lvalues can not and will not
                                            //use this overload of the method. Define to only use
                                            //lvalues by using dumb&&
        friend std::ostream& operator<<(std::ostream& out, const dumb& obj);
};

std::ostream& operator<<(std::ostream& out, const dumb& obj)
{
    out << "a = " << obj.a << "\n" << "b = " << obj.b << "\n";
    return out;
}

dumb dumb::operator+(dumb&& obj)
{
    return dumb(42, 42);
}

dumb dumb::operator+(const dumb& obj)
{
    return dumb(2, 3);
}

int main(void)
{
    //lvalues have both a value and an address where the value is stored at (a variable)
    //rvalues only have a value. They are temporary/literals. They are used to set the
        //value of an lvalue

    std::cout << integerValue() << "\n";
    integerValue() = 42;    
    //intresting, since we are returning a reference to a static 
    //variable inside the integerValue function, even though 
    //usually functions return a rvalue, since it is a reference
    //we can return an lvalue which can be modified.
    //Therefore, we can change the value of the static variable 
    //outside of the function!
    std::cout << integerValue() << "\n";

    //I think this will work similarly for pointers
    std::cout << *integerValue2() << "\n";
    *integerValue2() = 90;
    std::cout << *integerValue2() << "\n";
    //yup. ahh pointers, you are just so predictable at small scale

    //int& a = 10; can't set an lvalue reference using an rvalue unless...
    const int& a = 10;
    //a = 21; //note, now I can not modify the value, but what is happening is:
    //More or less the compiler looks at:
    //const int& a = 10; //10 is an rvalue, so this would not work, therefore
    //int temp g = 10; //it probably puts something like this on top

    //therefore this:
    int g = 10;
    const int& d = g; 

    //is equivalent to:
    const int& e = 10;  //of course, g and the new compiler temp variable may have 
                        //different adderess, but since it's a reference, this 
                        //doesn't really matter!
    //Note, this is why it is also nice to pass in std::string to functions
    //as const std::string& ,because it would be fine to use both lvalues and rvalues!


    //testing out the rvalue specific method in Class dumb
    dumb temp;
    std::cout << "\n\n\n"; //spacer
    std::cout << "rvalue + rvalue:\n" << dumb() + dumb();   //will use the dumb&& rvalue version of the operator overload
    std::cout << "rvalue + lvalue:\n" << dumb() + temp;     //will use the const dumb& lvalue/rvalue version of the operator overload
    std::cout << "lvalue + rvalue\n"  << temp + dumb();     //will use the dumb&& rvalue version of the operator overload 
    std::cout << "lvalue + lvalue\n" << temp + temp;        //will use the const dumb& lvalue/rvalue version of the operator overload
    return 0;
}