#include <iostream>
#include <fstream> 
#include <string>
// #include "Animal.hpp"
#include "Brain.hpp"
class Dog : public Animal
{
    private:
        Brain* _brain;
    public:
        Dog();
        Dog(const Dog& other);
        virtual ~Dog();
        Dog& operator=(const Dog& other);
        virtual void makeSound() const;
};