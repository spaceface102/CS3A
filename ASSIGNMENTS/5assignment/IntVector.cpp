/****************************************************************
 * AUTHOR           : Osbaldo Gonzalez Jr.
 * ASSIGNMENT 05    : IntVector
 * CLASS            : CS 3A
 * SECTION          : 71206
 * DUE DATE         : 7/7/2021
****************************************************************/
#include "IntVector.h"
#include <cstdlib>

/****************************************************************
 * 
 *  Method Constructor: Class IntVector
 *  //DEFAULT CONSTRUCTOR
 * --------------------------------------------------------------
 * Sets size and capacity to 0. data is set to nullptr
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must make an object, or call the constructor with no
 *      arguments.
 * 
 *  POST-CONDITIONS
 *      The object does not have any space to store anything
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
 *  Method Constructor: Class IntVector
 *  //CONSTRUCTOR
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
    for (long i = 0; i < sz; i++)
        data[i] = 0;
}
//EOF

/****************************************************************
 * 
 *  Method Constructor: Class IntVector
 *  //CONSTRUCTOR
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
 *  Method Destructor: Class IntVector
 *  //DESTRUCTOR
 * --------------------------------------------------------------
 * Frees all the dynamically allocated memory associated with
 * the class.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Object must get out of scope or must use the delete
 *      operator on a pointer to a IntVector object.
 * 
 *  POST-CONDITIONS
 *      The pointer to the private data attribute is set to
 *      nullptr after done with the destructor.
****************************************************************/
IntVector::~IntVector()
{
    delete [] data;
    data = nullptr;
}

/****************************************************************
 * 
 *  Method size: Class IntVector
 *  //PUBLIC
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
 *  Method capacity: Class IntVector
 *  //PUBLIC
 * --------------------------------------------------------------
 *  Returns the capacity of the object, aka the amount of
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
 *  Method empty: Class IntVector
 *  //PUBLIC
 * --------------------------------------------------------------
 *  Returns a boolean defining if the vector is empty
 *  (private attribute sz).
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
 *  Method at: Class IntVector
 *  //PUBLIC
 * --------------------------------------------------------------
 *  Returns a const reference to the data associated with the
 *  index passed in. If the index is greater than or equal to 
 *  size, the program will just simply exit, using exit(1).
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
        delete [] data; //free memory before exiting
        exit(1);
    }

    return data[index];
}
//EOF

/****************************************************************
 * 
 *  Method at: Class IntVector
 *  //PUBLIC
 * --------------------------------------------------------------
 *  Returns a reference to the data associated with the
 *  index passed in. If the index is greater than or equal to 
 *  size, the program will just simply exit, using exit(1).
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must call method on an object; not a static method.
 *      Index should be less than or equal to private attribute sz
 * 
 *  POST-CONDITIONS
 *      The returned refernce, if modified, will see the
 *      modification seen in the object, since it now using
 *      a reference without a const qualifer. Therefore can
 *      use the assignment operator on the resulting return value.
****************************************************************/
int& IntVector::at(unsigned index)
{
    if (index >= sz)
    {
        delete [] data; //free memory before exiting
        exit(1);
    }

    return data[index];
}
//EOF

/****************************************************************
 * 
 *  Method front: Class IntVector
 *  //PUBLIC
 * --------------------------------------------------------------
 *  Returns a const reference of the int value at the very front
 *  of the VectorInt object. Equivalent to obj.at(0).
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The object's capacity must be > 0! If not, you
 *      will access memory you are not supposed to. Size
 *      should also be greater than 0, and you will most
 *      likely get garbage values if size = 0, but it is 
 *      especially dangerous if capacity = 0.
 * 
 *  POST-CONDITIONS
 *      The state of the object will remain the same. No
 *      modification to any of the private attributes.
****************************************************************/
const int& IntVector::front(void) const
{
    return data[0];
}
//EOF

/****************************************************************
 * 
 *  Method front: Class IntVector
 *  //PUBLIC
 * --------------------------------------------------------------
 *  Returns a reference of the int value at the very front
 *  of the VectorInt object. Equivalent to obj.at(0).
 *  Since a reference is returned, you are also allowed to use
 *  the assignment operator to change the value of the of the
 *  front index in the object.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The object's capacity must be > 0! If not, you
 *      will access memory you are not supposed to. Size
 *      should also be greater than 0, and you will most
 *      likely get garbage values if size = 0, but it is 
 *      especially dangerous if capacity = 0.
 * 
 *  POST-CONDITIONS
 *      The object's state comming out of the method is not
 *      modified, yet, can be modified if afterwords the 
 *      assignment operator is used on the return of the method.
****************************************************************/
int& IntVector::front(void)
{
    return data[0];
}
//EOF

