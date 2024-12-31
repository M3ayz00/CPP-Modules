#include "PmergeMe.hpp"
#include <sstream>

int main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cerr << "Usage: ./PmergeMe sequence of numbers...\n";
        return (1);
    }
    try
    {
        std::vector<std::pair<int, int>> vec;
        int leftover = -1;
        ::initContainer(ac, av, vec, &leftover);
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
     try
    {
        std::deque<std::pair<int, int>> deq;
        int leftover = -1;
        ::initContainer(ac, av, deq, &leftover);
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}