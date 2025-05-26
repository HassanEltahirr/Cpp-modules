#include <iostream>
#include <fstream> 
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"
class Cat : public Animal
{
    private:
        Brain* _brain;
    public:
        Cat();
        Cat(const Cat& other);
        virtual ~Cat();
        Cat& operator=(const Cat& other);
        virtual void makeSound() const;
};