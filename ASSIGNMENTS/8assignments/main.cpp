#include "cs003AStudent.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

void PrintAll(const Student& stu);

int main(void)
{
    Student test;

    //Testing Student class
    std::cout << "Before, just declaring variable test of type Student:\n";
    test.print(); std::cout << "\n";
    std::cout << "Testing: setName()\n";
    test.setName("Not the original constructor name");
    test.print(); std::cout << "\n";
    std::cout << "Testing: setStudentID()\n";
    test.setStudentID(42);
    test.print(); std::cout << "\n";
    std::cout << "Testing: setPhoneNumber()\n";
    test.setPhoneNumber("A valid phone num 323 maybe, 949???");
    test.print(); std::cout << "\n";
    std::cout << "Testing: setAge()\n";
    test.setAge(400);
    test.print(); std::cout << "\n";
    std::cout << "Testing: setGender()\n";
    test.setGender("Whatever geneder I please!");
    test.print(); std::cout << "\n";
    std::cout << "Testing: setClassStanding()\n";
    test.setClassStanding(Student::ClassStanding::SENIOR);
    test.print(); std::cout << "\n";
    std::cout << "Testing: setGPA()\n";
    test.setGPA(4.44);
    test.print(); std::cout << "\n";

    //Testing input from a file
    std::cout << "\n\n\n"; //spacer
    std::ifstream fileStudentRecords;   //PROC - read from file student record
    std::vector<Student> studentVector; //PROC - store student record

    std::cout << "Testing with input file student record:\n";
    fileStudentRecords.open("students.txt");
    while (fileStudentRecords)
        studentVector.push_back(
            Student().setStudentFromFile(fileStudentRecords)
        );

    for (long i = 0; i < studentVector.size(); i++)
        PrintAll(studentVector[i]);
}

void PrintAll(const Student& stu)
{
    stu.print();
    std::cout << "\n";
}