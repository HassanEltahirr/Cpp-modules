#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
    this->type = type;
}
const std::string& Weapon::gettype() const {
    return this->type;
}

void Weapon::setType(std::string type) 
{
    this->type = type;
}
Weapon::Weapon()
{
    this->type = "default";
}