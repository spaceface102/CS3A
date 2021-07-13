#include <iostream>
#include "intVector.h"

std::ostream& operator<<(std::ostream& out, const IntVector& obj);
void HyperGradeOutput(const IntVector& obj, const char* vectorName);
int main() 
{
  IntVector def;
  IntVector one(5);
  IntVector two(5, 9);

  std::cout << "Testing default constructor\n";
  HyperGradeOutput(def, "v");

  std::cout << "Testing one parameter constructor\n";
  HyperGradeOutput(one, "v1");

  std::cout << "Testing two parameter constructor\n";
  HyperGradeOutput(two, "v3");
}

std::ostream& operator<<(std::ostream& out, const IntVector& obj)
{
  for (long i = 0; i < obj.size(); i++)
    out << obj.at(i) << " ";
  return out;
}
//EOF

void HyperGradeOutput(const IntVector& obj, const char* vectorName)
{
  std::cout << "size: " << obj.size() << "\t" 
  << "capacity: " << obj.capacity() << "\n";
  std::cout << "Testing empty member function\n";
  if (obj.empty())
    std::cout << vectorName << " is empty\n";
  else
  {
    std::cout << vectorName << " is not empty\n";
    std::cout << "Testing at function by displaying "
    << "contents of " << vectorName <<"\n";
    std::cout << obj << "\n";
  }
  std::cout << "\n\n";
}