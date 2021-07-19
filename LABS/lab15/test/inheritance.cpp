#include <iostream>

class Animal
{
public:
    virtual void speak(void)
    {
        std::cout << "Animal\n";
    }

    void printNumber(int number)
    {
        std::cout << number << "\n";
    }

    virtual void walk(void) = 0;
};

class Pig : public Animal
{
public:
    void speak(void) override
    {
        std::cout << "Oink!\n";
    }

    void printNumber(int number)
    {
        std::cout << "Hello " << number << "\n";
    }

    void walk(void) override
    {
        std::cout << "A skip as and a hop\n";
    }
};

class Mammal
{
public:
    virtual void milky(void)
    {
        std::cout << "One of my key features fr "
        << "I be lactiating n shit\n";
    }

    void walk(void)
    {
        std::cout << "WALK Mammal\n";
    }
};

class Dog : public Animal, public Mammal
{
public:
    void speak(void) override
    {
        std::cout << "Bark!\n";
    }

    void somethingDiff(void)
    {
        std::cout << "I don't know! I just be diff\n";
    }

    void walk(void) override
    {
        std::cout << "Walking and wagging my tail!\n";
    }
};

int main(void)
{
    Dog tree;
    Pig porker;
    Animal *animal_ptr;
    Mammal *mammal_ptr;

    porker.printNumber(32);
    animal_ptr = &porker;
    animal_ptr->printNumber(32);
    animal_ptr->speak();
    animal_ptr->walk();
    std::cout << "\n";

    animal_ptr = &tree;
    animal_ptr->walk();
    animal_ptr->speak();
    tree.somethingDiff();

    std::cout << "\n";
    mammal_ptr = &tree;
    mammal_ptr->milky();
    mammal_ptr->walk();
    
}