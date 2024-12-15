#ifndef MUTANT_STACK
#define MUTANT_STACK

#include <iostream>
#include <stack>
#include <vector>

template <typename T>
class MutantStack : public std::stack<T>
{
  public  :
    MutantStack(){}
    virtual ~MutantStack(){}
    typedef typename std::deque<T>::iterator iterator;
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
};

#endif