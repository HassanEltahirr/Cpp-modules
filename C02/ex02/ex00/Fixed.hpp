#include <iostream>
#include <fstream> 
#include <string>
// #include "Fixed.hpp"

class Fixed  
{
    private:
        int fixedpoint;
        static const int fract = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed (const Fixed& other);
        Fixed& operator = (const Fixed& other);
        int getRawBits(void);
        void setRawBits(int const raw);
};