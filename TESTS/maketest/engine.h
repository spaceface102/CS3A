#ifndef ENGINE_CLASS_H
#define ENGINE_CLASS_H

#include <string>
#include <iostream>

class Engine
{
private:
    int displacement;
    int cylinders;
    int horsepower;
public:
    Engine(void);
    Engine(int disp, int cyl, int hp);
    friend std::ostream& operator<<(std::ostream& out, const Engine& obj);
};

#endif //ENGINE_CLASS_H