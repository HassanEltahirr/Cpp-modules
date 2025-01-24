#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include "Weapon.hpp"
class HumanB 
{
    private:
        std::string name;
        Weapon weapon;
    public:
        const std::string& gettype ()const;
        void setType(std::string &type);
        std::string getname();
        void attack();
        HumanB();
        HumanB(std::string name);
        void setWeapon(Weapon weapon);
};

#endif