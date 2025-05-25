#include <iostream>
#include <fstream> 
#include <string>
#include <iostream>
#include "ScavTrap.hpp" // <-- this also includes ClapTrap.hpp again

int main( void ) 
{
    ClapTrap claptrap("ClapTrap");
    ScavTrap scavtrap("ScavTrap");

    claptrap.attack("target1");
    scavtrap.attack("target2");

    claptrap.takeDamage(5);
    scavtrap.takeDamage(10);

    claptrap.beRepaired(3);
    scavtrap.beRepaired(5);

    scavtrap.guardGate();

    return 0;
}
// #endif // CLAPTRAP_HPP
