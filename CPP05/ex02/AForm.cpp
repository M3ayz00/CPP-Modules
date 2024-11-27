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

const char * AForm::FormNotSigned::what() const throw()
{
  return "form is not signed\n";
}

const char * AForm::FormAlreadySigned::what() const throw()
{
  return "form is already signed\n";
}

const char * AForm::FormAlreadyExecuted::what() const throw()
{
  return "form is already executed\n";
}

AForm::AForm() : name("Default Form"), isSigned(false), isExecuted(false), signGrade(100), execGrade(50)
{
  std::cout << "Form default constructor called\n";
}

AForm::AForm(const AForm& F) : name(F.name), isSigned(F.isSigned), isExecuted(F.isExecuted), signGrade(F.signGrade), execGrade(F.execGrade)
{
  std::cout << "AForm copy constructor called\n";
}

AForm::AForm(const std::string& _name, const int _signGrade, const int _execGrade) : 
  name(_name), isSigned(false), isExecuted(false), signGrade(_signGrade), execGrade(_execGrade)
{
  std::cout << "AForm constructor called\n";
  if (signGrade > 150 || execGrade > 150)
    throw (GradeTooLowException());
  else if (signGrade < 1 || execGrade < 1)
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
  if (isSigned == true)
    throw (FormAlreadySigned());
  isSigned = true;
}

void  AForm::execute(Bureaucrat& B)
{
  if (B.getGrade() > getExecGrade())
    throw (GradeTooLowException());
  if (!isSigned)
    throw (FormNotSigned());
  if (isExecuted)
    throw (FormAlreadyExecuted());
  executeAction();
  isExecuted = true;
}

const std::string&  AForm::getName( void ) const
{
  return (name);
}

bool  AForm::getSignatureState( void ) const
{
  return (isSigned);
}

bool  AForm::getExecutionState( void ) const
{
  return (isExecuted);
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
  os  << "\n    Name : " <<  F.getName()
      << "\n    Sign grade : " << F.getSignGrade()
      << "\n    Execution grade : " << F.getExecGrade()
      << "\n    Is signed : ";
  if (F.getSignatureState() == true)
    os << "yes";
  else
    os << "no";
  os << "\n    Is executed : ";
  if (F.getExecutionState() == true)
    os << "yes\n\n";
  else
    os << "no\n\n";
  return (os);
}
