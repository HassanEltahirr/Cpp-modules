#include "Zombie.hpp"
int main()
{
    Zombie *zombie = new Zombie("Foo");
    zombie->announce();
    randomChump("Bar");
    delete zombie;
    return 0;
}