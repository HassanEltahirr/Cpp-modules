#include <iostream>
#include <fstream> 
#include <string>
#include <iostream>
#include "ClapTrap.hpp"

int main( void ) 
{
    ClapTrap claptrap1("ClapTrap1");
    ClapTrap claptrap2("ClapTrap2");
    claptrap1.attack("target1");
    claptrap1.takeDamage(5);
    claptrap1.beRepaired(3);
    claptrap2.attack("target2");
    claptrap2.takeDamage(2);
    claptrap2.beRepaired(1);
    return 0;
}