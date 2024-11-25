/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 03:51:46 by m3ayz00           #+#    #+#             */
/*   Updated: 2024/11/25 15:58:18 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential pardon form", 25, 5), target("default")
{
  std::cout << "PresidentialPardonForm Form default constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& _target) : AForm("Presidential pardon form", 25, 5), target(_target)
{
  std::cout << "PresidentialPardonForm Form constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& PPF) : AForm(PPF.getName(), PPF.getSignGrade(), PPF.getExecGrade()), target(PPF.target)
{
  std::cout << "PresidentialPardonForm Form copy constructor called\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
  std::cout << "PresidentialPardonForm Form destructor called\n";
}

PresidentialPardonForm&  PresidentialPardonForm::operator=(const PresidentialPardonForm& PPF)
{
  std::cout << "PresidentialPardonForm Form assignment operator called\n";
  if (this != &PPF)
    target = PPF.target; 
  return (*this);
}

void  PresidentialPardonForm::executeAction() const
{
  std::cout << target << " has been pardoned by Zaphod Beeblebrox\n";
}

