#include <iostream>
#include <fstream> 
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    this->name = "default";
    this->hitpoints = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
    std::cout<<"ScavTrap " << this->name << " created!" << std::endl;
}
ScavTrap::ScavTrap(std::string name)
{
    this->name = name;
    this->hitpoints = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
    std::cout<<"ScavTrap " << this->name << " created!" << std::endl;
}
ScavTrap::~ScavTrap()
{
    std::cout<<"ScavTrap " << this->name << " destroyed!" << std::endl;
}
void ScavTrap::attack(const std::string& target)
{
    if(this->hitpoints > 0 && this->energy_points > 0)
    {
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
        this->energy_points--;
    }
    else
    {
        std::cout << "ScavTrap " << this->name << " has no energy points left to attack!" << std::endl;
    }
}
void guardGate()
{
    std::cout << "ScavTrap " << this->name << " is now in Gate Keeper mode!" << std::endl;
}
