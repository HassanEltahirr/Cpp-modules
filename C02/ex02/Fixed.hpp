#include <iostream>
#include <fstream> 
#include <string>
class Fixed  
{
    private:
        float fixedpoint;
        static const int fract = 8;
    public:
        Fixed();
        int getFixedPoint() const;
        float toFloat(void)const ;
        int toInt()const;
        Fixed(float a);
        Fixed (const Fixed& other);
        int getValue() const;
        ~Fixed();
        bool operator<(const Fixed& obj)const;
        bool operator>(const Fixed& obj)const;
        bool operator>=(const Fixed& obj)const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& obj)const;
        Fixed operator+(const Fixed& obj)const;
        Fixed operator-(const Fixed& obj)const;
        Fixed operator*(const Fixed& obj)const;
        Fixed operator/(const Fixed& obj)const;
        Fixed operator++();
        Fixed operator--();
        Fixed operator++(int);
        Fixed operator--(int);
        Fixed min(const Fixed& obj1, const Fixed& obj2) ;
        // static Fixed& max(Fixed& obj1,Fixed& obj2) ;
        static Fixed max(const Fixed& obj1, const Fixed& obj2);
};
std::ostream& operator<<(std::ostream& out, const Fixed& obj);