/****************************************************************
 * 
 *  Method back: Class IntVector
 *  //PUBLIC
 * --------------------------------------------------------------
 *  Returns a const reference of the int value at the very back
 *  of the VectorInt object. Equivalent to obj.at(obj.size()-1).
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The object's capacity must be > 0! If not, you
 *      will access memory you are not supposed to. Size
 *      should also be greater than 0, and you will most
 *      likely get garbage values if size = 0, but it is 
 *      especially dangerous if capacity = 0.
 * 
 *  POST-CONDITIONS
 *      The state of the object will remain the same. No
 *      modification to any of the private attributes.
****************************************************************/
const int& IntVector::back(void) const
{
    return data[sz-1];
}
//EOF

/****************************************************************
 * 
 *  Method back: Class IntVector
 *  //PUBLIC
 * --------------------------------------------------------------
 *  Returns a reference of the int value at the very back
 *  of the VectorInt object. Equivalent to obj.at(obj.size()-1).
 *  Since a reference is returned, you are also allowed to use
 *  the assignment operator to change the value of the of the
 *  back index in the object.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The object's capacity must be > 0! If not, you
 *      will access memory you are not supposed to. Size
 *      should also be greater than 0, and you will most
 *      likely get garbage values if size = 0, but it is 
 *      especially dangerous if capacity = 0.
 * 
 *  POST-CONDITIONS
 *      The object's state comming out of the method is not
 *      modified, yet, can be modified if afterwords the 
 *      assignment operator is used on the return of the method.
****************************************************************/
int& IntVector::back(void)
{
    return data[sz-1];
}
//EOF

/****************************************************************
 * 
 *  Method expand: Class IntVector
 *  //PRIVATE
 * --------------------------------------------------------------
 *  Double the capacity of the data array.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      There must be enough memory to hold both the new bigger
 *      array, and the smaller current array, while copying is
 *      being done.
 * 
 *  POST-CONDITIONS
 *      Assuming there was enough memory, the size of the object
 *      will stay the same but the value of capacity will be
 *      doubled, and the private data array can now hold twice
 *      as many elements (and all the previous elements are also
 *      kept).
 *      Note: if cap = 0, then the new capacity will be set to 1.
****************************************************************/
void IntVector::expand(void)
{
    if (cap == 0)   //ensure a new object also gets memory!
        expand(1);
    else
        expand(cap);    //double capacity
}
//EOF

/****************************************************************
 * 
 *  Method expand: Class IntVector
 *  //PRIVATE
 * --------------------------------------------------------------
 *  Increase the size of the data array by the passed in arg
 *  unsigned amount.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      There must be enough memory to hold both the new bigger
 *      array, and the smaller current array, while copying is
 *      being done.
 * 
 *  POST-CONDITIONS
 *      Assuming there was enough memory, the size of the object
 *      will stay the same but the value of capacity will grow to
 *      capacity + amount, and the private data array can now "amount"
 *      more elements (and all the previous elements are also
 *      kept).
****************************************************************/
void IntVector::expand(unsigned amount)
{
    int* temp;  //PROC - store the address of the new array

    cap += amount;  //change size of capacity
    temp = new int[cap];
    //copy all of contents of data to temp
    for (long i = 0; i < sz; i++)
        temp[i] = data[i];

    delete [] data; //free the previous memory
    data = temp;    //set new address for data
}
//EOF

/****************************************************************
 * 
 *  Method insert: Class IntVector
 *  //PUBLIC
 * --------------------------------------------------------------
 *  Inserts int value into the passed index (if index is less
 *  than the size of the IntVector object).
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The IntVector object's size should be greater than 0.
 * 
 *  POST-CONDITIONS
 *      The size of the object increases by one. If the new
 *      size is larger than the capacity, will automatically
 *      set double the capacity. The closer to the front
 *      of the vector the index is, the longer the method
 *      will take, since private data structure is just an array,
 *      have to a lot of shifiting of elements.
 * 
 *      Note: if the index is invalid, clean up of the calling
 *      object is done, and the complete program ends (exit(1))
****************************************************************/
void IntVector::insert(unsigned index, int value)
{
    if (index >= sz) //ensure index is valid
    {
        delete [] data;
        exit(1);
    }
    
    if (sz + 1 > cap)
        expand(); //double capacity if new size is bigger
    
    for (long i = sz - 1; i >= index; i--)
        data[i+1] = data[i];
    data[index] = value;    //insert value here
    sz += 1; //increase size
}
//EOF

