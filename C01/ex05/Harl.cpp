#include <iostream>
#include <fstream> 
#include <string>
#include "Harl.hpp"

void Harl::complain(std::string level)
{
  typedef void (Harl::*func)();
  func complaints[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
  std::string levels[] = {"debug", "info", "warning", "error"};
    for(int i = 0; i < 4; i++)
    {
        if(level == levels[i])
        {
        (this->*complaints[i])();
        return;
        }
    }
    std::cout << "Unknown level" << std::endl;
}
void Harl::debug()
{
    std::cout << "Debug" << std::endl;
}
void Harl::info()
{
    std::cout << "Info" << std::endl;
}
void Harl::warning()
{
    std::cout << "Warning" << std::endl;
}
void Harl::error()
{
    std::cout << "Error" << std::endl;
}
