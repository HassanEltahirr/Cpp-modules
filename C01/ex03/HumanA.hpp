#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include "Weapon.hpp"
class HumanA 
{
    private:
        Weapon& weapon;
        std::string name;
    public:
        const std::string& gettype ()const;
        void setType(std::string &type);
        
        HumanA(const std::string& name, Weapon& weapon);
        HumanA(Weapon& weapon);
        void attack();
        std::string getname();
        void setname(std::string name);
};

#endif