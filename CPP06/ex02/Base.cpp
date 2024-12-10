/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:17:51 by msaadidi          #+#    #+#             */
/*   Updated: 2024/12/01 17:00:33 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>

Base::~Base(){}

Base* generate(void)
{
  std::srand(std::time(0));
  int random = std::rand();
  if (random % 3 == 0)
    return (new A);
  else if (random % 3 == 1)
    return (new B);
  return (new C);
}

void  identify(Base* p)
{
  if (dynamic_cast<A*>(p) != NULL)
    std::cout << "A\n";
  else if (dynamic_cast<B*>(p) != NULL)
    std::cout << "B\n";
  else if (dynamic_cast<C*>(p) != NULL)
    std::cout << "C\n";
  else
    std::cout << "Unkown type\n";
}

void  identify(Base& p)
{
  try
  {
    A a = dynamic_cast<A&>(p);
    std::cout << "A";
  }
  catch(const std::exception& e)
  {
    try
    {
      B b = dynamic_cast<B&>(p);
      std::cout << "B\n";
    }
    catch(const std::exception& e)
    {
      try
      {
        C c = dynamic_cast<C&>(p);
        std::cout << "C\n";
      }
      catch(const std::exception& e)
      {
        std::cerr << "Uknown type\n";
      }
    }
  }
  
}
