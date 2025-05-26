#include <iostream>
#include <fstream> 
#include <string>
#include "Cat.hpp"
Cat::Cat() {
    std::cout << "Cat constructor called" << std::endl;
    _brain = new Brain();
}

Cat::Cat(const Cat& other) {
    std::cout << "Cat copy constructor called" << std::endl;
    *this = other;
    _brain = new Brain(*other._brain); // Assuming Brain has a copy constructor
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) 
    {
        this->type = other.type;
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}
