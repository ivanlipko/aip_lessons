#include "dog.h"

#include <math.h>
#include <iostream>

Dog::Dog()
{
    name_ = "Dog";
    weight_ = 3;
    hunger_ = 1;
    age_ = 2;
}

Dog::Dog(std::string name)
{
    name_ = name;
    weight_ = 3;
    hunger_ = 1;
    age_ = 2;
}

void Dog::eat(int food)
{
    weight_ += std::exp(food);
    hunger_ -= food * 0.1;
}

void Dog::bark()
{
    std::cout << "guf... guff!\n";
}

std::string Dog::getInfo()
{
    std::string info;
    info = "Class Dog (" + name_ + ", " + std::to_string(age_) + ", " + std::to_string(weight_) + ", " + std::to_string(hunger_) + ")";
    return info;
}
