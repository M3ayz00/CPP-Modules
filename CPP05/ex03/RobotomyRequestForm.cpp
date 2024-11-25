/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 03:51:46 by m3ayz00           #+#    #+#             */
/*   Updated: 2024/11/25 15:59:23 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy request form", 72, 45), target("default")
{
  std::cout << "RobotomyRequestForm Form default constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& _target) : AForm("Robotomy request form", 72, 45), target(_target)
{
  std::cout << "RobotomyRequestForm Form constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& RQF) : AForm(RQF.getName(), RQF.getSignGrade(), RQF.getExecGrade()), target(RQF.target)
{
  std::cout << "RobotomyRequestForm Form copy constructor called\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
  std::cout << "RobotomyRequestForm Form destructor called\n";
}

RobotomyRequestForm&  RobotomyRequestForm::operator=(const RobotomyRequestForm& RQF)
{
  std::cout << "RobotomyRequestForm Form assignment operator called\n";
  if (this != &RQF)
    target = RQF.target; 
  return (*this);
}

void  RobotomyRequestForm::executeAction() const
{
  std::cout << "Drilling noises...\n";
  std::srand(std::time(NULL));
  if (std::rand() % 2)
    std::cout << target << "has been robotomized succesfully\n";
  else
    std::cout << "The robotomy has failed for " << target << std::endl;
}

