#ifndef MUTANT_STACK
#define MUTANT_STACK

#include <iostream>
#include <stack>

template <typename T>
class MutantStack
{
  private :
    std::stack<T> s;

  public  :
    MutantStack();
    ~MutantStack();
    MutantStack(const MutantStack& MS);
    MutantStack& operator=(const MutantStack& MS);
    class Iterator
    {
      private:
        /* data */
      public:
        Iterator();
        ~Iterator();
        Iterator& operator=(const Iterator& it);
        Iterator& operator++(int);
        Iterator& operator++(const Iterator& it);
        Iterator& operator--(int);
        Iterator& operator--(const Iterator& it);
    };
    
};

#endif