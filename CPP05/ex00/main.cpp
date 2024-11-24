/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:52:22 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/08 18:18:33 by msaadidi         ###   ########.fr       */
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
        B1[i] = new Bureaucrat("Police Officer", (i + 1) * 20);
        try 
        {
          std::cout << B1[i];
          B1[i]->decGrade();
          std::cout << B1[i];
          delete B1[i];
        }
        catch (const Bureaucrat::GradeTooHighException& e)
        {
          std::cout << e.what();
          delete B1[i];
        }
        catch (const Bureaucrat::GradeTooLowException &e)
        {
          std::cout << e.what();
          delete B1[i];
        }
      }
      catch (const Bureaucrat::GradeTooHighException& e)
      {
        std::cout << e.what();
      }
      catch (const Bureaucrat::GradeTooLowException &e)
      {
        std::cout << e.what();
      }
    }
    else
    {
      try
      {
        B1[i] = new Bureaucrat("Fireman", (i + 1) * 20);
        try 
        {
          std::cout << B1[i];
          B1[i]->incGrade();
          std::cout << B1[i];
          delete B1[i];
        }
        catch (const Bureaucrat::GradeTooHighException& e)
        {
          std::cout << e.what();
          delete B1[i];
        }
        catch (const Bureaucrat::GradeTooLowException &e)
        {
          std::cout << e.what();
          delete B1[i];
        }
      }
      catch (const Bureaucrat::GradeTooHighException& e)
      {
        std::cout << e.what();
      }
      catch (const Bureaucrat::GradeTooLowException &e)
      {
        std::cout << e.what();
      }
    }
  }

    // ////////////////////////////////////////////////

  Bureaucrat* B3;
  try
  {
    B3 = new Bureaucrat("Police 0fficer", 150);
    try
    {
      std::cout << *B3;
      B3->decGrade();
      std::cout << *B3;
      delete B3;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
      std::cout << e.what();
      delete B3;
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
      std::cout<< e.what();
      delete B3;
    }
  }
  catch (const Bureaucrat::GradeTooHighException& e)
  {
    std::cout<< e.what();
  }
  catch (const Bureaucrat::GradeTooLowException& e)
  {
    std::cout << e.what();
  }
  Bureaucrat* B2;
  try
  {
    B2 = new Bureaucrat("Fireman", -1);
    try
    {
      std::cout << *B2;
      B2->incGrade();
      std::cout << *B2;
      delete B2;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
      std::cout << e.what();
      delete B2;
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
      std::cout << e.what();
      delete B2;
    }
  }
  catch (const Bureaucrat::GradeTooHighException& e)
  {
    std::cout<< e.what();
  }
  catch (const Bureaucrat::GradeTooLowException& e)
  {
    std::cout << e.what();
  }
  return (0);
}