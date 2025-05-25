#include <iostream>
#include <fstream> 
#include <string>
#include "ClapTrap.hpp"
class FragTrap: public ClapTrap
{
    private:
        std::string name;
        int hitpoints;
        int energy_points;
        int attack_damage;
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& other);
        ~FragTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void guardGate();
        std::string getName() const;
        void setName(std::string name);
        void highFivesGuys();
};