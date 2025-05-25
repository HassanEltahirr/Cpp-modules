#include <iostream>
#include <fstream> 
#include <string>
#include "FragTrap.hpp"
FragTrap::FragTrap()
{
    this->name = "default";
    this->hitpoints = 10;
    this->energy_points = 10;
    this->attack_damage = 0;
    std::cout << "FragTrap " << this->name << " created!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->name = name;
    this->hitpoints = 10;
    this->energy_points = 10;
    this->attack_damage = 0;
    std::cout << "FragTrap " << this->name << " created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
{
    this->name = other.name;
    this->hitpoints = other.hitpoints;
    this->energy_points = other.energy_points;
    this->attack_damage = other.attack_damage;
    std::cout << "FragTrap " << this->name << " copied!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->name << " destroyed!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (this->hitpoints > 0 && this->energy_points > 0)
    {
        std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
        this->energy_points--;
    }
    else
    {
        std::cout << "FragTrap " << this->name << " has no energy points left to attack!" << std::endl;
    }
}

void FragTrap::takeDamage(unsigned int amount)
{
    if (this->hitpoints > 0)
    {
        this->hitpoints -= amount;
        std::cout << "FragTrap " << this->name << " takes " << amount << " points of damage! Hitpoints left: " << this->hitpoints << std::endl;
    }
    else
    {
        std::cout << "FragTrap " << this->name << " is already dead!" << std::endl;
    }
}

void FragTrap::beRepaired(unsigned int amount)
{
    if (this->hitpoints > 0 && this->energy_points > 0)
    {
        this->hitpoints += amount;
        this->energy_points--;
        std::cout << "FragTrap " << this->name << " repairs itself for " << amount << " hitpoints! Hitpoints now: " << this->hitpoints << std::endl;
    }
    else
    {
        std::cout << "FragTrap " << this->name << " has no energy points left to repair!" << std::endl;
    }
}

void FragTrap::guardGate()
{
    std::cout << "FragTrap " << this->name << " is now guarding the gate!" << std::endl;
}

std::string FragTrap::getName() const
{
    return this->name;
}

void FragTrap::setName(std::string name)
{
    this->name = name;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << this->name << " is requesting a high five!" << std::endl;
}