#include "matrix.h"
#include <iostream>
#include <string>
#include <fstream>

/****************************************************************
 * AUTHOR           : Osbaldo Gonzalez Jr.
 * LAB 16           : Template Matrix
 * CLASS            : CS 3A
 * SECTION          : 71206
 * DUE DATE         : 7/19/2021
****************************************************************/

/*****************************************************************************
 * 
 *   Matrix Template
 *______________________________________________________________________________
 *   Test my own template class making a matrix.
 *______________________________________________________________________________
 *  INPUT:
 *      none
 *  OUTPUT:
 *      outputFile  : where most of the output is going
*****************************************************************************/

int main(void)
{
    std::ofstream outputFile;    //OUTPUT - output.txt, store output

    outputFile.open("output.txt");

    outputFile << "Demonstrating with string matrix:\n\n";
    Matrix<std::string, 3, 3> strMtrx;
    std::string str2Darray[3][3] = {
        "Matrix set", "to", "first array",
        "Congra ", "y", " ar",
        "alm ", "don", " La"
    };
    strMtrx.setMatrix(str2Darray);
    outputFile << strMtrx << "\n\n";

    outputFile
    << "Matrix incremented by second array\n"
    << "You're almost done\n"
    << "with the Lab!\n\n";

    outputFile << "Demonstrating with int matrix:\n";
    Matrix<int, 2, 3> firstMatrix;
    int array1D_0[6] = {1, 2, 3, 4, 5, 6};
    firstMatrix.setMatrix(array1D_0);
    outputFile << firstMatrix << "\n\n";

    outputFile << "Matrix incremented by second array\n";
    Matrix<int, 2, 3> secondMatrix;
    int array2D_0[2][3] = {7, 7, 7, 7, 7, 7};
    secondMatrix.setMatrix(array2D_0);
    outputFile << secondMatrix << "\n\n";

    outputFile << "Demonstrating with float matrix:\n\n";
    outputFile << "Matrix set to first array\n"
    << "Made two, 2 by 3 matrices and added them together.\n"
    << "The first one is 1 through 6 and second is 0.6 to 0.1\n"
    << "Test operator+ and << and setMatrix with a 1D array\n";;
    double floatarray_0[6] = {1, 2, 3, 4, 5, 6};
    double floatarray_1[6] = {0.6, 0.5, 0.4, 0.3, 0.2, 0.1};
    Matrix<double, 2, 3> floatmatrix0;
    Matrix<double, 2, 3> floatmatrix1;
    floatmatrix0.setMatrix(floatarray_0);
    floatmatrix1.setMatrix(floatarray_1);
    outputFile << floatmatrix0 + floatmatrix1 << "\n\n";

    outputFile 
    << "Matrix incremented by second array\n"
    << "Made two, 2 by 3 matrices and added them together.\n"
    << "The first one is all sevens and the second one is all 0.7s\n"
    << "Test operator+ and << and setMatrix with a 1D array and 2D array\n";
    double floatarray_2[2][3] = {7, 7, 7, 7, 7, 7};
    double floatarray_3[6]    = {0.7, 0.7, 0.7, 0.7, 0.7, 0.7};
    Matrix<double, 2, 3> floatmatrix2;
    Matrix<double, 2, 3> floatmatrix3;
    floatmatrix2.setMatrix(floatarray_2);
    floatmatrix3.setMatrix(floatarray_3);
    outputFile << floatmatrix2 + floatmatrix3 << "\n\n";

    outputFile << "Final test, just .setElements and .printMatrix:\n";
    Matrix<int, 10, 10> upto100;
    for (int i = 0; i < 10; i++)
        for (int k = 0; k < 10; k++)
            upto100.setElement(i, k, (i*10) + 1 + k);
    outputFile << upto100 << "\n";
    outputFile << "Same output on console with the printMatrix method!\n";
    upto100.printMatrix();
    outputFile.close();
}