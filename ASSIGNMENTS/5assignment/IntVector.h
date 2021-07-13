#ifndef INTVECTOR_CLASS_H
#define INTVECTOR_CLASS_H

class IntVector
{
private:
    unsigned sz; //IN - size of vector (defines accessible elements)
    unsigned cap;//IN - capacity of vector (defines when need to expand data)
    int* data;   //IN - where all the data is stored.

public:
    /*****************************
    ** CONSTRUCTOR & DESTRUCTOR **
    *****************************/
    IntVector(void);
    IntVector(unsigned size);
    IntVector(unsigned size, int value);
    ~IntVector(void);

    /**************
    ** ACCESSORS **
    **************/
    unsigned size() const;
    unsigned capacity() const;
    bool empty() const;
    const int& at(unsigned index) const;
    const int& front() const;
    const int& back() const;

    /*************
    ** MUTATORS **
    *************/
    void insert(unsigned index, int value);
    void erase(unsigned index);
    void push_back(int value);
    void pop_back(void);
    void clear(void);
    void resize(unsigned size);
    void resize(unsigned size, int value);
    void reserve(unsigned n);
    void assign(unsigned n, int value);
    int& at(unsigned index);
    int& front();
    int& back();

    //EXTRA to meet rules of 3
    IntVector(const IntVector& obj);
    IntVector& operator=(const IntVector& obj);

private:
    void expand(void);
    void expand(unsigned amount);
};

#endif //INTVECTOR_CLASS_H

/********************************************************************
 * IntVector Class
 *  This class is a basic copy of the std::vector class without
 *  template args; can only store ints. It manages sz (size), 
 *  cap (capacity), and data (where all the information is held).
 *  "data" is resized as needed.
********************************************************************/

/*****************************
** CONSTRUCTOR & DESTRUCTOR **
*****************************/

/********************************************************************
 * IntVector(void);
 * 
 *      Constructor; Initialize all class attributes to 0. data
 *                   is initialized nullptr
 * ------------------------------------------------------------------
 *      Paramters: none
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/

/********************************************************************
 * IntVector(unsigned size);
 * 
 *      Constructor; Initialize sz and cap to passed in size arg.
 *                   Memory is allocated for data
 * ------------------------------------------------------------------
 *      Paramters: unsigned size //IN - set the private attribute sz
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/

/********************************************************************
 * IntVector(unsigned size, int value);
 * 
 *      Constructor; Initialize sz and cap to passed in size arg.
 *                   Memory is allocated for data. All the indicies
 *                   of the data array are set to passed in value arg
 * ------------------------------------------------------------------
 *      Paramters: unsigned size  //IN - set the private attribute sz
 *                 int      value //IN - value of every indicies in 
 *                                //data array
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/

/********************************************************************
 * ~IntVector(void);
 * 
 *      Destructor; Free all the heap allocated memory associated
 *                  with the object.
 * ------------------------------------------------------------------
 *      Paramters: none
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/

/********************************************************************
 * IntVector(const IntVector& obj);
 * 
 *      Copy Constructor; Does a deep copy of the passed in object.
 *                        All attributes of the passed in object,
 *                        are exactly copied into the new object.
 * ------------------------------------------------------------------
 *      Paramters: const IntVector& obj //IN - the object to be deep
 *                                      copied.
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/


/**************
** ACCESSORS **
**************/

/********************************************************************
 * unsigned size() const;
 * 
 *      Accessor; returns the size of the IntVector object.
 * ------------------------------------------------------------------
 *      Paramters: none
 * ------------------------------------------------------------------
 *      Return:    return a copy of the sz private attribute.
********************************************************************/

/********************************************************************
 * unsigned capacity() const;
 * 
 *      Accessor; returns the capacity of the IntVector object.
 * ------------------------------------------------------------------
 *      Paramters: none
 * ------------------------------------------------------------------
 *      Return:    return a copy of the cap private attribute.
********************************************************************/

/********************************************************************
 * bool empty() const;
 * 
 *      Accessor; returns a boolean associated with size == 0
 * ------------------------------------------------------------------
 *      Paramters: none
 * ------------------------------------------------------------------
 *      Return:    sz == 0 (a boolean value)
********************************************************************/

/********************************************************************
 * const int& at(unsigned index) const;
 * 
 *      Accessor; value at the passed in index
 * ------------------------------------------------------------------
 *      Paramters: unsigned index //IN - the index to return value
 *                                //from in the data array
 * ------------------------------------------------------------------
 *      Return:    a const reference to the value at the specified
 *                 index
********************************************************************/

