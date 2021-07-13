#include <iostream>
#include <vector>

using namespace std;
ostream& operator<<(ostream& out, const vector<int>& vect)
{
  out << "size: " << vect.size();
  out << " capacity: " << vect.capacity() << "\n";
  return out;
}


int main(void)
{
    std::vector<int> hello(42);
    hello.back();
    hello.end();
    std::cout << hello;
}