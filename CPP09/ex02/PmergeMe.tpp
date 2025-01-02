#include "PmergeMe.hpp"

template <typename Container>
PmergeMe<Container>::PmergeMe() {}

template <typename Container>
PmergeMe<Container>::PmergeMe(Container& _C) : C(_C) {}

template <typename Container>
PmergeMe<Container>::~PmergeMe() {}

template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe& r)  { (void)r; }

template <typename Container>
PmergeMe<Container>&  PmergeMe<Container>::operator=(const PmergeMe& r) 
{
    (void) r;
    return *this; 
}

template <typename Container>
int  PmergeMe<Container>::isValid(char *number)
{
    if (!number|| !*number) throw std::runtime_error("Error: invalid number \"" + std::string(number) + "\"");
    for (char *temp = number; *temp; temp++)
        if (!std::isdigit(*temp)) throw std::runtime_error("Error: invalid number \"" + std::string(number) + "\"");
    std::istringstream ss(number);
    unsigned long num;
    ss >> num;
    if (num > INT_MAX || num < 0) throw std::runtime_error("Error: number must be (0 <= number <= INT_MAX)\"" + std::string(number) + "\"");
    return (num);
}

template <typename Container>
void    insertIntoSorted(Container& sorted, typename Container::value_type value)
{
    typename Container::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(pos, value);
}

template <typename Container>
void    mergeInsert(Container& largest, Container& smallest)
{
    for (typename Container::iterator it = smallest.begin(); it != smallest.end(); it++)
        insertIntoSorted(largest, *it);
}

template <typename Container>
Container  fordJohnsonSort(Container& C)
{
    if (C.size() <= 1)
        return C;
    Container smallest, largest;
    for (typename Container::iterator it = C.begin(); it != C.end() && it + 1 != C.end(); it+=2)
    {
        if  (*it > *(it + 1))
        {
            largest.push_back(*it);
            smallest.push_back(*(it + 1));
        }
        else
        {
            smallest.push_back(*it);
            largest.push_back(*(it + 1));
        }
    }
    if (C.size() % 2 != 0)
        smallest.push_back(C.back());
    largest = fordJohnsonSort(largest);
    mergeInsert(largest, smallest);
    return (largest);
}

template <typename Container>
void    PmergeMe<Container>::printContainer(Container& C, const std::string& message)
{
    if (!message.empty())
        std::cout << message;
    int i = 0;
    for (typename Container::iterator it = C.begin(); it != C.end(); it++)
    {
        std::cout << *it << " ";
        if (++i == 3) break ;
    }
    std::cout << "[...]" << std::endl;
}

template <typename Container>
void    PmergeMe<Container>::initContainer(int ac, char **av, Container &C, const std::string& containerType)
{
    if (ac < 3) throw std::runtime_error("Error: not enough arguments.");
    clock_t begin, end;
    begin = clock();
    for (int i = 1; i < ac; i++)
        C.push_back(isValid(av[i]));
    printContainer(C, "Before: ");
    C = fordJohnsonSort(C);
    end = clock();
    printContainer(C, "After: ");
    std::cout << "Time to process a range of " 
        << C.size() << " elements with std::" << containerType
        << " : " << static_cast<double>((end - begin) * CLOCKS_PER_SEC / 1000000)
        << "us\n";
    std::cout << std::endl;
}