#include "customerData.h"

long CustomerData::currentCustomerNumber = 0;
CustomerData::CustomerData(void)
{
    customerNumber = CustomerData::currentCustomerNumber++;
    mailingList = false;
}
//EOF

void CustomerData::updateMailingListStatus(bool status)
{
    mailingList = status;
}
//EOF

bool CustomerData::getMailingListStatus(void) const
{
    return mailingList;
}
//EOF

int CustomerData::getCustomerNumber(void) const
{
    return customerNumber;
}
//EOF