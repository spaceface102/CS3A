/*****************************************************************************
 * AUTHOR   : Osbaldo Gonzalez Jr. && Zimin Yang
 * LAB #6   : The Rule of 3
 * CLASS    : CS 3A
 * SECTION  : 71206
 * DUE DATE : 7/7/2021
*****************************************************************************/
#include "music_collection.h"

/****************************************************************
 * 
 *  Method Constructor: Class Music_collection 
 *  //DEFAULT CONSTRUCTOR
 * --------------------------------------------------------------
 *  Number of tunes is set to 0, the max number of tunes is set
 *  to 100 and memory is allocated for 100 tunes.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must make an object, or call the constructor with no
 *      arguments.
 * 
 *  POST-CONDITIONS
 *      The object does not have any tunes yet, use add_tune()
 *      class method to add a Tune object!
****************************************************************/
Music_collection::Music_collection(void)
{
    number = 0;
    max = 100;
    collection = new Tune[max];
}
//EOF

/****************************************************************
 * 
 *  Method Constructor: Class Music_collection 
 *  //CONSTRUCTOR
 * --------------------------------------------------------------
 *  Number of tunes is set to 0, the max number of tunes is set
 *  to "n" (passed in int arg) and memory is allocated for "n" tunes.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must make an object, or call the constructor with one 
 *      int argument
 * 
 *  POST-CONDITIONS
 *      The object does not have any tunes yet, use add_tune()
 *      class method to add a Tune object!
 *      If n is negative, no memory is allocated and max is
 *      set to 0.
****************************************************************/
Music_collection::Music_collection(int n)
{
    number = 0;
    max = (n < 0) ? 0 : n;  //ensure the value of n is positive
    collection = (max == 0) ? nullptr : new Tune[max];
}
//EOF

/****************************************************************
 * 
 *  Method Constructor: Class Music_collection 
 *  //COPY CONSTRUCTOR
 * --------------------------------------------------------------
 *  Private attribues number and max are set directly from the
 *  passed in object. New memory is allocated for the Tune*
 *  collection.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must make an object, or call the constructor with a 
 *      Music_collection object as the argument
 * 
 *  POST-CONDITIONS
 *      The new object will have all the tunes from the passed
 *      in object. The new object will be of the exact same 
 *      capacity (max attributes are equal and allocated memory
 *      size is also equal)
****************************************************************/
Music_collection::Music_collection(const Music_collection& m)
{
    number = m.number;
    max = m.max;
    collection = new Tune[max];
    for (int i = 0; i < number; i++)
        collection[i] = m.collection[i];
}
//EOF

/****************************************************************
 * 
 *  Method add_tune: Class Music_collection 
 *  //PUBLIC
 * --------------------------------------------------------------
 *  A tune object is added to the collection array if size
 *  permits. Returns true is successfully added, returns false
 *  if not able to add new Tune to the private collection array.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must call the method through an object; not a static
 *      method.
 * 
 *  POST-CONDITIONS
 *      The passed in tune is not modified (A copy of the tune
 *      is made). Private attribute number is incremented by
 *      one if the new Tune fits into the collection array.
****************************************************************/
bool Music_collection::add_tune(const Tune&t)
{
    if (number >= max)
        return false;   //Not enough space
    
    collection[number] = t;
    number += 1;        //account for the new tune
    return true;
}
//EOF

/****************************************************************
 * 
 *  Method set_tune: Class Music_collection 
 *  //PUBLIC
 * --------------------------------------------------------------
 *  Changes an already set Tune inside the collection to a new
 *  Tune. If tune has not yet been set, method will not add
 *  Tune. Start counting from 0 (like array); if you want to
 *  set a new Tune for the 42nd tune, passed in index should be 41.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must call the method through an object; not a static
 *      method.
 * 
 *  POST-CONDITIONS
 *      The collection array does not grow, and will continue 
 *      to stay the same size. The new set_tune is not 
 *      forced to set as the last tune (note the passed in
 *      index var!).
 *      The private attribute can be equal to max by the end
 *      of the method call, but never greater than!
****************************************************************/
bool Music_collection::set_tune(int index, const Tune& t)
{
    if (index >= number)
        return false;   //not a valid index
    
    collection[index] = t;
    return true;        //index was less than number
}
//EOF

