#include "vehicle.h"
#include <iostream>

Vehicle::Vehicle(void)
{
    name = "Nissan";
    makeYear = 1997;
}

void Vehicle::ApplyBrakes(void)
{
    std::cout << "I am applying the brakes!\n";
}