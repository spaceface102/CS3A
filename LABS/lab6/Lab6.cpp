/*************************************************************
 * AUTHOR   : Osbaldo Gonzalez Jr., Sasha Saaed-Marmorstein
              Alex Lam
 * LAB #5   : Vectors
 * CLASS    : CS 3A
 * SECTION  : MTRF 9:00 - 11: 50
 * DUE DATE : 7/1/21
*************************************************************/
#include <iostream>
#include <vector>
using namespace std;

//FUNCTION DECLERATIONS/PROTOTYPES
ostream& operator<<(ostream& out,           //IN - output stream
                    const vector<int>& vect //IN - a std::vector<int>
                  );
void DisplaySizeCapacity(const vector<int>& vect  //IN - a std::vector<int>
                        );
void CheckEmpty(const vector<int>& vect     //IN - a std::vector<int>
                );


/*******************************************************************
 * main function
 * _________________________________________________________________
  initializes 3 vectors(v1,v2,v3) one with no arguments 
  one with 1 argument and 1 with 2 arguements 
  runs 3 vectors through a series of changes, outputting the
  results of the changes after each one
  
 * _________________________________________________________________
 * INPUT:
 *    
 *
 * OUTPUT:
 *    - couts vector properties or contents depending on 
      what was changed each time a change happens
 ******************************************************************/

int main() 
{
  vector<int> v1 = vector<int>();     //PROC - default constructor
  vector<int> v2 = vector<int>(5);    //PROC - constructor with one parameter
  vector<int> v3 = vector<int>(5,9);  //PROC - constructor with two parameter
  
  cout<<"Testing default constructor"<<endl; 
  DisplaySizeCapacity(v1);
  cout<<"Testing empty member function"<<endl;
  CheckEmpty(v1);
  cout << "\n";

  cout<<"Testing One parameter constructor"<<endl;
  DisplaySizeCapacity(v2);
  cout<<"Testing empty member function"<<endl;
  CheckEmpty(v2);
  cout<< "Testing at function by displaying v2\n";
  cout << v2 << "\n\n";

  cout<<"Testing Two parameter constructor"<<endl;
  DisplaySizeCapacity(v3);
  cout<<"Testing empty member function"<<endl;
  CheckEmpty(v3);
  cout<<"Testing at function by displaying v3"<<endl;
  cout << v3 << "\n\n";

  cout<<"Testing push back function"<<endl;
  while(v1.size()<10)
  {
    v1.push_back(v1.size());
    DisplaySizeCapacity(v1);
  }

  cout<<"\nTesting pop back function"<<endl;
  v1.pop_back();
  DisplaySizeCapacity(v1);
  v1.pop_back();
  DisplaySizeCapacity(v1);

  cout<<"\nTesting front and back functions"<<endl;
  cout<<"front: "<<v1.front()<<" back: "<<v1.back()<<endl;

  cout<<"\nTesting insert() function by adding at position 5"<<endl;
  v1.insert(v1.begin() + 5, 100);
  cout << v1 << "\n\n";
  cout<<"Testing erase() function by erasing position 6"<<endl;
  v1.erase(v1.begin() + 6);
  cout << v1 << "\n\n";
  
  cout<<"Testing resize() function (one parameter)\n";
  v1.resize(20);
  DisplaySizeCapacity(v1);
  cout<<v1<<endl;
  v1.resize(10);
  DisplaySizeCapacity(v1);
  cout << v1 << "\n\n";

  cout << "Testing resize() function (two parameter)\n";
  v1.resize(20,101);
  DisplaySizeCapacity(v1);
  cout<<v1<<endl;
  v1.resize(10);
  DisplaySizeCapacity(v1);
  cout << v1 << "\n\n";
  
  cout<<"Testing assign() function\n";
  v1.assign(5, 102);
  DisplaySizeCapacity(v1);
  cout << v1 << "\n\n";

  cout << "Testing clear() function\n";
  v1.clear();
  DisplaySizeCapacity(v1);
  cout << "\n";
}
//EOMAIN

/*****************************************************************************
 * FUNCTION operator<<
 *______________________________________________________________________________
 *  Overloads the left shift operator for a std::vector class templated 
 *  with <int> when the left hand side operator is of type std::ostream.
 *  Will just print out the full contents of the vector.
 * _____________________________________________________________________________
 * PRE-CONDITIONS
 *    Passed in vector must be templated with <int>.
 * 
 * POST-CONDITIONS
 *    Ouput will all be on a single line. Seperating character
 *    between vector elements is ' '.
*****************************************************************************/
ostream& operator<<(ostream& out,           //IN - output stream
                    const vector<int>& vect //IN - a std::vector<int>
                  )
{
  for (int i = 0; i < vect.size(); i++)
    cout << vect.at(i) << " ";
  return out;
}
//EOF


/*****************************************************************************
 * FUNCTION DisplaySizeCapacity
 *______________________________________________________________________________
 *  Displays the size and capacity attributes of a std::vector<int>
 * _____________________________________________________________________________
 * PRE-CONDITIONS
 *    Passed in vector must be templated with <int>.
 * 
 * POST-CONDITIONS
 *    Ouput will be formated according to CS3A Lab 5
*****************************************************************************/
void DisplaySizeCapacity(const vector<int>& vect  //IN - a std::vector<int>
                        )
{
  cout << "size: " << vect.size();
  cout << " capacity: " << vect.capacity() << "\n";
}
//EOF

/*****************************************************************************
 * FUNCTION CheckEmpty
 *______________________________________________________________________________
 *  Wraps the .empty() method from std::vector to output if the passed in
 *  vector is empty or not.
 * _____________________________________________________________________________
 * PRE-CONDITIONS
 *    Passed in vector must be templated with <int>.
 * 
 * POST-CONDITIONS
 *    Ouput will be formated according to CS3A Lab 5
*****************************************************************************/
void CheckEmpty(const vector<int>& vect     //IN - a std::vector<int>
                )
{
  if(vect.empty())
    cout<<"v is empty"<<endl;
  else
    cout<<"v is not empty"<<endl;
}
//EOF