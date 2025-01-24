#include "Zombie.hpp"
int main()
{
    int n = 5;
    Zombie *zombies = zombieHorde(n, "BOO");
    for (int i = 0; i < n; i++)
    {
        zombies[i].announce();
    }
    delete[] zombies;
}