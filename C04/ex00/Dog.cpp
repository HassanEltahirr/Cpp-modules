#include <iostream>
#include <fstream> 
#include <string>
#include "Dog.hpp"
Dog::Dog() {
    this->type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}
Dog::Dog(const Dog& other) {
    std::cout << "Dog copy constructor called" << std::endl;
    *this = other;
}
Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}
Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other) 
    {
        this->type = other.type;
    }
    return *this;
}
void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}
// std::string Dog::getType() const {
//     return this->type;
// }
std::ostream& operator<<(std::ostream& os, const Dog& dog) {
    os << "Dog type: " << dog.getType();
    return os;
}
