/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:03:35 by msaadidi          #+#    #+#             */
/*   Updated: 2024/12/03 09:30:37 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

// class Data
// {
//   public:
//     std::string type;
//     unsigned int size;
//     Data();
//     Data(const std::string& _type, unsigned int size);
//     Data& operator=(const Data& D);
//     Data(const Data& D);
//     ~Data();
//     bool  operator>(const Data& D);
//     bool  operator<(const Data& D);
//     bool  operator==(const Data& D);
// };

// Data::Data() : type("Some Data Type"), size(8) {}

// Data::Data(const std::string& _type, unsigned int _size) : type(_type), size(_size) {}

// Data::~Data() {}

// Data& Data::operator=(const Data& D)
// {
//   if (this != &D)
//   {
//     size = D.size;
//     type = D.type;
//   }
//   return (*this);
// }
// bool  Data::operator>(const Data& D)
// {
//   return (size > D.size);
// }

// bool  Data::operator<(const Data& D)
// {
//   return (size < D.size);
// }

// bool  Data::operator==(const Data& D)
// {
//   return (size == D.size);
// }

// std::ostream& operator<<(std::ostream& os, const Data& D)
// {
//   os << D.size << " " << D.type;
//   return (os);
// }

// Data::Data(const Data& D) : type(D.type), size(D.size){}


template <typename T>
void  printElement(T& elem)
{
  std::cout << elem << "\n";
}

template <typename _type>
void  fortyTwo(_type& elem)
{
  elem = 42;
}

template <typename chiType>
void  addOne(chiType& elem)
{
  elem++;
}

int main()
{
  std::cout << "----------------------------------------------------------" << std::endl;
  int arr[5] = {0, 1, 2, 3, 4};
  int sizeArr = sizeof(arr) / sizeof(arr[0]);
  iter(arr, sizeArr, printElement);
  std::cout << std::endl;
  iter(arr, sizeArr, fortyTwo);
  iter(arr, sizeArr, printElement);
  std::cout << "----------------------------------------------------------" << std::endl;
  int arr1[10] = {452, -123, 2689, -38, 455, -498, 212121, -6849865, 6565, -987987};
  int sizeArr1 = sizeof(arr1) / sizeof(arr1[0]);
  iter(arr1, sizeArr1, printElement);
  std::cout << std::endl;
  iter(arr1, sizeArr1, addOne);
  iter(arr1, sizeArr1, printElement);
  std::cout << "----------------------------------------------------------" << std::endl;
  int arr2[2] = {2147483647, -2147483648};
  int sizeArr2 = sizeof(arr2) / sizeof(arr2[0]);
  iter(arr2, sizeArr2, printElement);
  std::cout << std::endl;
  iter(arr2, sizeArr2, addOne);
  iter(arr2, sizeArr2, printElement);
  std::cout << "----------------------------------------------------------" << std::endl;
  float arr3[3] = {13.6545f, -123123.123f, 0.001f};
  int sizeArr3 = sizeof(arr3) / sizeof(arr3[0]);
  iter(arr3, sizeArr3, printElement);
  std::cout << std::endl;
  iter(arr3, sizeArr3, addOne);
  iter(arr3, sizeArr3, printElement);
  std::cout << "----------------------------------------------------------" << std::endl;
  char arr4[5] = {'a', '0', '4', '8', 'y'};
  int sizeArr4 = sizeof(arr4) / sizeof(arr4[0]);
  iter(arr4, sizeArr4, printElement);
  std::cout << std::endl;
  iter(arr4, sizeArr4, addOne);
  iter(arr4, sizeArr4, printElement);
  std::cout << "----------------------------------------------------------" << std::endl;
  // Data arr5[5];
  // iter(arr5, 5, printElement);
}