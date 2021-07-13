#ifndef VEHICLE_CLASS_H
#define VEHICLE_CLASS_H

#include <string>
#include "endian.h";

class Vehicle
{
private:
    static const int MAKE_LEN = 128;
    static const int MODEL_LEN = 128;
    char make[MAKE_LEN];
    char model[MODEL_LEN];
    int yearMade;
    int color;  //some sort of hex code

public:
    Vehicle(void);
    ~Vehicle();
};

#endif //VEHICLE_CLASS_H