/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:52:22 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/25 18:25:39 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
  Bureaucrat *B1[4];
  for (int i = 0; i < 4; i++)
  {
    if ((i + 1) % 2)
    {
      try
      {
        B1[i] = new Bureaucrat("Jake", (i + 1) * 20);
        try 
        {
          std::cout << *(B1[i]);
          B1[i]->decGrade();
          std::cout << *(B1[i]);
          delete B1[i];
        }
        catch (const std::exception& e)
        {
          std::cout << e.what();
          delete B1[i];
        }
      }
      catch (const std::exception& e)
      {
        std::cout << e.what();
      }
    }
    else
    {
      try
      {
        B1[i] = new Bureaucrat("Lyle", (i + 1) * 40);
        try 
        {
          std::cout << *(B1[i]);
          B1[i]->incGrade();
          std::cout << *(B1[i]);
          delete B1[i];
        }
        catch (const std::exception& e)
        {
          std::cout << e.what();
          delete B1[i];
        }
      }
      catch (const std::exception& e)
      {
        std::cout << e.what();
      }
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  {
    try
    {
      Bureaucrat B3("Thompson", 150);
      try
      {
        std::cout << B3;
        B3.decGrade();
        std::cout << B3;
      }
      catch (const std::exception& e)
      {
        std::cout << e.what();
      }
    }
    catch (const std::exception& e)
    {
      std::cout<< e.what();
    }
  }
  std::cout << std::endl;
  {
    try
    {
      Bureaucrat B2("Martin", -1);
      try
      {
        std::cout << B2;
        B2.incGrade();
        std::cout << B2;
      }
      catch (const std::exception& e)
      {
        std::cout << e.what();
      }
    }
    catch (const std::exception& e)
    {
      std::cout<< e.what();
    }
  }
  return (0);
}