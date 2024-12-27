#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    (void) av;
    if (ac != 2)
    {
        std::cout << "Error: could not open file.\n";
        return 1;
    }
    BitcoinExchange btc;
    if (!btc.loadDatabase("cpp_09/data.csv")) return (1);
    btc.processInput(av[1]);
    return 0;
}