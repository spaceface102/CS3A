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
gpa(0.0) 
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
uint64_t age, std::string gender, ClassStanding standing, double gpa)
:
name(name), studentId(studentId), phoneNumber(phoneNumber), age(age),
gender(gender), standing(standing), gpa(gpa)
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
 *  Method setName: Class Student
 *  //PUBLIC MUTATOR
 * --------------------------------------------------------------
 *  Set a new name for the calling Student object
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must call method on an object.
 *      Passed in arg of type std::string
 * 
 *  POST-CONDITIONS
 *      No return type, we are just changing the private
 *      name field for the Student object.
****************************************************************/
void Student::setName(const std::string& Aname)
    {name = Aname;}
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
 *  Method setStudentID: Class Student
 *  //PUBLIC MUTATOR
 * --------------------------------------------------------------
 *  Set a new ID for the calling Student object
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must call method on an object.
 *      Passed in arg of type uint64_t
 * 
 *  POST-CONDITIONS
 *      No return type, we are just changing the private
 *      ID field for the Student object.
****************************************************************/
void Student::setStudentID(uint64_t An_id)
    {studentId = An_id;}
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
 *  Method setPhoneNumber: Class Student
 *  //PUBLIC MUTATOR
 * --------------------------------------------------------------
 *  Set a new phone number for the calling Student object
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must call method on an object.
 *      Passed in arg of type std::string
 * 
 *  POST-CONDITIONS
 *      No return type, we are just changing the private
 *      phoneNumber field for the Student object.
****************************************************************/
void Student::setPhoneNumber(const std::string& Aphone)
    {phoneNumber = Aphone;}
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
 *  Method setAge: Class Student
 *  //PUBLIC MUTATOR
 * --------------------------------------------------------------
 *  Set a new age for the calling Student object
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must call method on an object.
 *      Passed in arg of type uint64_t
 * 
 *  POST-CONDITIONS
 *      No return type, we are just changing the private
 *      age field for the Student object.
****************************************************************/
void Student::setAge(uint64_t An_age)
    {age = An_age;}
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
//EOF

/****************************************************************
 * 
 *  Method setGender: Class Student
 *  //PUBLIC MUTATOR
 * --------------------------------------------------------------
 *  Set a new gender for the calling Student object
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must call method on an object.
 *      Passed in arg of type std::string
 * 
 *  POST-CONDITIONS
 *      No return type, we are just changing the private
 *      gender field for the Student object.
****************************************************************/
void Student::setGender(const std::string& Agender)
    {gender = Agender;}
//EOF

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
 *  Method setClassStanding: Class Student
 *  //PUBLIC MUTATOR
 * --------------------------------------------------------------
 *  Set a new class standing for the calling Student object
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must call method on an object.
 *      Passed in arg of type Student::ClassStanding
 * 
 *  POST-CONDITIONS
 *      No return type, we are just changing the private
 *      standing (class standing) field for the Student object.
****************************************************************/
void Student::setClassStanding(ClassStanding Astanding)
    {standing = Astanding;}
//EOF

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
    {return gpa;}
//EOF

/****************************************************************
 * 
 *  Method setGPA: Class Student
 *  //PUBLIC MUTATOR
 * --------------------------------------------------------------
 *  Set a new gpa for the calling Student object
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must call method on an object.
 *      Passed in arg of type double
 * 
 *  POST-CONDITIONS
 *      No return type, we are just changing the private
 *      gpa field for the Student object.
****************************************************************/
void Student::setGPA(double AGPA)
    {gpa = AGPA;}
//EOF