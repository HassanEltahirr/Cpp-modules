#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
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

#endif // ANIMAL_HPP
