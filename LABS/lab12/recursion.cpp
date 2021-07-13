#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

int sum(int n)
{
  if(n<=1)
    return 1;
  else 
    return n + sum(n-1);
}

//Problem 2
int findmin(const int a[], int n)
{
    if (n == 1)
        return a[0];
    
    int result;
    
    //can replace "result" with findmin(a, n - 1)
    //every single place "result" appears, and
    //although it makes the total recursive call
    //use significantly more memory, if not used,
    //have to do a recursive call twice, within 
    //every call of the function.
    //This is unecessary since I'm only comparing
    //the value and then returning said value.
    result = findmin(a, n - 1);
    if (result < a[n - 1])
        return result;
    else
        return a[n - 1];
}

//Problem 4
bool ispalindrome(const char a[], int n)
{
    if (n <= 0)
        return true;

    if (a[n-1] == a[0])
        return ispalindrome(a+1,  n-2);
    else
        return false;
}


//Problem 5
void recursive_substring(string s, vector<string>& substrings)
{
    if (s.size() == 0)
        return;
    
    substrings.push_back(s);
    s.pop_back();
    recursive_substring(s, substrings);
}

vector<string> generate_substrings(string s)
{
    vector<string> substrings;
    for (int i = 0; i < s.size(); i++)
        recursive_substring(s.substr(i, s.size()), substrings);

    substrings.push_back("");
    return substrings;
}

//Problem 6
void drawPattern(int n)
{
    if (n == 0)
        return;
    
    for (int i = 0; i < n; i++)
        cout << '*';
    cout << "\n";
    drawPattern(n - 1);
    for (int i = 0; i < n; i++)
        cout << '*';
    cout << "\n";
}

int main() 
{
    std::array<int, 10> test;
    int array[5] = {9, 213, 321, 42, 8888};
    std::cout << findmin(array, 5);
}
