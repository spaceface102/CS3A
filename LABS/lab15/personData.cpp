#include "personData.h"

void PersonData::setLastName(const std::string& _lastName)
{
    lastName = _lastName;
}
//EOF

void PersonData::setFirstName(const std::string& _firstName)
{
    firstName = _firstName;
}
//EOF

void PersonData::setAddress(const std::string& _address)
{
    address = _address;
}
//EOF

void PersonData::setCity(const std::string& _city)
{
    city = _city;
}
//EOF

void PersonData::setState(const std::string& _state)
{
    state = _state;
}
//EOF

void PersonData::setPhone(const std::string& _phone)
{
    phone = _phone;
}
//EOF

void PersonData::setZip(int _zip)
{
    zip = _zip;
}
//EOF

const std::string& PersonData::getLastName(void) const
{
    return lastName;
}
//EOF

const std::string& PersonData::getFirstName(void) const
{
    return firstName;
}
//EOF

const std::string& PersonData::getAddress(void) const
{
    return address;
}
//EOF

const std::string& PersonData::getCity(void) const
{
    return city;
}
//EOF

const std::string& PersonData::getState(void) const
{
    return state;
}
//EOF

const std::string& PersonData::getPhone(void) const
{
    return phone;
}
//EOF

int PersonData::getZip(void) const
{
    return zip;
}