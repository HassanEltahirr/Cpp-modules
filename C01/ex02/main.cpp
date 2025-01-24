#include <iostream>
#include <string>
#include <cstdlib>
int main()
{
    std::string name = "HI THIS IS BRAIN";
    std::string *ptr = &name;
    std::string &ref = name;

    std::cout << &name <<std::endl;
    std::cout << ptr<<std::endl;
    std::cout << &ref<<std::endl;

    std::cout << name <<std::endl;
    std::cout << *ptr<<std::endl;
    std::cout << ref<<std::endl;
}