#ifndef CS003A_STUDENT_CLASS_H
#define CS003A_STUDENT_CLASS_H

#include "student.h"
#include "date.h"
class CS003AStudent : public Student
{
public:
    CS003AStudent(void);
    CS003AStudent(std::string name, uint64_t studentId,
        std::string phoneNumber, uint64_t age, std::string gender,
        ClassStanding standing, double gpa, double initAssignmentScore,
        bool knowsJava, int gradMonth, int gradDay);

    void print(std::ostream& out = std::cout) const override;

private:
    int gradMonth;            //PROC - grad month for current year
    int gradDay;              //PROC - grad day for current year
    double totalScoreAssignments;   //PROC - assignment scores, total
    bool javaKnowledge;             //PROC - yes or no question for constructor
    Date projectedGraduation;       //PROC - based on current class standing
};

#endif //CS003A_STUDENT_CLASS_H