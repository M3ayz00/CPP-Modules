/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:04:50 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/24 19:14:08 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
// #include "Bureaucrat.hpp"

AForm::AForm() : name("Default Form"), isSigned(false), signGrade(100), execGrade(50)
{
  std::cout << "Form default constructor called\n";
}

AForm::AForm(const AForm& F) : name(F.name), isSigned(F.isSigned), signGrade(F.signGrade), execGrade(F.execGrade)
{
  std::cout << "AForm copy constructor called\n";
  if (signGrade > 150)
    throw (GradeTooLowException());
  else if (signGrade < 1)
    throw (GradeTooHighException());
  if (execGrade > 150)
    throw (GradeTooLowException());
  else if (execGrade < 1)
    throw (GradeTooHighException());
}

AForm::AForm(const std::string& _name, const int _signGrade, const int _execGrade) : 
  name(_name), isSigned(false), signGrade(_signGrade), execGrade(_execGrade)
{
  std::cout << "AForm constructor called\n";
  if (signGrade > 150)
    throw (GradeTooLowException());
  else if (signGrade < 1)
    throw (GradeTooHighException());
  if (execGrade > 150)
    throw (GradeTooLowException());
  else if (execGrade < 1)
    throw (GradeTooHighException());
}

AForm& AForm::operator=(const AForm& F)
{
  if (this != &F)
    isSigned = F.isSigned;
  return (*this);
}

AForm::~AForm()
{
  std::cout << "AForm destructor called\n";
}

void  AForm::beSigned(Bureaucrat& B)
{
  if (B.getGrade() > getSignGrade())
    throw (GradeTooLowException());
  isSigned = true;
}

const std::string&  AForm::getName( void ) const
{
  return (name);
}

bool  AForm::getIsSigned( void ) const
{
  return (isSigned);
}

int AForm::getSignGrade( void ) const
{
  return (signGrade);
}

int AForm::getExecGrade( void ) const
{
  return (execGrade);
}

std::ostream& operator<<(std::ostream& os, const AForm& F)
{
  os  << "Name : " <<  F.getName()
      << "\nSign grade : " << F.getSignGrade()
      << "\nExecution grade : " << F.getExecGrade()
      << "Is signed : \n" << std::boolalpha << F.getIsSigned()
      << std::endl;
  return (os);
}
