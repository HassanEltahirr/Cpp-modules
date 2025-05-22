#include <iostream>
#include <fstream> 
#include <string>
#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout<<"Default constructor called"<<std::endl;
    this->fixedpoint = 0;
}
Fixed::~Fixed()
{
    std::cout<<"Destructor called"<<std::endl;
};
Fixed::Fixed (const Fixed& other)
{
    std::cout<<"Copy constructor called "<<std::endl;   
    this->fixedpoint = other.fixedpoint;
}
int Fixed::getRawBits(void)
{
    std::cout <<"getRawBits member function called"<<std::endl;
    return fixedpoint;
}
Fixed& Fixed::operator = (Fixed const& other)
{
    std::cout<<"Copy assignment operator called // <-- This line may be missing depending on your implementation"<<std::endl;   
    if(this!=&other)
    {
        this->fixedpoint = other.fixedpoint;
    }
    return *this;
}
void Fixed::setRawBits(int const raw)
{
    this->fixedpoint = raw;
}

