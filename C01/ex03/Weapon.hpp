#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class Weapon 
{
    private:
        std::string type;
    public:
        const std::string& gettype ()const;
        void setType(std::string type);
        Weapon(std::string type);
        Weapon();
};

#endif