/********************************************************************
 * const int& front(void) const;
 * 
 *      Accessor; value at the front of the index.
 * ------------------------------------------------------------------
 *      Paramters: none
 * ------------------------------------------------------------------
 *      Return:    a const reference to the value at the front
 *                 of the data array
********************************************************************/

/********************************************************************
 * const int& back(void) const;
 * 
 *      Accessor; value at the back of the index.
 * ------------------------------------------------------------------
 *      Paramters: none
 * ------------------------------------------------------------------
 *      Return:    a const reference to the value at the back
 *                 of the data array
********************************************************************/

/*************
** MUTATORS **
*************/

/********************************************************************
 *  void insert(unsigned index, int value);
 * 
 *      Mutator; inserts a passed in int value to the specified index
 * ------------------------------------------------------------------
 *      Paramters: unsigned index //IN - index to insert value in data
 *                 int      value //IN - value to insert.
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/

/********************************************************************
 *  void erase(unsigned index)
 * 
 *      Mutator; erases a value in the specified index, and shrinks
 *               size by one
 * ------------------------------------------------------------------
 *      Paramters: unsigned index //IN - index to erase value from
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/

/********************************************************************
 *  void push_back(int value);
 * 
 *      Mutator; makes spaces for a new value at the very end of the
 *               of data array. Increases sz by one
 * ------------------------------------------------------------------
 *      Paramters: unsigned value //IN - value to be set
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/

/********************************************************************
 *  void pop_back(void);
 * 
 *      Mutator; removes the last element from the data array. 
 *               Decreases sz by one.
 * ------------------------------------------------------------------
 *      Paramters: none
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/

/********************************************************************
 *  void clear(void);
 * 
 *      Mutator; size is set to 0.
 * ------------------------------------------------------------------
 *      Paramters: none
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/

/********************************************************************
 *  void resize(unsigned size);
 *  //OVERLOAD 1
 * 
 *      Mutator; Sets a new size for the calling object. If larger
 *               than current size, fills in new indicies with 0.
 * ------------------------------------------------------------------
 *      Paramters: unsigned size //IN - value to set private attribute
 *                               //sz to.
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/

/********************************************************************
 *  void resize(unsigned size, int value);
 *  //OVERLOAD 2
 *      Mutator; Sets a new size for the calling object. If larger
 *               than current size, fills in new indicies with 
 *               passed in int value.
 * ------------------------------------------------------------------
 *      Paramters: unsigned size //IN - value to set private attribute
 *                               //sz to.
 *                 int     value //IN - value to set the new empty 
 *                               //indices from the resize
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/

/********************************************************************
 *  void reserve(unsigned n)
 *      Mutator; Sets a new capacity "n" if "n" is greater than 
 *               the current capacity.
 * ------------------------------------------------------------------
 *      Paramters: unsigned n //IN - new capacity for calling object.
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/

/********************************************************************
 *  void assign(unsigned n, int value)
 *      Mutator; Changes the size of the object, and set all the
 *               the full data to passed in int value
 * ------------------------------------------------------------------
 *      Paramters: unsigned n //IN - new size for calling object.
 *                 int value  //IN - value for every index in data array
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/

/********************************************************************
 *  int& at(unsigned index);
 *      Mutator; returns a mutable reference to an index in data
 * ------------------------------------------------------------------
 *      Paramters: unsigned index //IN - the index reference to return
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/

/********************************************************************
 *  int& front();
 *      Mutator; returns a mutable reference to the front of data array
 * ------------------------------------------------------------------
 *      Paramters: none
 * ------------------------------------------------------------------
 *      Return:    reference to first (0th) index in data array
********************************************************************/

/********************************************************************
 *  int& back();
 *      Mutator; returns a mutable reference to the back of data array
 * ------------------------------------------------------------------
 *      Paramters: none
 * ------------------------------------------------------------------
 *      Return:    reference to last (size - 1) index in data array
********************************************************************/

/********************************************************************
 *  void expand(void);
 *      Mutator; double the capacity of the calling object.
 *               if the capacity is 0, sets capacity to 1.
 * ------------------------------------------------------------------
 *      Paramters: none
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/

/********************************************************************
 *  void expand(unsigned amount);
 *      Mutator; adds "amount" to capacity of the calling object.
 * ------------------------------------------------------------------
 *      Paramters: unsigned amount; //IN - value to add to private
 *                                  //attribute cap, and to realloc
 *                                  //memory for data
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/

/********************************************************************
 *  IntVector& operator=(const IntVector& obj)
 *      Mutator; does a deep copy of passed in obj to the calling
 *               IntVector object.
 * ------------------------------------------------------------------
 *      Paramters: const IntVector& obj //IN - object to make a deep
 *                                      //of to calling object.
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/