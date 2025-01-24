#include "HumanB.hpp"

const std::string& HumanB::gettype() const
{    
    return weapon.gettype();
}
void HumanB::setType(std::string& type) {
    weapon.setType(type);
}

void HumanB::attack() {
    std::cout << name << " attacks with their " << weapon.gettype() << std::endl;
}
std::string HumanB::getname()
{
    return name;
}
HumanB::HumanB()
{
    this->name = "default";
}
HumanB::HumanB(std::string name)
{
    this->name = name;
}
void HumanB::setWeapon(Weapon weapon)
{
    this->weapon = weapon;
}