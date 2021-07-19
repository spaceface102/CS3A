#ifndef PREFERRED_CUSTOMER_CLASS_H
#define PREFERRED_CUSTOMER_CLASS_H

#include "customerData.h"

class PreferredCustomer : public CustomerData
{
private:
    double purchasesAmount;
    double discountLevel;

public:
    /*****************************
    ** CONSTRUCTOR & DESTRUCTOR **
    *****************************/
    PreferredCustomer(void);

    /*************
    ** MUTATORS **
    *************/
    double makePurchase(double amount);

    /**************
    ** ACCESSORS **
    **************/
    double getPurchasesAmount(void) const;
    double getDiscountLevel(void) const;
private:
    /**************
    **  HELPERS  **
    **************/
    void updateDiscountLevel(void);
    void congratsDiscountLevel(double prevDiscount);
    void yourSavingsToday(double amount);
};

#endif //PREFERRED_CUSTOMER_CLASS_H