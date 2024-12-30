#pragma once

#include <iostream>
#include <vector>
#include <list>

class PmergeMe
{
    private :
        std::vector<int> container1;
        std::list<int> container2;
        PmergeMe(const PmergeMe& r);
        PmergeMe&  operator=(const PmergeMe& r);
    public  :
        PmergeMe();
        ~PmergeMe();
        void  addToList(unsigned int num);
        void  addToVec(unsigned int num);
};