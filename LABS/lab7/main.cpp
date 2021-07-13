#include "complex.h"

int main(void)
{   
    Complex input;

    std::cout << "\nTesting default constructor\n";
    std::cout << Complex() << "\n\n";
    std::cout << "Testing one parameter constructor with input 5\n";
    std::cout << Complex(5) << "\n\n";
    std::cout << "Testing two parameter constructor with input 0, 0\n";
    std::cout << Complex(0, 0) << "\n\n";
    std::cout << "Testing two parameter constructor with input 1, 2\n";
    std::cout << Complex(1, 2) << "\n\n";
    std::cout << "Testing two parameter constructor with input -13, 21\n";
    std::cout << Complex(-13, 21) << "\n\n";
    std::cout << "Testing two parameter constructor with input -3, -4\n";
    std::cout << Complex(-3, -4) << "\n\n";


    std::cout << "Testing addition subtraction and multiplication for "
              << "complex numbers: 10+4i and 5+3i\n";
    std::cout << Complex(10, 4) << " + " << Complex(5, 3) << " = "
              << (Complex(10, 4) + Complex(5, 3)) << "\n";

    std::cout << Complex(10, 4) << " - " << Complex(5, 3) << " = "
              << (Complex(10, 4) - Complex(5, 3)) << "\n";

    std::cout << Complex(10, 4) << " * " << Complex(5, 3) << " = "
              << (Complex(10, 4) * Complex(5, 3)) << "\n\n";

              
    std::cout << "Testing addition subtraction and multiplication for "
              << "complex numbers: -10-4i and -5-3i\n";              
    std::cout << Complex(-10, -4) << " + " << Complex(-5, -3) << " = "
              << (Complex(-10, -4) + Complex(-5, -3)) << "\n";

    std::cout << Complex(-10, -4) << " - " << Complex(-5, -3) << " = "
              << (Complex(-10, -4) - Complex(-5, -3)) << "\n";

    std::cout << Complex(-10, -4) << " * " << Complex(-5, -3) << " = "
              << (Complex(-10, -4) * Complex(-5, -3)) << "\n\n";


    std::cout << "Testing == operator with -10-4i and -5-3i\n";
    std::cout << "Should be false: " 
              << (Complex(-10, -4) == Complex(-5, -3)) << "\n\n";
    std::cout << "Testing == operator with 10+4i and 10+4i\n";
    std::cout << "Should be true: " 
              << (Complex(-10, -4) == Complex(-10, -4)) << "\n\n";


    std::cout << "Testing << and >> operators\n";
    std::cout << "enter imaginary number of form a+bi or a-bi\n";
    std::cin >> input;
    std::cout << input << "\n";
}