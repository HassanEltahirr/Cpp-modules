#include <iostream>
#include <fstream> 
#include <string>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    this->name = "ScavTrap";
    this->hitpoints = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
    std::cout<<"ScavTrap " << this->name << " created!" << std::endl;
}
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " is now in Gate Keeper mode!" << std::endl;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
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
void ScavTrap::takeDamage(unsigned int amount)
{
    if(this->hitpoints > 0)
    {
        this->hitpoints -= amount;
        std::cout << "ScavTrap " << this->name << " takes " << amount << " points of damage! Hitpoints left: " << this->hitpoints << std::endl;
    }
    else
    {
        std::cout << "ScavTrap " << this->name << " is already dead!" << std::endl;
    }
}
void ScavTrap::beRepaired(unsigned int amount)
{
    if(this->hitpoints > 0 && this->energy_points > 0)
    {
        this->hitpoints += amount;
        this->energy_points--;
        std::cout << "ScavTrap " << this->name << " repairs itself for " << amount << " hitpoints! Hitpoints now: " << this->hitpoints << std::endl;
    }
    else
    {
        std::cout << "ScavTrap " << this->name << " has no energy points left to repair!" << std::endl;
    }
}   