/****************************************************************
 * 
 *  Method erase: Class IntVector
 *  //PUBLIC
 * --------------------------------------------------------------
 *  If the index is less than the object's size, then the value
 *  at said index is erased, and all the elements to the right
 *  of it are shifted one index down (to the left).
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The IntVector object's size should be greater than 0.
 * 
 *  POST-CONDITIONS
 *      The size of the object is decrease by 1. The capacity 
 *      of the object does not change what's so ever.
 *      The closer the index is to the front of the IntVector, 
 *      the longer the method will take as more elements need
 *      to be shifted left.
 *      Note: if the index is invalid, clean up of the calling
 *      object is done, and the complete program ends (exit(1))
****************************************************************/
void IntVector::erase(unsigned index)
{
    if (index >= sz)
    {
        delete [] data;
        exit(1);
    }

    //sz - 1 to not access memory were are not supposed to (data[i+1])
    for (long i = index; i < (sz - 1); i++)
        data[i] = data[i+1];

    sz -= 1;    //since we removed an index
}
//EOF

/****************************************************************
 * 
 *  Method push_back: Class IntVector
 *  //PUBLIC
 * --------------------------------------------------------------
 *  The size of the object is increase by one, and the int value
 *  is set to the new back of the IntVector object.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The IntVector object can be of any size and capcity,
 *      including 0.
 * 
 *  POST-CONDITIONS
 *      If the new size is greater than capacity, capacity is
 *      doubled.
****************************************************************/
void IntVector::push_back(int value)
{
    if (sz + 1 > cap)
        expand();

    sz += 1;
    data[sz - 1] = value;
}
//EOF

/****************************************************************
 * 
 *  Method pop_back: Class IntVector
 *  //PUBLIC
 * --------------------------------------------------------------
 *  The size of the object is decreased by one. Previous back
 *  index is no longer accessible. New back index.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The object's size must be a minimum 1.
 * 
 *  POST-CONDITIONS
 *      If object's size is 0, the object's heap allocated
 *      memory is cleaned up and the whole program exists.
****************************************************************/
void IntVector::pop_back(void)
{
    //nothing to pop!
    if (sz == 0)
    {
        delete [] data;
        exit(1);
    }
    sz -= 1;
}
//EOF

/****************************************************************
 * 
 *  Method clear: Class IntVector
 *  //PUBLIC
 * --------------------------------------------------------------
 *  The size of the object is set to 0.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The object can be of any size or capacity.
 * 
 *  POST-CONDITIONS
 *      The size will be set to 0, but the capacity is left
 *      untouched.
****************************************************************/
void IntVector::clear(void)
{
    //makes it so user can no longer access the values through
    //the public interface! capacity is untouched.
    sz = 0;
}
//EOF

/****************************************************************
 * 
 *  Method resize: Class IntVector
 *  //PUBLIC
 * --------------------------------------------------------------
 *  If the passed in size is larger than the current object's
 *  size, then more memory is accommodated if needed, and all
 *  the new unfilled indicies are filled with zeros. If passed
 *  in size is smaller than current size, then the object's
 *  size variable will simply be set to the passed in size.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The object can be of any size or capacity.
 * 
 *  POST-CONDITIONS
 *      The capacity of the IntVector is not assured to change.
 *      The only times it will change is if the passed in size
 *      is greater than capacity (note, capacity does not 
 *      necessarily need to equal to size, it's usually bigger!)
 *      If the passed in size is smaller, none of the data values
 *      are changed, but the user looses access to them through
 *      the public interface.
****************************************************************/
void IntVector::resize(unsigned size)
{
    resize(size, 0);
}
//EOF

/****************************************************************
 * 
 *  Method resize: Class IntVector
 *  //PUBLIC
 * --------------------------------------------------------------
 *  If the passed in size is larger than the current object's
 *  size, then more memory is accommodated if needed, and all
 *  the new unfilled indicies are filled with "value" arg. If passed
 *  in size is smaller than current size, then the object's
 *  size variable will simply be set to the passed in size.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The object can be of any size or capacity.
 * 
 *  POST-CONDITIONS
 *      The capacity of the IntVector is not assured to change.
 *      The only times it will change is if the passed in size
 *      is greater than capacity (note, capacity does not 
 *      necessarily need to equal to size, it's usually bigger!)
 *      If the passed in size is smaller, none of the data values
 *      are changed, but the user looses access to them through
 *      the public interface.
****************************************************************/
void IntVector::resize(unsigned size, int value)
{
    if (size <= sz)
    {
        sz = size; //either stays the same, or it reduces in value
        return;
    }

    //then size must be greater than sz
    if (size > cap) //expanding capacity to meet size demands
        (cap*2 >= size) ? expand() : expand(size - cap);
    
    for (long i = sz; i < size; i++) //set rest of data array to 0
        data[i] = value;
    
    sz = size;  //update finnally the size
}
//EOF

