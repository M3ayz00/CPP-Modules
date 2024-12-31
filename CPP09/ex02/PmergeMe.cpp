#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& r) :container1(r.container1), container2(r.container2) {}

PmergeMe&  PmergeMe::operator=(const PmergeMe& r) 
{
    if (this != &r)
    {
        container1 = r.container1;
        container2 = r.container2;
    } 
    return *this; 
}

bool    PmergeMe::isValid(char *av)
{
    if (std::atoi(av) < 0)
    {
        std::cerr << "Error: invalid number.\n";
        exit(1);
    }
    return true;
}

void  PmergeMe::addNumbers(int ac, char **av)
{
    for (size_t i = 1; i < ac - 1; i += 2)
    {
        if (isValid(av[i]))
        {
            container1.push_back(std::atoi(av[i]));
            container2.push_back(std::atoi(av[i]));
        }
    }

}
