#include <iostream>
#include <fstream> 
#include <string>
#include "Fixed.hpp"

Fixed::Fixed()
{
    this->fixedpoint = 0;
}
Fixed::Fixed(float a)
{
    this->fixedpoint = roundf(a *(256));
}
Fixed::~Fixed(){}
Fixed::Fixed (const Fixed& other)
{
    this->fixedpoint = other.fixedpoint;
}
int Fixed::getFixedPoint() const
{
    return this->fixedpoint;
}
int Fixed::toInt( void ) const
{
    int a = this->fixedpoint;
    return(a /256);
}
bool Fixed::operator<(const Fixed& obj) const
{
    if (this->fixedpoint < obj.fixedpoint)
        return true;
    else
        return false;
}
bool Fixed:: operator<=(const Fixed& obj)const
{
    if (this->fixedpoint <= obj.fixedpoint)
        return true;
    else
        return false;
}
bool Fixed:: operator>(const Fixed& obj)const
{
    if (this->fixedpoint > obj.fixedpoint)
        return true;
    else
        return false;
}
bool Fixed:: operator>=(const Fixed& obj)const
{
    if (this->fixedpoint >= obj.fixedpoint)
        return true;
    else
        return false;
}
float Fixed::toFloat( void ) const
{
    return((this->fixedpoint) / (256));
}
        bool Fixed:: operator==(const Fixed& other) const
        {
    if (this->fixedpoint == other.fixedpoint)
    {
        return true;
    }
    else
    {
        return false;
    }
        }
        bool Fixed:: operator!=(const Fixed& obj)const
        {
    if (this->fixedpoint != obj.fixedpoint)
    {
        return true;
    }
    else
    {
        return false;
    }
        }
        Fixed Fixed::operator+(const Fixed& obj)const
        {
            Fixed result;
            result.fixedpoint = this->fixedpoint + obj.fixedpoint;
            return result;
        }
        Fixed Fixed::operator-(const Fixed& obj)const
        {
            Fixed result;
            result.fixedpoint = this->fixedpoint - obj.fixedpoint;
            return result;
        }
        Fixed Fixed::operator*(const Fixed& obj)const
        {
            Fixed result;
            result.fixedpoint = ((this->fixedpoint * obj.fixedpoint) /256);
            return result;
        }
        Fixed Fixed::operator/(const Fixed& obj)const
        {
            Fixed result;
            result.fixedpoint = (this->fixedpoint * 256) / obj.fixedpoint;
            return result;
        }
    std::ostream& operator<<(std::ostream& out, const Fixed& obj)
    {
        out << obj.toFloat();
        return out;
    }
    Fixed Fixed::max(const Fixed& obj1, const Fixed& obj2) 
    {
        if (obj1.fixedpoint > obj2.fixedpoint)
        {
            return obj1;
        }
        else
        {
            return obj2;
        }
    }
    Fixed Fixed::min(const Fixed& obj1,const Fixed& obj2)
        {
        if (obj1.fixedpoint < obj2.fixedpoint)
        {
            return obj1;
        }
        else
        {
            return obj2;
        }
        }

        Fixed Fixed::operator++()
        {
            ++this->fixedpoint;
            return *this;
        }
        Fixed Fixed::operator++(int )
        {
            Fixed whatever = * this;
            this->fixedpoint +=1;
            return whatever;
        }
        Fixed Fixed::operator--(int )
        {   
            Fixed whatever;
            whatever.fixedpoint = this->fixedpoint;
            this->fixedpoint +=1;
            return whatever;
        }
        Fixed Fixed::operator--()
        {
            this->fixedpoint -=1;
            return (*this);
        }