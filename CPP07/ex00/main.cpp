/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:10:45 by msaadidi          #+#    #+#             */
/*   Updated: 2024/12/01 17:17:11 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

// class Data
// {
//   public:
//     std::string type;
//     unsigned int size;
//     Data(const std::string& _type, unsigned int size);
//     Data& operator=(const Data& D);
//     Data(const Data& D);
//     ~Data();
//     bool  operator>(const Data& D);
//     bool  operator<(const Data& D);
//     bool  operator==(const Data& D);
// };

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

// std::ostream& operator<<(std::ostream& os, const Data& D)
// {
//   os << D.size << " " << D.type;
//   return (os);
// }

// Data::Data(const Data& D) : type(D.type), size(D.size){}

int main( void ) 
{
  int a = 2;
  int b = 3;
  ::swap( a, b );
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
  std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
  std::string c = "chaine1";
  std::string d = "chaine2";
  ::swap(c, d);
  std::cout << "c = " << c << ", d = " << d << std::endl;
  std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
  std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;


  // Data data1("Type1", 8);
  // Data data2("Type2", 8);
  // std::cout << data1 << std::endl;
  // std::cout << data2 << std::endl;
  // ::swap(data1, data2);
  // std::cout << data1 << std::endl;
  // std::cout << data2 << std::endl;
  // std::cout << "min( data1, data2) = " << ::min( data1, data2) << std::endl;
  // std::cout << "max( data1, data2) = " << ::max( data1, data2) << std::endl;

  return 0;
}