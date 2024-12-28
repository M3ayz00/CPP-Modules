#include "RPN.hpp"

int main (int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: ./RPN [Reverse Polish Notation]\n";
        return (1);
    }
    try
    {
        RPN rpn;
        std::cout << rpn.evaluate(av[1]) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}