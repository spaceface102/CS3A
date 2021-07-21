#include "cs003AStudent.h"
#include <ctime>

CS003AStudent::CS003AStudent(void)
:
Student(), totalScoreAssignments(0), javaKnowledge(false),
gradMonth(5), gradDay(11)
{
    time_t t;   //PROC - time in seconds, UNIX time

    t = time(NULL);
    projectedGraduation = 
    Date(gradMonth, gradDay, (localtime(&t)->tm_year)+1900);
    //+1900 is just an offset for the localtime return value
}
//EOF

CS003AStudent::CS003AStudent(std::string name, uint64_t studentId,
        std::string phoneNumber, uint64_t age, std::string gender,
        ClassStanding standing, double gpa, double initAssignmentScore,
        bool knowsJava, int gradMonth, int gradDay)
:
Student(name, studentId, phoneNumber, age, gender, standing, gpa),
totalScoreAssignments(initAssignmentScore), javaKnowledge(knowsJava),
gradMonth(gradMonth), gradDay(gradDay)
{
    time_t t;   //PROC - time in seconds, UNIX time

    t = time(NULL);
    //set data to current year
    projectedGraduation = 
    Date(gradMonth, gradDay, (localtime(&t)->tm_year)+1900);
    //+1900 is just an offset for the localtime return value

    projectedGraduation = 
    projectedGraduation.addDays(
        (static_cast<int>(Student::ClassStanding::SENIOR)
         - static_cast<int>(standing))*365
    ); //adding a year for every class standing away from senior
    //ex, senior - senior = 0, senior - sophmore = 2,
    //senior - freshman = 3, senior - junior = 1
}
//EOF

void CS003AStudent::print(std::ostream& out) const
{
    //use base class Student's print
    this->Student::print(out);
    
    //add more to the output of Student's print
    out
    << "Assignment Score: " << totalScoreAssignments << "\n"
    << "Java Knowledge:   " << ((javaKnowledge) ? "yes" : "no") << "\n"
    << "Graduation Date:  " << projectedGraduation << "\n";
}