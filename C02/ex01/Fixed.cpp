#include <iostream>
#include <fstream> 
#include <string>
#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout<<"Default constructor called"<<std::endl;
    this->fixedpoint = 0.0;
}
Fixed::Fixed(float a)
{
    this->fixedpoint = roundf(a * 256);
}
Fixed::Fixed(int a)
{
    this->fixedpoint = roundf(a * 256);
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
int Fixed::getFixedPoint() const
{
    return this->fixedpoint;
}
int Fixed::getValue() const
{
    return this->fixedpoint;
}
int Fixed::toInt( void ) const
{
    int a = this->fixedpoint>>8;
    return(a);
}
std::ostream& operator<<(std::ostream& out,const Fixed& obj)
{
    out << obj.toFloat();
    return out;
}
float Fixed::toFloat( void ) const
{
    float a = this->fixedpoint/256.0;
    return(a);
}