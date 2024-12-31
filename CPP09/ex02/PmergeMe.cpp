#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& r)  { (void)r; }

PmergeMe&  PmergeMe::operator=(const PmergeMe& r) 
{
    (void) r;
    return *this; 
}

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