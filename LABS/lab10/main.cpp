#include <iostream>
#include "music_collection.h"

int main(void)
{
    Tune a("a");
    Tune b("b");
    Tune c("c");
    Tune d("d");

    Music_collection A;
    A.add_tune(a);
    A.add_tune(b);
    A.add_tune(c);
    std::cout << "Music_collection A\n";
    std::cout << A << "\n";

    Music_collection B(A);
    B.set_tune(2, d);
    std::cout << "Music_collection B\n";
    std::cout << B << "\n";
    std::cout << "Music_collection A\n";
    std::cout << A << "\n";

    Music_collection C;
    C = B;
    B.add_tune(a);
    C.set_tune(0, d);

    std::cout << "= operator\n";
    std::cout << "A: \n" << A;
    std::cout << "B:\n" << B;
    std::cout << "C: \n" << C << "\n";
    return 0;
}