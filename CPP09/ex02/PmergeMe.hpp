#pragma once

#include <iostream>
#include <vector>
#include <list>

class PmergeMe
{
    public  :
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& r);
        PmergeMe&  operator=(const PmergeMe& r);
};