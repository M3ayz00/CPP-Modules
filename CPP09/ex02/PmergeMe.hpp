#pragma once

#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <deque>
#include <sstream>
#include <climits> 
#include <ctime>    

template <typename Container>
class PmergeMe
{
    private :
        Container C;
        PmergeMe(const PmergeMe& r);
        PmergeMe&  operator=(const PmergeMe& r);
        int  isValid(char *number);
        void  printContainer(Container& C, const std::string& message);
    public  :
        void    initContainer(int ac, char **av, Container &C, const std::string& containerType);
        PmergeMe();
        PmergeMe(Container& C);
        ~PmergeMe();
};


#include "PmergeMe.tpp"