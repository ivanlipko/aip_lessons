#ifndef DOG_H
#define DOG_H

#include <string>

class Dog
{
    std::string name_;
    int age_;
    float weight_;
    float hunger_;

public:
    Dog();
    Dog(std::string name);

    void eat(int food);
    void bark();
    std::string getInfo();
};

#endif // DOG_H
