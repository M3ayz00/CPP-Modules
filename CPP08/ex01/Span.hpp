#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Span
{
  private :
    unsigned int      N;
    std::vector<int>  numbers;

  public  :
    Span();
    Span(unsigned int _N);
    ~Span();
    Span(const Span& S);
    Span& operator=(const Span& S);

    void  addNumber(int number);
    void  addNumbers(std::vector<int>& _numbers);
    long   shortestSpan() const;
    long   longestSpan() const;


};

#endif