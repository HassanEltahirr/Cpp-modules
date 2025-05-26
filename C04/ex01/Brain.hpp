#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>
#include <fstream> 
#include <string>
#include "Animal.hpp"

class Brain : public Animal
{
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain& other);
        virtual ~Brain();
        Brain& operator=(const Brain& other);
        virtual void makeSound() const;
};
#endif // BRAIN_HPP