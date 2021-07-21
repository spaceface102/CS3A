/****************************************************************
 * AUTHOR           : Osbaldo Gonzalez Jr.
 * ASSIGNMENT 08    : Inheritance
 * CLASS            : CS 3A
 * SECTION          : 71206
 * DUE DATE         : 7/19/2021
****************************************************************/

#include "student.h"
#include <iostream>
#include <cctype>

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
standing_str("Freshman"), gpa(0.0)
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
{
    static const std::string CLASS_STANDING_TABLE[5] = 
    {"Freshman", "Sophmore", "Junior", "Senior", "Invalid"};

    standing_str = 
    CLASS_STANDING_TABLE[static_cast<int>(standing)];
}
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
    return standing_str;
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
 *      This also updates the standing_str.
****************************************************************/
void Student::setClassStanding(ClassStanding Astanding)
{
    static const std::string CLASS_STANDING_TABLE[5] = 
    {"Freshman", "Sophmore", "Junior", "Senior", "Invalid"};

    standing = Astanding;
    standing_str = 
    CLASS_STANDING_TABLE[static_cast<int>(standing)];
}
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

/****************************************************************
 * 
 *  Method print: Class Student
 *  //PUBLIC ACCESSOR
 *  //VIRTUAL
 * --------------------------------------------------------------
 *  Print all the attributes related to a Student object.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must call method on an object.
 * 
 *      Can optionally pass in any std::ostream, by default, 
 *      uses std::cout to display output.
 * 
 *  POST-CONDITIONS
 *      The object's state will remain constant. All private
 *      fields will have their own line for output.
****************************************************************/
void Student::print(std::ostream& out) const
{
    out
    << "Name:           " << name << "\n"
    << "Student ID:     " << studentId << "\n"
    << "Phone Number:   " << phoneNumber << "\n"
    << "Age:            " << age << "\n"
    << "Gender:         " << gender << "\n"
    << "Class Standing: " << getClassStanding() << "\n"
    << "GPA:            " << gpa << "\n";
}
//EOF

/****************************************************************
 * 
 *  Method setStudentFromFile: Class Student
 *  //PUBLIC MUTATOR
 *  //VIRTUAL
 * --------------------------------------------------------------
 *  Grabs all the records from a file. Useful if there is a
 *  large file with all sorts of records that need to be
 *  input quickly.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must call method on an object. The object can be a
 *      temp, r-value object, or an object with an l-value.
 * 
 *      Can optionally pass in any std::istream, by default, 
 *      uses std::cin to get input.
 * 
 *      If comming from file, must include all necessary
 *      data.
 * 
 *  POST-CONDITIONS
 *      The method will look for trailing new lines at the end
 *      of input. You don't need to worry about spaces between
 *      input, as long as there is an obvious seperating
 *      character between the data fields.
****************************************************************/
const Student& Student::setStudentFromFile(std::istream& in)
{
    std::string firstName;  //PROC - get first name from file
    std::string lastName;   //PROC - get last name from file
    int pushbackchar;       //PROC - just to push last character
    in 
    >> firstName >> lastName >> studentId >> phoneNumber
    >> age >> gender >> standing_str >> gpa;

    //set private field name
    name = firstName + " " + lastName;

    //set standing (enum class)
    switch (tolower(standing_str.at(0)))
    {
        case 'f':
            standing = ClassStanding::FRESHMAN;
            break;
        case 's':
            if (tolower(standing_str.at(1)) == 'o')
                standing = ClassStanding::SOPHMORE;
            else if (tolower(standing_str.at(1)) == 'e')
                standing = ClassStanding::SENIOR;
            else
                standing = ClassStanding::INVALID;
            break;
        case 'j':
            standing = ClassStanding::JUNIOR;
            break;
        default:
            standing = ClassStanding::INVALID;
    }

    //finish the line
    while (in && in.get() != '\n')
        ;
    while (in && (pushbackchar = in.get()) == '\n')
        ;
    in.putback(pushbackchar);
    return *this;
}
//EOF