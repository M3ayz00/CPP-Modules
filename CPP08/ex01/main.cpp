#include "Span.hpp"

#include <stack>
int main()
{
  try
  {
    Span span(10);
    span.addNumber(-19);
    span.addNumber(0);
    span.addNumber(-50);
    span.addNumber(2147483647);
    span.addNumber(-2147483648);
    std::vector<int> vec{-1, 1, 2, 3, 4};
    span.addNumbers(vec);

    std::cout << span.shortestSpan() << std::endl;
    std::cout << span.longestSpan() << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
}