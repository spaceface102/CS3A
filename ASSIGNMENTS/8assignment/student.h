#ifndef STUDENT_CLASS_H
#define STUDENT_CLASS_H

#include <string>
#include <cstdint>
#include <iostream>

class Student
{
public:
    enum class ClassStanding 
    {FRESHMAN = 0, SOPHMORE, JUNIOR, SENIOR, INVALID};

    Student(void);
    Student(std::string name, uint64_t studentId,
        std::string phoneNumber, uint64_t age, std::string gender,
        ClassStanding standing, double gpa);

    const std::string& getName(void) const;
    uint64_t getStudentID(void) const;
    const std::string& getPhoneNumber(void) const;
    uint64_t getAge(void) const;
    const std::string& getGender(void) const;
    const std::string& getClassStanding(void) const;
    double getGPA(void) const;
    virtual void print(std::ostream& out = std::cout) const;

    void setName(const std::string& Aname);
    void setStudentID(uint64_t An_id);
    void setPhoneNumber(const std::string& Aphone);
    void setAge(uint64_t An_age);
    void setGender(const std::string& Agender);
    void setClassStanding(ClassStanding Astanding);
    void setGPA(double Agpa);
    virtual const Student& setStudentFromFile(std::istream& in = std::cin);

private:
    std::string name;
    uint64_t studentId;
    std::string phoneNumber;
    uint64_t age;
    std::string gender;
    ClassStanding standing;
    std::string standing_str;
    double gpa;

};

#endif //STUDENT_CLASS_H