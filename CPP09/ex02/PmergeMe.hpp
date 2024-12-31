#pragma once

#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <deque>
#include <sstream>
#include <climits> 

class PmergeMe
{
    private :
        PmergeMe(const PmergeMe& r);
        PmergeMe&  operator=(const PmergeMe& r);
        bool    isValid(char *av);
    public  :
        PmergeMe();
        ~PmergeMe();
        void  addNumbers(int ac, char **av);
};