/****************************************************************

 *  Method operator=: Class Music_collection 
 *  //PUBLIC
 * --------------------------------------------------------------
 *  Does a deep copy of the passed in Music_collection object, 
 *  where the number of tunes is changed, the max number of tunes
 *  is changed and if the "capacity" of the passed in object is 
 *  greater, the "capcity" of the calling object is also changed
 *  to match. All the tunes from the passed in object are 
 *  copied to the calling object.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The passed in object can be an temporay object (rvalue)
 *      as well as the calling object.
 * 
 *  POST-CONDITIONS
 *      The collection array may, or may not grow. It is
 *      assured to grow if the private attribute "max", is 
 *      larger than that of the calling object, but otherwise,
 *      the already existing memory is just written over.
 *      There might still be valid tunes in the overwritten 
 *      array associated with the calling object's Tune* collection,
 *      but it is not accessibly publicly through the interface as
 *      the private attribute number is assured to change.
****************************************************************/
Music_collection& Music_collection::operator=(const Music_collection &m)
{
    if (this != &m) //avoid object assigning to itself
    {
        number = m.number; //assured that m.number is <= m.max

        //check to see if max >= m.max instead of max >= m.number 
        //because I want the new object to at least have the exact
        //same max as the passed in object
        if (max >= m.max) //enough space avaliable to just copy m.collection
        {
            //number, to reduce the copies; only need to copy useful data!
            //max attribute stays the same, since no new memory was allocated
            for (int i = 0; i < number; i++)
                collection[i] = m.collection[i];
        }
        else //max is less than m.max, therefore have to allocate more memory!
        {
            max = m.max;
            delete [] collection; //free up the previous memory
            collection = new Tune[max]; //assing new memory to it
            for (int i = 0; i < number; i++)
                collection[i] = m.collection[i];
        }
    }
    #if DEBUG //inform progammer of self assignent; DEBUG defined and set to 1
    else
    {
        std::cout << "Class: Music_collection\n";
        std::cout << "Method: " << __func__ << "\n";
        std::cout << "Object is trying to assigning to itself!\n";
        std::cout << "Address of calling object: " << this << "\n";
        std::cout << "Address of passed object : " << &m << "\n";
    }
    #endif

    return *this;   //return the calling object
}
//EOF

/****************************************************************
 * 
 *  Method Destructor: Class Music_collection 
 *  //DESTRUCTOR
 * --------------------------------------------------------------
 *  All the heap allocated memory associated with the
 *  Music_collection object if freed.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Standard Destructor rules apply.
 * 
 *  POST-CONDITIONS
 *      The Tune* collection is set to nullptr.
****************************************************************/
Music_collection::~Music_collection(void)
{
    delete [] collection;
    collection = nullptr;   //ensure memory address is no longer accessible
}
//EOF

/****************************************************************
 * 
 *  FUNCTION: operator<<
 *  //FRIEND class Music_collection
 * --------------------------------------------------------------
 *  Displays all the tunes related with a Music_collection object
 *  in a single line.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Will only print the number of Tune objects present.
 * 
 *  POST-CONDITIONS
 *      The Music_collection object is not modified!
****************************************************************/
std::ostream& operator<<(std::ostream& out, const Music_collection& m)
{
    for (int i = 0; i < m.number; i++)
        out << m.collection[i].get_title() << "\n";
    return out;
}
//EOF

/****************************************************************
 * 
 *  Method Constructor: Class Tune
 *  //DEFAULT CONSTRUCTOR
 * --------------------------------------------------------------
 *  Set title to empty string.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Will only run when creating a new object.
 * 
 *  POST-CONDITIONS
 *      Private attribute title will be an empty string.
****************************************************************/
Tune::Tune(void)
{
    title = "";
}
//EOF

/****************************************************************
 * 
 *  Method Constructor: Class Tune
 *  //CONSTRUCTOR
 * --------------------------------------------------------------
 *  Set title to the passed in std::string "n".
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Will only run when creating a new object.
 * 
 *  POST-CONDITIONS
 *      Private attribute title will be a copy of the passed
 *      int std::string object.
****************************************************************/
Tune::Tune(const std::string& n)
{
    title = n;
}
//EOF

/****************************************************************
 * 
 *  Method get_title: Class Tune
 *  //PUBLIC
 * --------------------------------------------------------------
 *  Returns the title of the object.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must call method on an object. Not a static method.
 * 
 *  POST-CONDITIONS
 *      The return type is const std::string& to ensure 
 *      the object's private title is not modified.
****************************************************************/
const std::string& Tune::get_title() const
{
    return title;
}
//EOF