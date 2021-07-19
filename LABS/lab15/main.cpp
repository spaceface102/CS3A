/****************************************************************
 * AUTHOR           : Osbaldo Gonzalez Jr.
 * LAB 16           : Inheritance Customer
 * CLASS            : CS 3A
 * SECTION          : 71206
 * DUE DATE         : 7/17/2021
****************************************************************/

#include "preferredCustomer.h"
#include <iostream>
#include <string>

//FUNCTION PROTOTYPES
void UseAll_PersonData_Specific_Accessors(const PersonData& obj);
void UseAll_CustomerData_Specific_Accessors(const CustomerData& obj);
void UseAll_PreferredCustomer_Specific_Accessors(const PreferredCustomer& obj);
void UseAll_Accesors(const PreferredCustomer& obj);
//END OF FUNCTION PROTOTYPES

int main(void)
{
    PreferredCustomer someone;
    double costPurchase;

    someone.setFirstName("John");
    someone.setLastName("Doe");
    someone.setAddress("Somewhere");
    someone.setCity("Pasadena");
    someone.setState("CA");
    someone.setPhone("333 333 3333");
    someone.setZip(231231);
    
    while (someone.getPurchasesAmount() <= 2500)
    {
        std::cout << "Price of purchase: ";
        std::cin >> costPurchase;
        someone.makePurchase(costPurchase);
        std::cout << "\n";
    }
    std::cout << "\n\n";
    UseAll_Accesors(someone);
    return 0;
}
//EOF

void UseAll_PersonData_Specific_Accessors(const PersonData& obj)
{
    std::cout
    << "Using all of PersonData class Accessors:\n"
    << "Last Name:  " << obj.getLastName() << "\n"
    << "First Name: " << obj.getFirstName() << "\n"
    << "Address:    " << obj.getAddress() << "\n"
    << "City:       " << obj.getCity() << "\n"
    << "Zip Code:   " << obj.getZip() << "\n"
    << "State:      " << obj.getState() << "\n"
    << "Phone:      " << obj.getPhone() << "\n\n";
}

void UseAll_CustomerData_Specific_Accessors(const CustomerData& obj)
{
    std::cout
    << "Using all of CustomerData class Accessors:\n"
    << "Mailing List Status: " << obj.getMailingListStatus() << "\n"
    << "Customer Number:     " << obj.getCustomerNumber() << "\n\n";
}

void UseAll_PreferredCustomer_Specific_Accessors(const PreferredCustomer& obj)
{
    std::cout
    << "Using all of PreferredCustomer class Accessors:\n"
    << "Purchases Total: " << obj.getPurchasesAmount() << "\n"
    << "Discount Level:  " << obj.getDiscountLevel() << "\n\n";
}
//EOF

void UseAll_Accesors(const PreferredCustomer& obj)
{   
    std::cout
    << "\nUsing all of the possible accessors!\n";
    UseAll_PersonData_Specific_Accessors(obj);
    UseAll_CustomerData_Specific_Accessors(obj);
    UseAll_PreferredCustomer_Specific_Accessors(obj);
}