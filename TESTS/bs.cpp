#include<iostream>
#include <vector>
using namespace std;

void find(int a, int& b, int& c);

int main()
{
    vector<int> h;
    h.push_back(1);
    h.push_back(1);
    h.push_back(20);
    h.push_back(1);
    h.push_back(1);

    h.insert(h.begin()+2, 42);
    cout << h.at(2) << "\n";
}
