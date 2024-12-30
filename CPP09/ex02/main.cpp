#include "PmergeMe.hpp"
#include <sstream>

int  isValid(char *av)
{
    if (!*av) throw std::runtime_error("Error: invalid number \"" + std::string(av) + "\"");
    for (char *temp = av; *temp; temp++)
    {
        if (!std::isdigit(*temp)) throw std::runtime_error("Error: invalid number \"" + std::string(av) + "\"");
    }
    std::istringstream ss(av);
    unsigned int num;
    ss >> num;
    return (num);
}

int main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cerr << "Usage: ./PmergeMe sequence of numbers...\n";
        return (1);
    }
    try
    {
        PmergeMe merger;
        av++;
        for (; *av; av++)
        {
            merger.addToVec(isValid(*av));
            merger.addToList(isValid(*av));
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}