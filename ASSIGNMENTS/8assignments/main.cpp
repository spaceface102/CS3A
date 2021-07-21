#include "cs003AStudent.h"
#include <iostream>
#include <string>
#include <fstream>

int main(void)
{
    Student test[2];
    std::ifstream fileStudentRecords;
    fileStudentRecords.open("students.txt");

    test[0].setStudentFromFile(fileStudentRecords);
    test[1].setStudentFromFile(fileStudentRecords);

    test[0].print();
    test[1].print();
}