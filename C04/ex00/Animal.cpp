#include <iostream>
#include <fstream> 
#include <string>
#include "Animal.hpp"

Animal::Animal() : type("Animal") 
{
    std::cout << "Animal created!" << std::endl;
}
Animal::Animal(const Animal& other) : type(other.type) 
{
    std::cout << "Animal copied!" << std::endl;
}
Animal::~Animal() 
{
    std::cout << "Animal destroyed!" << std::endl;
}
Animal& Animal::operator=(const Animal& other) 
{
    if (this != &other) {
        this->type = other.type;
    }
    std::cout << "Animal assigned!" << std::endl;
    return *this;
}
void Animal::makeSound() const 
{
    std::cout << "Animal sound!" << std::endl;
}
std::string Animal::getType() const 
{
    return this->type;
}
Animal::Animal(const std::string& type) : type(type) 
{
    std::cout << "Animal of type " << type << " created!" << std::endl;
}
