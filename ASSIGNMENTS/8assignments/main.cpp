#include "cs003AStudent.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

void PrintAll(const Student& stu);

int main(void)
{
    Student test;                       //PROC && TEST -use default constructor
    Student studentarray[2];            //PROC && OUTPUT -track student objects
    CS003AStudent csStudentarray[2];    //PROC && OUTPUT - track CS objects


    studentarray[0] = test;
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
    std::cout << "Using constructor with parameters!\n";
    studentarray[1] = Student("Jimbo", 1234, "999-323-4453", 222, "Swag",
    Student::ClassStanding::JUNIOR, 4.0);
    studentarray[1].print();

    //using CS class
    csStudentarray[0] = CS003AStudent();
    std::cout << "Default constructor CS\n";
    csStudentarray[0].print();
    csStudentarray[1] =
    CS003AStudent("Someone's name", 9876, "444-444-444", 90,
    "M", Student::ClassStanding::SOPHMORE, 3.9999, 1000, true,
    9, 10);
    std::cout << "Testing using non default constructor CS\n";
    csStudentarray[1].print(); std::cout << "\n";

    std::cout << "\n\nTesting polymorphism PrintAll\n";
PrintAll(studentarray[0]);
PrintAll(studentarray[1]);
PrintAll(csStudentarray[0]);
PrintAll(csStudentarray[1]);

    //Testing input fr]om a file
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