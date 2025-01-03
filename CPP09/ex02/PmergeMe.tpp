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
Container PmergeMe<Container>::generateJacobSthal(int n) 
{
    Container jSequence;
    jSequence.push_back(0);
    jSequence.push_back(1);
    
    while (jSequence.back() < n) {
        typename Container::value_type next = jSequence[jSequence.size() - 1] + 2 * jSequence[jSequence.size() - 2];
        if (next > n) break;
        jSequence.push_back(next);
    }
    return (jSequence);
}

template <typename Container>
Container PmergeMe<Container>::generateInsertionSequence(int n) 
{
    Container jacob = generateJacobSthal(n);
    Container sequence;
    
    for (size_t i = 1; i < jacob.size(); i++) {
        for (int k = jacob[i]; k > jacob[i - 1]; k--)
            if (k <= n) sequence.push_back(k - 1);
    }
    return sequence;
}

template <typename Container>
typename Container::iterator  PmergeMe<Container>::binarySearch(typename Container::iterator first, typename Container::iterator last, typename Container::value_type value)
{
    while (first < last)
    {
        typename Container::iterator mid = first + (last - first) / 2;
        if (*mid == value)
            return mid;
        else if (value > *mid)
            first = mid + 1;
        else
            last = mid;
    }
    return (first);
}


template <typename Container>
void    PmergeMe<Container>::insertIntoSorted(Container& sorted, typename Container::value_type value)
{
    typename Container::iterator pos = binarySearch(sorted.begin(), sorted.end(), value);
    // if (*pos != value)
    sorted.insert(pos, value);
}

template <typename Container>
void    PmergeMe<Container>::mergeInsert(Container& mainChain, Container& pend)
{
    Container insertionOrder = generateInsertionSequence(pend.size());
    for (size_t i = 0; i < insertionOrder.size() ; i++)
        insertIntoSorted(mainChain, pend[insertionOrder[i]]);
}

template <typename Container>
Container  PmergeMe<Container>::fordJohnsonSort(Container& C)
{
    if (C.size() <= 1) return C;
    Container mainChain, pend;
    bool hasStraggler = C.size() % 2;
    typename Container::value_type straggler;
    for (size_t i = 0; i < C.size() - (hasStraggler ? 1 : 0); i += 2)
    {
        if (C[i] > C[i + 1]) 
        {
            mainChain.push_back(C[i]);
            pend.push_back(C[i + 1]);
        } 
        else 
        {
            mainChain.push_back(C[i + 1]);
            pend.push_back(C[i]);
        }
    }
    if (hasStraggler) 
        straggler = C.back();
    mainChain = fordJohnsonSort(mainChain);
    mergeInsert(mainChain, pend);
    if (hasStraggler)
        insertIntoSorted(mainChain, straggler);
    return (mainChain);
}

template <typename Container>
void    PmergeMe<Container>::printContainer(Container& C, const std::string& message)
{
    if (!message.empty())
        std::cout << message;
    // int i = 0;
    for (typename Container::iterator it = C.begin(); it != C.end(); it++)
    {
        std::cout << *it << " ";
        // if (++i == 3) break ;
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
        << " : " << ((static_cast<double>(end - begin) / CLOCKS_PER_SEC) * 1000000)
        << "us\n";
    std::cout << std::endl;
}

int mainAlgo(int ac, char **av)
{
    if (ac == 1)
    {
        std::cerr << "Usage: ./PmergeMe (sequence of numbers...)\n";
        return (1);
    }
    try
    {
        std::vector<int> vec;
        PmergeMe<std::vector<int> > FJ(vec);
        FJ.initContainer(ac, av, vec, "vector");
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::deque<int> deq;
        PmergeMe<std::deque<int> > FJ(deq);
        FJ.initContainer(ac, av, deq, "deque");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}