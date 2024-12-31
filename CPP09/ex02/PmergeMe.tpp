#include "PmergeMe.hpp"


int  isValid(char *number)
{
    if (!*number) throw std::runtime_error("Error: invalid number \"" + std::string(number) + "\"");
    for (char *temp = number; *temp; temp++)
        if (!std::isdigit(*temp)) throw std::runtime_error("Error: invalid number \"" + std::string(number) + "\"");
    std::istringstream ss(number);
    unsigned long num;
    ss >> num;
    if (num > INT_MAX || num < 0) throw std::runtime_error("Error: invalid number \"" + std::string(number) + "\"");
    return (num);
}

std::pair<int, int> actualPairing(int value1, int value2)
{
    if (value1 > value2)
        return (std::make_pair(value2, value1));
    return (std::make_pair(value1, value2));
}

template <typename Container>
void    initContainer(int ac, char **av, Container &C, int *leftover)
{
    if (ac < 3) throw std::runtime_error("Error: not enough arguments.");
    for (size_t i = 1; i < ac - 1; i+=2)
    {
        if (av[i + 1]) 
            C.push_back(actualPairing(isValid(av[i]), isValid(av[i + 1])));
        else 
            *leftover = isValid(av[i]);
    }
}

template <typename C, typename T>



