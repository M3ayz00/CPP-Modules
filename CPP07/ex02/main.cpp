#include <iostream>
#include "Array.hpp"
#include <cstdlib>

class Data
{
  public:
    std::string type;
    unsigned int size;
    Data();
    Data(const std::string& _type, unsigned int size);
    Data& operator=(const Data& D);
    Data(const Data& D);
    ~Data();
    bool  operator>(const Data& D);
    bool  operator<(const Data& D);
    bool  operator==(const Data& D);
};

Data::Data() : type("Some Data Type"), size(8) {}

Data::Data(const std::string& _type, unsigned int _size) : type(_type), size(_size) {}

Data::~Data() {}

Data& Data::operator=(const Data& D)
{
  if (this != &D)
  {
    size = D.size;
    type = D.type;
  }
  return (*this);
}

bool  Data::operator>(const Data& D)
{
  return (size > D.size);
}

bool  Data::operator<(const Data& D)
{
  return (size < D.size);
}

bool  Data::operator==(const Data& D)
{
  return (size == D.size);
}

std::ostream& operator<<(std::ostream& os, const Data& D)
{
  os << D.size << " " << D.type;
  return (os);
}

Data::Data(const Data& D) : type(D.type), size(D.size){}

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
      const Array<int> arr(5);
      try
      {
        std::cout << arr[1] << std::endl;
        std::cout << arr[5] << std::endl;
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
    arr[0] = "before1";
    arr[1] = "before2";
    arr[2] = "before3";
    std::cout << arr[0] << " " << arr[1] << " " << arr[2] << "\n";
    {
      Array<std::string>arr2(arr);
      std::cout << arr2[0] << " " << arr2[1] << " " << arr2[2] << "\n";
      arr[0] = "after1";
      arr[1] = "after2";
      arr[2] = "after3";
      std::cout << arr2[0] << " " << arr2[1] << " " << arr2[2] << "\n";
      arr2[0] = "after1";
      arr2[1] = "after2";
      arr2[2] = "after3";
    }
    std::cout << arr[0] << " " << arr[1] << " " << arr[2] << "\n";
  }
  {
    Array<Data> arr(10);
    for( unsigned int i = 0; i < arr.size(); i++)
      std::cout << arr[i] << std::endl;
    for( unsigned int i = 0; i < arr.size(); i++)
      arr[i] = Data("Some Other Data Type", 16);
    for( unsigned int i = 0; i < arr.size(); i++)
      std::cout << arr[i] << std::endl;
  }
  {
    Array<std::string> arr;
  }
}