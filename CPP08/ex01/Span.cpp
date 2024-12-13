#include "Span.hpp"

Span::Span() : N(0) {}

Span::Span(unsigned int _N) : N(_N) {}

Span::~Span()
{
  numbers.clear();
}

Span::Span(const Span& S) : N(S.N), numbers(S.numbers) {}

Span& Span::operator=(const Span& S)
{
  if (this != &S)
  {
    N = S.N;
    numbers = S.numbers;
  }
  return (*this);
}

void  Span::addNumber(int number)
{
  if (numbers.size() == N)
    throw std::logic_error("Span is full");
  numbers.push_back(number);
}

void  Span::addNumbers(std::vector<int>& _numbers)
{
  if (numbers.size() + _numbers.size() > N)
    throw std::runtime_error("Span size is not enough");
  numbers.insert(numbers.end(), _numbers.begin(), _numbers.end());
}


long Span::shortestSpan() const
{
  if (N < 2)
    throw std::runtime_error("Not enough numbers for span calculation");
  std::vector<int> sortedNumbers = numbers;
  std::sort(sortedNumbers.begin(), sortedNumbers.end());
  long shortestSpan = INT_MAX;
  for (size_t i = 1; i < sortedNumbers.size() - 1; i++)
    shortestSpan = std::min(shortestSpan, static_cast<long>(sortedNumbers[i] - sortedNumbers[i - 1]));
  return (shortestSpan);
}

long Span::longestSpan() const
{
  if (N < 2)
    throw std::runtime_error("Not enough numbers for span calculation");
  long max_it = *std::max_element(numbers.begin(), numbers.end());
  long min_it = *std::min_element(numbers.begin(), numbers.end());
  return (max_it - min_it);
}
