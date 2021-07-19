#ifndef PERSON_DATA_CLASS_H
#define PERSON_DATA_CLASS_H

#include <string>
class PersonData
{
private:
    std::string lastName;   //PROC - last name of a person
    std::string firstName;  //PROC - first name of a person
    std::string address;    //PROC - house address of a person
    std::string city;       //PROC - city name of house of a person
    std::string state;      //PROC - state name of the city
    int zip;                //PROC - zip code of the city
    std::string phone;      //PROC - phone number of a person

public:
    /*************
    ** MUTATORS **
    *************/
    void setLastName(const std::string& _lastName);
    void setFirstName(const std::string& _lastName);
    void setAddress(const std::string& _address);
    void setCity(const std::string& _address);
    void setState(const std::string& _address);
    void setPhone(const std::string& _address);
    void setZip(int _zip);

    /**************
    ** ACCESSORS **
    **************/
    const std::string& getLastName(void) const;
    const std::string& getFirstName(void) const;
    const std::string& getAddress(void) const;
    const std::string& getCity(void) const;
    const std::string& getState(void) const;
    const std::string& getPhone(void) const;
    int getZip(void) const;
};
//I think for this example it might be better to just
//use a struct; its all just data fields that need to
//be modifed are accessed. Following instructions...

#endif //PERSON_DATA_CLASS_H 