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
        void    insertIntoSorted(Container& sorted, typename Container::value_type value);
        Container  fordJohnsonSort(Container& C);
        PmergeMe();
        Container generateJacobSthal(int n);
        Container generateInsertionSequence(int n);
        void    mergeInsert(Container& mainChain, Container& pend);
        typename Container::iterator  binarySearch(typename Container::iterator first, typename Container::iterator last, typename Container::value_type value);

    public  :
        void    initContainer(int ac, char **av, Container &C, const std::string& containerType);
        PmergeMe(Container& C);
        ~PmergeMe();
};

int mainAlgo(int ac, char **av);

#include "PmergeMe.tpp"