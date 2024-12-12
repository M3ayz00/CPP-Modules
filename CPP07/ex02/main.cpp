#include <iostream>
#include "Array.hpp"
#include <cstdlib>

#define MAX_VAL 750
int main(int, char**)
{
  {
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
      const int value = rand();
      numbers[i] = value;
      mirror[i] = value;
    }
    //SCOPE
    {
      Array<int> tmp = numbers;
      Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
      if (mirror[i] != numbers[i])
      {
        std::cerr << "didn't save the same value!!" << std::endl;
        return 1;
      }
    }
    try
    {
      numbers[-1] = 0;
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }
    try
    {
      numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
      numbers[i] = rand();
    delete [] mirror;//
  }
  {
    {
      Array<int> arr;
      try
      {
        std::cout << arr[0] << std::endl;
      }
      catch(const std::exception& e)
      {
        std::cerr << e.what() << '\n';
      }
    }
    {
      const Array<int> arr(5);
      try
      {
        std::cout << arr[0] << std::endl;
        // arr[0] = 1;
        // std::cout << arr[0] << std::endl;
      }
      catch (const std::out_of_range& e)
      {
        std::cout << e.what() << std::endl;
      }
    }
    {
      Array<int> arr(5);
      try
      {
        std::cout << arr[0] << std::endl;
        arr[0] = 1;
        std::cout << arr[0] << std::endl;
      }
      catch (const std::out_of_range& e)
      {
        std::cout << e.what() << std::endl;
      }
    }
  }
  {
    Array<std::string>arr(3);
    arr[0] = "test1";
    arr[1] = "test2";
    arr[2] = "test3";
    std::cout << arr[0] << " " << arr[1] << " " << arr[2] << "\n";
    Array<std::string>arr2(arr);
    std::cout << arr2[0] << " " << arr2[1] << " " << arr2[2] << "\n";
    arr2[0] = "1test";
    arr2[1] = "2test";
    arr2[2] = "3test";
    std::cout << arr2[0] << " " << arr2[1] << " " << arr2[2] << "\n";
  }
  // {
  //   int * ptr = new int();
  //   std::cout << "PTR VALUE = " << *ptr << "\n";
  //   delete ptr;
  // }

  return 0;
}