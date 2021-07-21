/****************************************************************
 * AUTHOR           : Osbaldo Gonzalez Jr.
 * ASSIGNMENT 08    : Inheritance
 * CLASS            : CS 3A
 * SECTION          : 71206
 * DUE DATE         : 7/19/2021
****************************************************************/

#include "student.h"
/****************************************************************
 * 
 *  Method Constructor: Class Student
 *  //DEFAULT CONSTRUCTOR
 * --------------------------------------------------------------
 *  Set all student private fields to default values
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must make an object, or call the constructor with no
 *      arguments.
 * 
 *  POST-CONDITIONS
 *      The option is OK to use any of the other accesors
 *      or mutators.
****************************************************************/
Student::Student(void)
:
name("No Name"), studentId(0), phoneNumber("No Phone"), age(0),
gender("No gender"), standing(Student::ClassStanding::FRESHMAN),
GPA(0.0) 
{}
//EOF


/****************************************************************
 * 
 *  Method Constructor: Class Student
 *  //CONSTRUCTOR
 * --------------------------------------------------------------
 *  Set the values of all the private fields of an object of
 *  type Student
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must make an object, or call the constructor with no
 *      arguments.
 * 
 *      standing paramater must be of type ClassStanding, an enum
 *      class defined in the Student class. To access use scope
 *      resolution operator. Ex. Student::ClassStanding::JUNIOR
 * 
 *  POST-CONDITIONS
 *      The option is OK to use any of the other accesors
 *      or mutators.
****************************************************************/
Student::Student(std::string name, uint64_t studentId, std::string phoneNumber,
uint64_t age, std::string gender, ClassStanding standing, double GPA)
:
name(name), studentId(studentId), phoneNumber(phoneNumber), age(age),
gender(gender), standing(standing), GPA(GPA)
{}
//EOF

/****************************************************************
 * 
 *  Method getName: Class Student
 *  //PUBLIC ACCESSOR
 * --------------------------------------------------------------
 *  Get the name of the Student object.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must call method on an object.
 * 
 *  POST-CONDITIONS
 *      Will return a const std::string&. Can NOT modify
 *      the object's name using this method.
****************************************************************/
const std::string& Student::getName(void) const
    {return name;}
//EOF

/****************************************************************
 * 
 *  Method getStudentID: Class Student
 *  //PUBLIC ACCESSOR
 * --------------------------------------------------------------
 *  Get the studentID of the Student object.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must call method on an object.
 * 
 *  POST-CONDITIONS
 *      Will return a const uint64_t. Can NOT modify
 *      the object's name using this method.
****************************************************************/
uint64_t Student::getStudentID(void) const
    {return studentId;}
//EOF

/****************************************************************
 * 
 *  Method getPhoneNumber: Class Student
 *  //PUBLIC ACCESSOR
 * --------------------------------------------------------------
 *  Get the phoneNumber of the Student object.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must call method on an object.
 * 
 *  POST-CONDITIONS
 *      Will return a const std::string&. Can NOT modify
 *      the object's phone number using this method.
****************************************************************/
const std::string& Student::getPhoneNumber(void) const
    {return phoneNumber;}
//EOF

/****************************************************************
 * 
 *  Method getAge: Class Student
 *  //PUBLIC ACCESSOR
 * --------------------------------------------------------------
 *  Get the age of the Student object.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must call method on an object.
 * 
 *  POST-CONDITIONS
 *      Will return a const uint64_t. Can NOT modify
 *      the object's name using this method.
****************************************************************/
uint64_t Student::getAge(void) const
    {return age;}
//EOF

/****************************************************************
 * 
 *  Method getGender: Class Student
 *  //PUBLIC ACCESSOR
 * --------------------------------------------------------------
 *  Get the gender of the Student object.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must call method on an object.
 * 
 *  POST-CONDITIONS
 *      Will return a const std::string&. Can NOT modify
 *      the object's gender using this method.
****************************************************************/
const std::string& Student::getGender(void) const
    {return gender;}

/****************************************************************
 * 
 *  Method getClassStanding: Class Student
 *  //PUBLIC ACCESSOR
 * --------------------------------------------------------------
 *  Get the class standing of the Student object as a string.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must call method on an object.
 * 
 *  POST-CONDITIONS
 *      Will return a const std::string&. Can NOT modify
 *      the object's standing using this method.
****************************************************************/
const std::string& Student::getClassStanding(void) const
{
    static const std::string CLASS_STANDING_TABLE[4] = 
    {"Freshman", "Sophmore", "Junior", "Senior"};

    return CLASS_STANDING_TABLE[static_cast<int>(standing)];
}

/****************************************************************
 * 
 *  Method getGPA: Class Student
 *  //PUBLIC ACCESSOR
 * --------------------------------------------------------------
 *  Get the GPA of a student
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must call method on an object.
 * 
 *  POST-CONDITIONS
 *      Will return a double. Can NOT modify
 *      the object's GPA using this method.
****************************************************************/
double Student::getGPA(void) const
    {return GPA;}