#include <iostream>
#include <fstream> 
#include <string>
#ifndef ANIMAL_HPP
#define ANIMAL_HPP
class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(const Animal& other);
        virtual ~Animal();
        Animal& operator=(const Animal& other);
        virtual void makeSound() const;
        std::string getType() const;
        Animal(const std::string& type);
};
#endif