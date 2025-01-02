#include "PmergeMe.hpp"
#include <ctime>

int main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cerr << "Usage: ./PmergeMe (sequence of numbers...)\n";
        return (1);
    }
    try
    {
        std::vector<int> vec;
        PmergeMe<std::vector<int> > apah(vec);
        apah.initContainer(ac, av, vec, "vector");
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::deque<int> deq;
        PmergeMe<std::deque<int> > apah(deq);
        apah.initContainer(ac, av, deq, "deque");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}