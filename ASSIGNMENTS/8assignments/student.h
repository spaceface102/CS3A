#ifndef STUDENT_CLASS_H
#define STUDENT_CLASS_H

#include <string>
#include <cstdint>

class Student
{
public:
    enum class ClassStanding {FRESHMAN = 0, SOPHMORE, JUNIOR, SENIOR};

    Student(void);
    Student(std::string name, uint64_t studentId, std::string phoneNumber,
    uint64_t age, std::string gender, ClassStanding standing, double GPA);

    const std::string& getName(void) const;
    uint64_t getStudentID(void) const;
    const std::string& getPhoneNumber(void) const;
    uint64_t getAge(void) const;
    const std::string& getGender(void) const;
    const std::string& getClassStanding(void) const;
    double getGPA(void) const;

    void setName(const std::string& Aname);
    void setStudentID(uint64_t Aid);
    void setPhoneNumber(const std::string& Aphone);
    void setAge(uint64_t Anage);
    void setGender(const std::string& Agender);
    void setClassStanding(ClassStanding Astanding);
    void setGPA(double AGPA);

private:
    std::string name;
    uint64_t studentId;
    std::string phoneNumber;
    uint64_t age;
    std::string gender;
    ClassStanding standing;
    double GPA;

};

#endif //STUDENT_CLASS_H