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
    ~MutantStack(){}

    typedef typename std::deque<T>::iterator iterator;
    typedef typename std::deque<T>::const_iterator const_iterator;

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    
    const_iterator cbegin() const { return this->c.begin(); }
    const_iterator cend() const { return this->c.end(); }

};

#endif