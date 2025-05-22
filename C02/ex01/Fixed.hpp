#include <iostream>
#include <fstream> 
#include <string>
class Fixed  
{
    private:
        int fixedpoint;
        static const int fract = 8;
    public:
        Fixed();
        Fixed(int a);
        Fixed(float a);
        int getFixedPoint() const;
        float toFloat(void)const ;
        int toInt()const;
        Fixed (const Fixed& other);
        int getValue() const;
        ~Fixed();
};
std::ostream& operator<<(std::ostream& out, const Fixed& obj);