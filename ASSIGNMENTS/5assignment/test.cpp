#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> h(20);
    std::vector<int> g;

    h.clear();
    std::cout 
    << "size:     " << h.size() << "\n"
    << "capacity: " << h.capacity() << "\n\n";

    std::cout 
    << "size:     " << g.size() << "\n"
    << "capacity: " << g.capacity() << "\n\n";

    g.push_back(2);
    std::cout << "\n\n" << g.front() << "\n\n";

    g = h;
    std::cout 
    << "size:     " << g.size() << "\n"
    << "capacity: " << g.capacity() << "\n\n";
    return 0;
}