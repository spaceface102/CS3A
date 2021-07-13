#ifndef ENGINE_CLASS_H
#define ENGINE_CLASS_H

class Engine
{
private:
    static const int ENGINE_CONFIG_LEN = 32;
    static const int MANUFACTURE_NAME_LEN = 128;

    char engineConfig[ENGINE_CONFIG_LEN];   //V8, Flat 4, Horizonalt 16, W8, etc
    char manufacturer[MANUFACTURE_NAME_LEN];//Nissan, Toyota, Honda, Ford, Chevy, Cosworth, etc
    int displacement;   //cc
    int cylinders;
    int maxRpm;
    int idleRpm;
    int torque; //ft-lb
    int horsepower; //bhp

public:
    Engine(void);
    Engine(const char* _engineConfig, const char* _manufacturer,
            int _displacement, int _cylinders, int _maxRpm, int _idleRpm,
            int _torque, int _horsepower
        );
};

#endif //ENGING_CLASS_H