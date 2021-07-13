#ifndef VEHICLE_CLASS_H
#define VEHICLE_CLASS_H

#include "engine.h"
#include <string>

class Vehicle
{
protected:
    std::string name;
    long vinNumber;
    int makeYear;
    Engine engine;

public:
    Vehicle(void);
    Vehicle(std::string Pname, int vin, int year, const Engine& obj);
    void ApplyBrakes(void);
};

#endif //VEHICLE_CLASS_H