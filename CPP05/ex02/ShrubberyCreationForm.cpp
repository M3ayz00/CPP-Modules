/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m3ayz00 <m3ayz00@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 03:51:46 by m3ayz00           #+#    #+#             */
/*   Updated: 2024/11/25 04:58:44 by m3ayz00          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", 145, 137), target("default")
{
  std::cout << "ShrubberyCreation Form default constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& _target) : AForm("ShrubberyCreation", 145, 137), target(_target)
{
  std::cout << "ShrubberyCreation Form constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& SCF) : AForm(SCF.getName(), SCF.getSignGrade(), SCF.getExecGrade()), target(SCF.target)
{
  std::cout << "ShrubberyCreation Form copy constructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
  std::cout << "ShrubberyCreation Form destructor called\n";
}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=(const ShrubberyCreationForm& SCF)
{
  std::cout << "ShrubberyCreation Form assignment operator called\n";
  if (this != &SCF)
    target = SCF.target; 
  return (*this);
}

void  ShrubberyCreationForm::executeAction() const
{
  std::ofstream outFile((target + "_shrubbery").c_str()); 
  if (outFile.is_open())
  {
    outFile << "ASCII Trees\n";//to modify later
    outFile.close();
  }
}