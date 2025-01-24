#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
    this->type = "Zombie";
}
void Zombie::announce( void )
{
    if(this->name.empty())
        std::cout << "<" << "unnamed" << " (" << this->type << ")> Braiiiiiiinnnssss..." << std::endl;
    else
    if(this->name == "Foo")
        std::cout << "Foo:" << " BraiiiiiiinnnzzzZ..." << std::endl;
    else
    std::cout << "<" << this->name << ">: BraiiiiiiinnnzzzZ..." << std::endl;
}
Zombie::~Zombie() {
    std::cout << this->name << " is destroyed" << std::endl;
}
Zombie ::Zombie()
{
    this->name = "unnamed";
    this->type = "Zombie";
}
void Zombie::setname(std::string name)
{
    this->name = name;
}
std::string Zombie::getname()
{
    return this->name;
}