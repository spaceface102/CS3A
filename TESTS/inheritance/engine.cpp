#include "engine.h"
#include <cstring>

Engine::Engine(void)
{
    strncpy(engineConfig, "V8", ENGINE_CONFIG_LEN);
    strncpy(manufacturer, "Cosworth", MANUFACTURE_NAME_LEN);
    displacement = 2993;
    cylinders = 8;
    maxRpm = 11000;
    idleRpm = 3000;
    torque = 280;
    horsepower = 510;
}

Engine::Engine(const char* _engineConfig, const char* _manufacturer,
        int _displacement, int _cylinders, int _maxRpm, int _idleRpm,
        int _torque, int _horsepower)
{
    strncpy(engineConfig, _engineConfig, ENGINE_CONFIG_LEN);
    strncpy(manufacturer, _manufacturer, MANUFACTURE_NAME_LEN);
    displacement = _displacement;
    cylinders = _cylinders;
    maxRpm = _maxRpm;
    idleRpm = _idleRpm;
    torque = _torque;
    horsepower = _horsepower;
}