#ifndef MATRIX_CLASS_TEMPLATE_H
#define MATRIX_CLASS_TEMPLATE_H

#include <cstdint>
#include <iostream>

//Declare std::ostream function as a template
//function before, in order to add template parameter
//in Matrix class definition. Defined later.
template<typename T, uint64_t Trows, uint64_t Tcols>
class Matrix;
template<typename T, uint64_t Trows, uint64_t Tcols>
std::ostream& operator<<(std::ostream& out, const Matrix<T, Trows, Tcols>& m);

//Class Matrix definiton
template<typename T, uint64_t Trows, uint64_t Tcols>
class Matrix
{
private:
    T array[Trows][Tcols];

public:
    Matrix(void);
    void printMatrix(void) const;
    friend std::ostream& operator<<
         <T>(std::ostream& out, const Matrix<T, Trows, Tcols>& m);
    void setElement(uint64_t row, uint64_t col, T value);
    void setMatrix(const T (&array1D)[Trows*Tcols]);
    void setMatrix(const T (&array2D)[Trows][Tcols]);
    const Matrix operator+(const Matrix<T, Trows, Tcols>& m) const;
};


//Method Defintions
/****************************************************************
 *  //TEMPLATE CLASS
 *  Method Constructor: Class Matrix
 *  //DEFAULT CONSTRUCTOR
 * --------------------------------------------------------------
 *  Set all the indicies of the 2D array representing a Matrix
 *  to 0.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The templated type T must be able to overload operator=
 *      and accept an integer as argument.
 * 
 *  POST-CONDITIONS
 *      The array is ready for the use of any other method
 *      associated with the class
****************************************************************/
template<typename T, uint64_t Trows, uint64_t Tcols>
Matrix<T, Trows, Tcols>::Matrix(void)
{
    for (uint64_t i = 0; i < Trows; i++)
        for (uint64_t k = 0; k < Tcols; k++)
            array[i][k] = 0;
}
//EOF

/****************************************************************
 *  //TEMPLATE CLASS
 *  Method printMatrix: Class Matrix
 *  //PUBLIC
 * --------------------------------------------------------------
 *  Displays the contents of a Matrix object row by row.
 *  No paramters for this method.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The templated type T must be able to overload 
 *      the operator<< with a std::ostream. Else, not able
 *      to use this method.
 *
 *  POST-CONDITIONS
 *      The calling object will not be modified. Each row
 *      is printed on one line, with no tailing extra space.
****************************************************************/
template<typename T, uint64_t Trows, uint64_t Tcols>
void Matrix<T, Trows, Tcols>::printMatrix(void) const
{
    for (uint64_t i = 0; i < Trows; i++)
    {
        for (uint64_t k = 0; k < Tcols - 1; k++)
            std::cout << array[i][k] << " ";
        std::cout << array[i][Tcols - 1] << "\n";
    }
}
//EOF

/****************************************************************
 *  //TEMPLATE
 *  //FRIEND of Matrix class
 *  FUNCTION operator<<
 * --------------------------------------------------------------
 *  Defines an overload for operator<< with a calling
 *  std::ostream object, and a passed in Matrix.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The templated type T must be able to overload 
 *      the operator<< with a std::ostream. Else, not able
 *      to use this method.
 *
 *  POST-CONDITIONS
 *      The calling object will not be modified. Each row
 *      is printed on one line, with no tailing extra space.
****************************************************************/
template<typename T, uint64_t Trows, uint64_t Tcols>
std::ostream& operator<<(std::ostream& out, const Matrix<T, Trows, Tcols>& m)
{
    for (uint64_t i = 0; i < Trows; i++)
    {
        for (uint64_t k = 0; k < Tcols - 1; k++)
            out << m.array[i][k] << " ";
        out << m.array[i][Tcols - 1] << "\n";
    }
    return out;
}
//EOF

template<typename T, uint64_t Trows, uint64_t Tcols>
void Matrix<T, Trows, Tcols>::setElement(uint64_t row, uint64_t col, T value)
{
    array[row][col] = value;
}
//EOF

/****************************************************************
 *  //TEMPLATE CLASS
 *  Method setMatrix: Class Matrix
 *  //PUBLIC
 * --------------------------------------------------------------
 *  Fills in the calling matrix object with the values at each
 *  index by the passed in array
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      The passed in array must be of the same templated type T,
 *      as that of the object.
 * 
 *      The passed in array must be declared in the calling
 *      function as a static array; size of the array must be
 *      known at compile time. (Method is passing in the array
 *      by reference to allow compiler to check array size, if
 *      they match with the expected size, compiles fine, else
 *      compilation error).
 * 
 *      Can't use dynamically allocated arrays.
 * 
 *      
 * 
 *      The templated type T, must define an operator= overload
 *      that passes in another object of the same type.
 * 
 *  POST-CONDITIONS
 *      The calling object will now be filled with the passed 
****************************************************************/
template<typename T, uint64_t Trows, uint64_t Tcols>
void Matrix<T, Trows, Tcols>::setMatrix(const T (&array1D)[Trows*Tcols])
{
    uint64_t r; //PROC - 1D array index

    r = 0;
    for (uint64_t i = 0; i < Trows; i++)
        for (uint64_t k = 0; k < Tcols; k++)
            array[i][k] = array1D[r++];
}
//EOF

template<typename T, uint64_t Trows, uint64_t Tcols>
void Matrix<T, Trows, Tcols>::setMatrix(const T (&array2D)[Trows][Tcols])
{
    for (uint64_t i = 0; i < Trows; i++)
        for (uint64_t k = 0; k < Tcols; k++)
            array[i][k] = array2D[i][k];
}
//EOF

template<typename T, uint64_t Trows, uint64_t Tcols>
const Matrix<T, Trows, Tcols> Matrix<T, Trows, Tcols>::
operator+(const Matrix<T, Trows, Tcols>& m) const
{
    Matrix<T, Trows, Tcols> returning_object; //PROC - create object to return
    for (uint64_t i = 0; i < Trows; i++)
        for (uint64_t k = 0; k < Tcols; k++)
            returning_object.array[i][k] = array[i][k] + m.array[i][k];
    return returning_object;
}
#endif //MATRIX_CLASS_TEMPLATE_H