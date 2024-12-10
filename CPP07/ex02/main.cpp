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
      numbers[-2] = 0;
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
    Array<int> arr(5);
    try
    {
      std::cout << arr[2] << std::endl;
    }
    catch (const std::out_of_range& e)
    {
      std::cout << e.what() << std::endl;
    }
  }
  {
    Array<std::string>arr(3);
    arr[0] = "pixou";
    arr[1] = "appah";
    arr[2] = "okdaaa";
    std::cout << arr[0] << " " << arr[1] << " " << arr[2] << "\n";
    Array<std::string>arr2(arr);
    arr2[0] = "pixou2";
    arr2[1] = "appah2";
    arr2[2] = "okdaaa2";
    std::cout << arr2[0] << " " << arr2[1] << " " << arr2[2] << "\n";
  }
  // {
  //   int * ptr = new int();
  //   std::cout << "PTR VALUE = " << *ptr << "\n";
  //   delete ptr;
  // }
  return 0;
}