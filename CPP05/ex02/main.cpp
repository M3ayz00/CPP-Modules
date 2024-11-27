/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:52:22 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/27 15:21:19 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
  {
    try
    {
      ShrubberyCreationForm simpleForm("home");
      std::cout << simpleForm;
      Bureaucrat BC("M3ayz00", 130);
      BC.signForm(simpleForm);
      std::cout << simpleForm;
      BC.executeForm(simpleForm);
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }
  }
  {
    try
    {
      PresidentialPardonForm ppForm("criminal");
      std::cout << ppForm;
      Bureaucrat BC1("Rashford", 1);
      Bureaucrat BC2("Ferguson", 100);
      BC1.signForm(ppForm);
      std::cout << ppForm;
      BC1.signForm(ppForm);
      std::cout << ppForm;
      BC1.executeForm(ppForm);
      BC1.executeForm(ppForm);
      BC2.executeForm(ppForm);
      BC2.signForm(ppForm);
      std::cout << ppForm;
      BC2.signForm(ppForm);
      std::cout << ppForm;
      BC2.executeForm(ppForm);
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }
  }
  {
    try
    {
      RobotomyRequestForm rrForm("Constantine");
      std::cout << rrForm;
      Bureaucrat BC("VegaPunk", 2);
      BC.signForm(rrForm);
      std::cout << rrForm;
      BC.executeForm(rrForm);
      std::cout << rrForm;
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }
  }
  return (0);
}