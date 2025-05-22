#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class Harl 
{
    private:
        std::string name;
        void debug();
        void info();
        void warning();
        void error();
    public:
        void complain(std::string level);

};
#endif