/****************************************************************
 * 
 *  Method reserve: Class IntVector
 *  //PUBLIC
 * --------------------------------------------------------------
 *  The capacity of the IntVector is changed based on the passed in
 *  unsigned "n" argument. All the previous elements held in the
 *  vector are left intact.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The object can be of any size or capacity.
 * 
 *  POST-CONDITIONS
 *      The IntVector object will never decrease in capacity.
 *      If the passed in "n" is smaller than capacity, nothing
 *      is done. The capacity is always assured to be at least
 *      the passed in "n", but may be bigger.
****************************************************************/
void IntVector::reserve(unsigned n)
{
    if (cap >= n)
        return; //don't do anything, capacity is all good
    
    //assured that n > cap
    (cap*2 >= n) ? expand() : expand(n - cap);
}
//EOF

/****************************************************************
 * 
 *  Method reserve: Class IntVector
 *  //PUBLIC
 * --------------------------------------------------------------
 *  It assigns a new size to the IntVector object, and fills
 *  up that new size with the new passed in "value". The final
 *  size is set to "n".
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The passed in IntVector object can be of any size.
 *  POST-CONDITIONS
 *      If the new size is greater than the capacity, capacity
 *      is automatically resized to meet the needs of the new
 *      size. The values of size is always changed (unless the
 *      passed in size "n" is the same).
****************************************************************/
void IntVector::assign(unsigned n, int value)
{
    if (n > sz)
    {
        for (long i = 0; i < sz; i++)
            data[i] = value;
        //this->resize() makes it so sz = n, data and capacity
        //are made bigger accordingly, and the new empty indicies
        //between sz and n (since n is larger) are filled with
        //"value"
        //NOTE: have to call after the above for loop to avoid
        //changing sz to n early, and risking a seg fault.
        this->resize(n, value);
    }
    else //n must be less than or equal to sz
    {   
        //this seperation of when n > sz and when n <= sz 
        //also allows for the possibility of reducing the 
        //number of value changes that need to be done on data
        //since n might be smaller than sz
        sz = n;
        for (long i = 0; i < sz; i++)
            data[i] = value;
    }

}
//EOF

//EXTRA to meet rules of 3


/****************************************************************
 * 
 *  Method Constructor: Class IntVector
 *  //COPY CONSTRUCTOR
 * --------------------------------------------------------------
 *  Used when the argument to the constructor is another
 *  IntVector object, in which case a deep copy is done.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Will only apply when making a new object.
 * 
 *  POST-CONDITIONS
 *      New memory will be allocated for the object, and all
 *      the values will perfectly resemble that of the passed
 *      in IntVector object.
****************************************************************/
IntVector::IntVector(const IntVector& obj)
{
    sz = obj.sz;
    cap = obj.cap;
    data = new int[cap];
    for (long i = 0; i < sz; i++)
        data[i] = obj.data[i];
}
//EOF

/****************************************************************
 * 
 *  Method operator=: Class IntVector
 *  //PUBLIC
 * --------------------------------------------------------------
 *  Used when reassigning the value of an already existing 
 *  IntVector object. Will do a deep copy of the passed in
 *  IntVector object.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Can apply to objects that either have an lvalue or
 *      rvalue, does not matter.
 * 
 *  POST-CONDITIONS
 *      If the capacity of the calling object is larger than
 *      or equal to the object being passed in, no new memory
 *      will be allocated. Otherwise, previous memory block
 *      will be freed, and new memory block the exact same capacity
 *      as the passed in object will be allocated.
 *      Private attribute "sz" is always changed to be equal to
 *      that of the passed in object.
****************************************************************/
IntVector& IntVector::operator=(const IntVector& obj)
{
    if (this != &obj) //avoid object assigning to itself
    {
        sz = obj.sz;
        if (cap >= obj.cap)
        {
            for (long i = 0; i < sz; i++)
                data[i] = obj.data[i];
        }
        else
        {
            cap = obj.cap;
            delete [] data;
            data = new int[cap];
            for (long i = 0; i < sz; i++)
                data[i] = obj.data[i];
        }
    }
    #if DEBUG //inform progammer of self assignent; DEBUG defined and set to 1
    else
    {
        std::cout << "Class: IntVector\n";
        std::cout << "Method: " << __func__ << "\n";
        std::cout << "Object is trying to assigning to itself!\n";
        std::cout << "Address of calling object: " << this << "\n";
        std::cout << "Address of passed object : " << &m << "\n";
    }
    #endif

    return *this;
}
//EOF