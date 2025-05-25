#include <iostream>
#include <fstream> 
#include <string>
#include <iostream>
#include "FragTrap.hpp"

int main( void ) 
{
    ClapTrap claptrap("ClapTrap");
    claptrap.attack("target");
    claptrap.takeDamage(5);
    claptrap.beRepaired(3);

    FragTrap fragtrap("FragTrap");
    fragtrap.attack("target");
    fragtrap.takeDamage(5);
    fragtrap.beRepaired(3);
    fragtrap.highFivesGuys();    
    fragtrap.guardGate();
    return 0;
}
