#include "PmergeMe.hpp"



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
