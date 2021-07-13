#ifndef INTVECTOR_CLASS_H
#define INTVECTOR_CLASS_H

class IntVector
{
private:
  unsigned sz;  //IN - size aka number of elements
  unsigned cap; //IN - ammount of allocated memory
  int* data;    //IN - address to an array of data
public:
  /*****************************
  ** CONSTRUCTOR & DESTRUCTOR **
  *****************************/
  IntVector();
  IntVector(unsigned size);
  IntVector(unsigned size, int value);
  ~IntVector();
  
  /**************
  ** ACCESSORS **
  **************/
  unsigned size() const;
  unsigned capacity() const;
  bool empty() const;
  const int& at(unsigned index) const;
};
#endif //INTVECTOR_CLASS_H

/********************************************************************
 * IntVector
 * This class is the first step to emulating std::vector. Here we
 * are just dealing with integers.
********************************************************************/

/*****************************
** CONSTRUCTOR & DESTRUCTOR **
*****************************/

/********************************************************************
 * IntVector(void);
 * 
 *      Constructor; Initialize all class attributes
 * ------------------------------------------------------------------
 *      Paramters: none
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/

/********************************************************************
 * IntVector(unsigned size);
 * 
 *      Constructor; Initialize all class attributes. Set all the
        value of the private data attribute to 0.
 * ------------------------------------------------------------------
 *      Paramters: unsigend size //IN - allocated that much memory
                                  //for future storage
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/

/********************************************************************
 * IntVector(unsigned size, int value);
 * 
 *      Constructor; Initialize all class attributes. Set all the
        value of the private data attribute to passed int value.
 * ------------------------------------------------------------------
 *      Paramters: unsigend size //IN - allocated that much memory
                                  //for future storage
                   unsigend value //IN - what all the indicies are
                                  //set to in the data attribute
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/

/**************
** ACCESSORS **
**************/

/********************************************************************
 * unsigned size(void) const;
 * 
 *      Accessor; Return the value of the private attribute sz.
 * ------------------------------------------------------------------
 *      Paramters: none
 * ------------------------------------------------------------------
 *      Return:    unsigend value of private attribute sz.
********************************************************************/

/********************************************************************
 * unsigned capacity(void) const;
 * 
 *      Accessor; Return the value of the private attribute cap.
 * ------------------------------------------------------------------
 *      Paramters: none
 * ------------------------------------------------------------------
 *      Return:    unsigend value of private attribute cap.
********************************************************************/

/********************************************************************
 *  bool empty(void) const;
 * 
 *      Accessor; Returns boolean denoting if IntVector object's
                  private attribute sz is equal to 0.
 * ------------------------------------------------------------------
 *      Paramters: none
 * ------------------------------------------------------------------
 *      Return:    empty status boolean.
********************************************************************/

/********************************************************************
 *  const int& at(unsigned index) const;
 * 
 *      Accessor; Returns value inside data with index passed.
 * ------------------------------------------------------------------
 *      Paramters: none
 * ------------------------------------------------------------------
 *      Return:    int value of unsigned index in private attribute
                   data
********************************************************************/