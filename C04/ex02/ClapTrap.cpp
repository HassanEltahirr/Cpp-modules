#include <iostream>
#include <fstream> 
#include <string>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    this->name = "default";
    this->hitpoints = 10;
    this->energy_points = 10;
    this->attack_damage = 0;
    std::cout<<"ClapTrap " << this->name << " created!" << std::endl;
}
ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    this->hitpoints = 10;
    this->energy_points = 10;
    this->attack_damage = 0;
    std::cout<<"ClapTrap " << this->name << " created!" << std::endl;
}
ClapTrap::~ClapTrap()
{
    std::cout<<"ClapTrap " << this->name << " destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if(this->hitpoints > 0 && this->energy_points > 0)
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
        this->energy_points--;
    }
    else
    {
        std::cout << "ClapTrap " << this->name << " has no energy points left to attack!" << std::endl;
    }
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if(this->hitpoints > 0)
    {
        this->hitpoints -= amount;
        std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage! Hitpoints left: " << this->hitpoints << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << this->name << " is already dead!" << std::endl;
    }
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if(this->hitpoints > 0 && this->energy_points > 0)
    {
        this->hitpoints += amount;
        this->energy_points--;
        std::cout << "ClapTrap " << this->name << " repairs itself for " << amount << " hitpoints! Hitpoints now: " << this->hitpoints << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << this->name << " has no energy points left to repair!" << std::endl;
    }
}
