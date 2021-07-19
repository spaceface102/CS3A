#ifndef CUSTOMER_DATA_CLASS_H
#define CUSTOMER_DATA_CLASS_H

#include "personData.h"
class CustomerData : public PersonData
{
private:
    static int currentCustomerNumber;   //TRACK - customer number counter
    int customerNumber;                 //PROC - a unique customer number
    bool mailingList;                   //PROC - determines if customer in
                                        //a maling list

public:
    /*****************************
    ** CONSTRUCTOR & DESTRUCTOR **
    *****************************/
    CustomerData(void);

    /*************
    ** MUTATORS **
    *************/
    void updateMailingListStatus(bool status);

    /**************
    ** ACCESSORS **
    **************/
    bool getMailingListStatus(void) const;
    int  getCustomerNumber(void) const;
};

//Initialize for later uses of the class
int CustomerData::currentCustomerNumber = 0;
#endif //CUSTOMER_DATA_CLASS_H