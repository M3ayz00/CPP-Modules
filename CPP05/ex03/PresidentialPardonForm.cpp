/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 03:51:46 by m3ayz00           #+#    #+#             */
/*   Updated: 2024/11/27 15:40:21 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential pardon form", 25, 5), target("default")
{
  std::cout << "PresidentialPardonForm default constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& _target) : AForm("Presidential pardon form", 25, 5), target(_target)
{
  std::cout << "PresidentialPardonForm constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& PPF) : AForm(PPF.getName(), PPF.getSignGrade(), PPF.getExecGrade()), target(PPF.target)
{
  std::cout << "PresidentialPardonForm copy constructor called\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
  std::cout << "PresidentialPardonForm destructor called\n";
}

PresidentialPardonForm&  PresidentialPardonForm::operator=(const PresidentialPardonForm& PPF)
{
  std::cout << "PresidentialPardonForm assignment operator called\n";
  if (this != &PPF)
    target = PPF.target; 
  return (*this);
}

void  PresidentialPardonForm::executeAction() const
{
  std::cout << target << " has been pardoned by Zaphod Beeblebrox\n";
}

