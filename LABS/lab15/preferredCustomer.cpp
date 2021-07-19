#include "preferredCustomer.h"
#include <iostream>
#include <iomanip>

PreferredCustomer::PreferredCustomer(void)
{
    purchasesAmount = 0.0;
    discountLevel = 0.0;
}

double PreferredCustomer::makePurchase(double amount)
{
    double previousDiscountLevel;

    if (amount < 0.0)
    {
        std::cout
        << "Purchases can not be less than $0.00!\n"
        << "Please try again.\n";
        return 0;
    }
    previousDiscountLevel = discountLevel;
    purchasesAmount += amount;
    updateDiscountLevel();
    congratsDiscountLevel(previousDiscountLevel);
    yourSavingsToday(amount);

    return amount*(1 - discountLevel);
}
//EOF

double PreferredCustomer::getPurchasesAmount(void) const
{
    return purchasesAmount;
}
//EOF

double PreferredCustomer::getDiscountLevel(void) const
{
    return discountLevel;
}
//EOF

void PreferredCustomer::updateDiscountLevel(void)
{
    if (purchasesAmount >= 2000)
        discountLevel = 0.10;
    else if (purchasesAmount >= 1500)
        discountLevel = 0.07;
    else if (purchasesAmount >= 1000)
        discountLevel = 0.06;
    else if (purchasesAmount >= 500)
        discountLevel = 0.05;
    else
        discountLevel = 0;
}
//EOF

void PreferredCustomer::congratsDiscountLevel(double prevDiscount)
{
    if (prevDiscount != discountLevel)
    {
        std::cout
        << "CONGRATULATIONS " << getFirstName() << " " << getLastName() << "\n"
        << "Your discount level went from " << prevDiscount*100 << "%% to "
        << discountLevel*100 << "%%!\n"
        << "Hope you continue to shop with us!\n";

        switch ((int)(discountLevel*100))
        {
            case 5: case 6: case 7:
                std::cout
                << "You are closer than you think to the\n"
                << "next discount level!\n"
                << "Only $";
        }

        switch ((int)(discountLevel*100))
        {
            case 5:
                std::cout
                << 1000.0 - purchasesAmount
                << " till you get our 6%% discount!\n";
                break;
            case 6:
                std::cout << 1500.0 - purchasesAmount
                << " till you get our 7%% discount!\n";
                break;
            case 7:
                std::cout << 2000.0 - purchasesAmount
                << " till you get our 10%% discount!\n";
                break;
        }
    }
}
//EOF

void PreferredCustomer::yourSavingsToday(double amount)
{   
    static std::string mailingDecision;    //PROC - get decision mailinglist

    std::cout
    << "Your savings today\n"
    << "You would have payed: $" << amount << "\n"
    << "You payed:            $" << amount*(1-discountLevel) << "\n"
    << "Thats a savings of:   $" << amount*discountLevel << "\n";

    if (!getMailingListStatus())
    {
        std::cout
        << "\n\nWould you like to even more?\n"
        << "Subscribe to our maling list today!\n"
        << "Be the first to know when we have flash sales!\n"
        << "Would you like to be part of the mailing list?\n"
        << "Y/N: ";

        std::cin >> mailingDecision;
        if (mailingDecision == "y" || mailingDecision == "Y")
        {
            std::cout
            << "You will be getting a booklet with all sorts of info\n"
            << "mailed to you house bi-weekly!\n"
            << getAddress() << " " << getCity() << " " << getZip() << "\n";

            updateMailingListStatus(true);
        }
        else
        {
            std::cout
            << "Thank you!\n"
            << "Hope you continue shoping with us!\n";
            //by default mailing list status is false.
        }
    }
}
//EOF