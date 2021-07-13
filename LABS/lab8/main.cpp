/*****************************************************************************
 * AUTHOR   : Osbaldo Gonzalez Jr. && Zimin Yang
 * LAB #6   : 2D Vectors
 * CLASS    : CS 3A
 * SECTION  : 71206
 * DUE DATE : 6/21/2021
*****************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

/*****************************************************************************
*
* 2D Vector (Matrix)
*_________________________________________________
* This program practices the used of 2D Vectors in
* a matrix addition & multiplication application.
*_________________________________________________
* INPUT:
*   a:        The first matrix
*   b:        The second matrix
* OUTPUT:
*   sum:      Sum of the two provided matrix
*   product:  Product of the two provided matrix
******************************************************************************/

void matrixFill(vector<vector<int>>& v);
void displayMatrix(const vector<vector<int>>& v);
void matrixAddition(const vector<vector<int>>& a,
                    const vector<vector<int>>& b,
                    vector<vector<int>>& c);
void matrixMultiplication(const vector<vector<int>>& a,
                    const vector<vector<int>>& b,
                    vector<vector<int>>& c);

/*****************************************************************************
 * FUNCTION matrixFill
 *____________________________________________________________
 * Fills in a passed in a 2D int vector by reference, through
 * the std::istream, std::cin. No output is done in this func.
 *_____________________________________________________________
 * PRE-CONDITIONS
 *  The function will only fill values of the vector
 *  if there has been already a preallocated size.
 *  Each sub vector in the 2D vector should be of the
 *  EXACT same size
 *
 * POST-CONDITIONS
 *  The size of the passed in vector will not change.
 *  Therefore the rows and columns, will be the same
 *  before and after. What will be modified are the values
 *  at each of the indicies.
****************************************************************************/
void matrixFill(vector<vector<int>>& v //IN - vector to fill values with
                )
{
  for(unsigned long i = 0; i < v.size(); ++i)
  {
    for(unsigned long j = 0; j < v[0].size(); ++j)
    {
      cin >> v[i][j];
    }
  }
}
//EOF

/*****************************************************************************
 * FUNCTION displayMatrix
 *____________________________________________________________
 * Simply goes through the rows and columns of a 2D int
 * vector and displays each number. Each row gets their own
 * line. Output goes to std::cout
 *_____________________________________________________________
 * PRE-CONDITIONS
 *  The function will only display values of the vector
 *  if it has already been filled
 *  Each sub vector in the 2D vector should be of the
 *  EXACT same size.
 *
 * POST-CONDITIONS
 *  The vector is not modified/is left untouched.
****************************************************************************/
void displayMatrix(const vector<vector<int>>& v //IN -vector to display values
                  )
{
  for(unsigned long i = 0; i < v.size(); ++i)
  {
    for(unsigned long j = 0; j < v[i].size(); ++j)
    {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
}
//EOF

/*****************************************************************************
 * FUNCTION matrixAddition
 *____________________________________________________________
 * Three vectors are passed in, a, b, and c. The operation
 * done is a + b and the new resulting vector is then pushed
 * into the c vector.
 *_____________________________________________________________
 * PRE-CONDITIONS
 *  All three vectors must be of the same size. 
 *
 * POST-CONDITIONS
 *  Both a and b are untouched, and c is modified. Nothing is
 *  returned and c is modified by reference. 
****************************************************************************/
void matrixAddition(const vector<vector<int>>& a, //IN - left operand
                    const vector<vector<int>>& b, //IN - right operand
                    vector<vector<int>>& c //IN/OUT - result of operation
                    )
{
  //first condition checks rows, second condition checks columns
  if ((a.size() != b.size()) || (a[0].size() != b[0].size()))
    return; //matrices are not the same size.

  for (unsigned long i = 0; i < a.size(); ++i)
  {
    for (unsigned long j = 0; j < a[i].size(); ++j)
    {
      c[i][j] = a[i][j]+ b[i][j];
    }
  }
}
//EOF

/*****************************************************************************
 * FUNCTION matrixAddition
 *____________________________________________________________
 * Three vectors are passed in, a, b, and c. The operation
 * done is a * b and the new resulting vector is then pushed
 * into the c vector.
 *_____________________________________________________________
 * PRE-CONDITIONS
 *  The vector "a" should have as many columns as "b" has rows.
 *  c's rows =  a's rows and c's columns =  b's columns
 * POST-CONDITIONS
 *  Both a and b are untouched, and c is modified. Nothing is
 *  returned and c is modified by reference. 
****************************************************************************/
void matrixMultiplication(const vector<vector<int>>& a, //IN - left operand
                    const vector<vector<int>>& b, //IN - right operand
                    vector<vector<int>>& c  //IN/OUT - result of operation
                    )
{
  //a.at(0).size() is a's col, b.size() is b's rows
  if ((a[0].size() != b.size()))
  {
      return; //matrices are not the same size.
  }

  for (unsigned long i = 0; i < a.size(); i++)
  {
    for (unsigned long j = 0; j < b[0].size(); j++)
    {
      c[i][j] = 0;
      for (unsigned long k = 0; k < b.size(); k++)
      {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }
}
//EOF

int main()
{
  int row;    //IN - the number of rows in a 2D vector
  int column; //IN - the number of columns in a 2D vector
  int row_a;  //IN - num of rows for vector a
  int row_b;  //IN - num of rows for vector b
  int col_a;  //IN - num of cols for vector a
  int col_b;  //IN - num of cols for vector b

  cout << "Enter the number of rows and columns of the matrices to add: ";
  cin >> row >> column;


  vector<vector<int>> a(row, vector<int>(column));
  
  cout << "Enter matrix A: ";
  matrixFill(a);
  cout << "For matrix A you entered: ";
  displayMatrix(a);


  vector<vector<int>> b(row, vector<int>(column));
  
  cout << "Enter matrix B: ";
  matrixFill(b);
  cout << "For matrix B you entered: ";
  displayMatrix(b);



  vector<vector<int>> sum(row, vector<int>(column));

  matrixAddition(a, b, sum);
  cout << "sum of A and B is: ";
  displayMatrix(sum);

  cout << "\n\n";



  cout << "Now for multiplication.\n";
  a.clear();
  b.clear();

  while(true)
  {
    cout << "Enter the number of rows and columns of matrix A: ";
    cin >> row_a >> col_a;
    cout << "Enter the number of rows and columns of matrix B: ";
    cin >> row_b >> col_b;

    if(col_a != row_b)
    {
      cout << "The number of columns of matrix A must be the same as the number of rows of matrix B.\n";
    }
    else
    {
      break;
    }
  }

  a.resize(row_a, vector<int>(col_a));
  b.resize(row_b, vector<int>(col_b));

  cout << "Enter matrix A: ";
  matrixFill(a);
  cout << "For matrix A you entered: ";
  displayMatrix(a);

  cout << "Enter matrix B: ";
  matrixFill(b);
  cout << "For matrix B you entered: ";
  displayMatrix(b);

  vector<vector<int>> product(row_a, vector<int>(col_b));

  matrixMultiplication(a, b, product);
  cout << "product of A and B is: ";
  displayMatrix(product);
  
  return 0;
}

//EOF