/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:39:18 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/25 16:17:39 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <functional>

Intern::Intern()
{
  std::cout << "Intern default constructor called\n";
}

Intern::Intern(const Intern& I)
{
  (void)I;
  std::cout << "Intern copy constructor called\n";
}

Intern::~Intern()
{
  std::cout << "Intern destructor called\n";
}

Intern& Intern::operator=(const Intern& I)
{
  (void)I;
  std::cout << "Intern assignment operator called\n";
  return (*this);
}

AForm*  Intern::makeForm(std::string formName, std::string formTarget)
{
  std::string formTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
  AForm*  (*formCreator[3])(const std::string&) = 
  {
    createShrubberyCreationForm,
    createRobotomyRequestForm,
    createPresidentialPardonForm
  };
  for (int i = 0; i < 3; i++)
  {
    if (!formName.compare(formTypes[i]))
    {
      std::cout << "Intern creates " << formName << std::endl;
      return (formCreator[i](formTarget));
    }
  }
  std::cout << "Error : " << formName << " : Unknown form type.\n";
  return 0;
}
