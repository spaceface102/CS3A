#include "intVector.h"
#include <cstring>
#include <cstdlib>

/****************************************************************
 * 
 *  Method Constructor: Class IntVector      //DEFAULT CONSTRUCTOR
 * --------------------------------------------------------------
 * Sets size and capacity to 0. data is set to nullptr
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must make an object, or call the constructor with no
 *      arguments.
 * 
 *  POST-CONDITIONS
 *      The object does not have any space to store anyhthing
 *      yet
****************************************************************/
IntVector::IntVector()
{
  sz = 0;
  cap = 0;
  data = nullptr;
}
//EOF

/****************************************************************
 * 
 *  Method Constructor: Class IntVector      //CONSTRUCTOR
 * --------------------------------------------------------------
 * Takes unsigned size arg and sets it to both capacity and size.
 * allocate array of int equivalent to size, and set it to all 0s.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must make an object, or call the constructor with no
 *      arguments.
 * 
 *  POST-CONDITIONS
 *      The object's sz = size as well as cap = size.
****************************************************************/
IntVector::IntVector(unsigned size)
{
  sz = size;
  cap = size;
  data = new int[cap];
  memset(data, 0x0, sizeof(int)*cap);
}
//EOF

/****************************************************************
 * 
 *  Method Constructor: Class IntVector      //CONSTRUCTOR
 * --------------------------------------------------------------
 * Takes unsigned size arg and sets it to both capacity and size.
 * allocate array of int equivalent to size. All the array indices
 * are then set to the int value passed int.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must make an object, or call the constructor with no
 *      arguments.
 * 
 *  POST-CONDITIONS
 *      The object's sz = size as well as cap = size. All the
 *      values in the private data attribute are set to value.
****************************************************************/
IntVector::IntVector(unsigned size, int value)
{
  sz = size;
  cap = size;
  data = new int[cap];
  for (long i = 0; i < size; i++)
    data[i] = value;
}
//EOF

/****************************************************************
 * 
 *  Method Destructor: Class IntVector      //Destructor
 * --------------------------------------------------------------
 * Frees all the dynamically allocated memory assoicated with
 * the class.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Object must get out of scope or must use the delete
 *      operator on a pointer to a IntVector object.
 * 
 *  POST-CONDITIONS
 *      The pointer to the private data attirbute is set to
 *      nullptr after done with the destructor.
****************************************************************/
IntVector::~IntVector()
{
  if (data != nullptr)
    delete [] data;
  data = nullptr;
}

/****************************************************************
 * 
 *  Method size: Class IntVector      //Public
 * --------------------------------------------------------------
 *  Returns the size of the object, aka all the indices filled
 *  with data.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must call method on an object; not a static method.
 * 
 *  POST-CONDITIONS
 *      The object's state will not be modified whatsoever.
****************************************************************/
unsigned IntVector::size() const
{
  return sz;
}
//EOF

/****************************************************************
 * 
 *  Method capacity: Class IntVector      //Public
 * --------------------------------------------------------------
 *  Returns the capacity of the object, aka the ammount of
 *  memory allocated.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must call method on an object; not a static method.
 * 
 *  POST-CONDITIONS
 *      The object's state will not be modified whatsoever.
****************************************************************/
unsigned IntVector::capacity() const
{
  return cap;
}
//EOF

/****************************************************************
 * 
 *  Method empty: Class IntVector      //Public
 * --------------------------------------------------------------
 *  Returns a boolean defining if the vector is empty
 *  (priavte attribute sz).
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must call method on an object; not a static method.
 * 
 *  POST-CONDITIONS
 *      The object's state will not be modified whatsoever.
****************************************************************/
bool IntVector::empty() const
{
  return sz == 0;
}
//EOF

/****************************************************************
 * 
 *  Method at: Class IntVector      //Public
 * --------------------------------------------------------------
 *  Returns a const reference to the data associated with the
 *  index passed in. If the index is greater than or equal to 
 *  size, the program will just simply exit, using exit(0).
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must call method on an object; not a static method.
 *      Index should be less than or equal to private attribute sz
 * 
 *  POST-CONDITIONS
 *      The object's state will not be modified whatsoever if
 *      the index is passed in within the bounds.
 *      Else, the memory allocated (if memory is allocated)
 *      is freed and the program exits.
****************************************************************/
const int& IntVector::at(unsigned index) const
{
  if (index >= sz)
  {
    if (data != nullptr)
      delete [] data; //free memory before exiting
    exit(0);
  }

  return data[index];
}