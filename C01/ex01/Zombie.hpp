#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class Zombie 
{
    private:
        std::string name;
    public:
        void announce( void );
        std ::string getname();
        void setname(std::string name);
        Zombie(std::string name);
        Zombie();
         ~Zombie(); 
        std::string type;
};
Zombie* newZombie(std::string name);
void randomChump(std::string name);
Zombie* zombieHorde( int N, std::string name );

#endif