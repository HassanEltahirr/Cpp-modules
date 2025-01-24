#include <iostream>
#include <string>
#include <cstdlib>
#include "Weapon.hpp"
#include "HumanA.hpp"
void HumanA::setname(std::string name)
{
    this->name = name;
}
std::string HumanA::getname()
{
    return name;
}
HumanA::HumanA(const std::string& name, Weapon& weapon) : weapon(weapon)
{
    this->name = name;
}
const std::string& HumanA::gettype() const
{    
    return weapon.gettype();
}
void HumanA::attack() 
{
    std::cout << name << " attacks with their " << weapon.gettype() << std::endl;
}
