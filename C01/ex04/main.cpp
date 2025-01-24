#include <iostream>
#include <fstream> 
#include <string>
int main(int ac,char **av)
{
    if(ac != 4)
    {
        std::cout << "Usage: ./replace filename s1 s2" << std::endl;
        return 1;
    }
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    std::fstream file(filename, std::ios::in | std::ios::out);
    std::string line;
    std::ofstream outfile("output.txt");

    while(std::getline(file,line))
    {
        outfile << line << std::endl;
    }
    file.close();
    outfile.close();
    return 0;
}
