#include <iostream>
#include <vector>

using namespace std;

void matrixFill(std::vector<std::vector<int>>& v);
void displayMatrix(const std::vector<std::vector<int>>& v);
void matrixAddition(const std::vector<std::vector<int>>& a,
                    const std::vector<std::vector<int>>& b,
                    std::vector<std::vector<int>>& c);
void matrixMultiplication(const std::vector<std::vector<int>>& a,
                    const std::vector<std::vector<int>>& b,
                    std::vector<std::vector<int>>& c);



int main(void)
{
    vector<vector<int>> a = {{2, 5, 1}, {0, 3, -1}};
    vector<vector<int>> b = {{1, 0, 2}, {-1, 4, -2}, {5, 2, 1}};
    vector<vector<int>> c(2);

    matrixMultiplication(a, b, c);
    displayMatrix(c);
}



void matrixAddition(const std::vector<std::vector<int>>& a,
                    const std::vector<std::vector<int>>& b,
                    std::vector<std::vector<int>>& c)
{
    //first condition checks rows, second condition checks columns
    if ((a.size() != b.size()) || (a.at(0).size() != b.at(0).size()))
        return; //matrices are not the same size.

    for (unsigned long i = 0; i < a.size(); i++)
        for (unsigned long j = 0; j < a.at(i).size(); j++)
            c.at(i).push_back(a.at(i).at(j)+b.at(i).at(j));
}
//EOF

void matrixMultiplication(const vector<vector<int>>& a,
                    const vector<vector<int>>& b,
                    vector<vector<int>>& c)
{
  
  //a.at(0).size() is a's col, b.size() is b's rows
  if ((a.at(0).size() != b.size()))
  {
      cout << "The number of columns of matrix A must be the same as the number of rows of matrix B.\n";
      return; //matrices are not the same size.
  }

  long sum;
  for (unsigned long k = 0; k < a.size(); k++)
  {
    for (unsigned long i = 0; i < b.at(0).size(); i++)
    {
      sum = 0;
      for (unsigned long j = 0; j < b.size(); j++)
      {
        sum += a.at(k).at(j) * b.at(j).at(i);
      }
      c[k].push_back(sum);
    }
  }
}
//EOF

void displayMatrix(const vector<vector<int>>& v)
{
  for(unsigned long i = 0; i < v.size(); ++i)
  {
    for(unsigned long j = 0; j < v[i].size(); ++j)
    {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
}//EOF