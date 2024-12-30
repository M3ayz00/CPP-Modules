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

void  PmergeMe::addToList(unsigned int num)
{
    container2.push_back(num);
}

void  PmergeMe::addToVec(unsigned int num)
{
    container1.push_back(num);
}
