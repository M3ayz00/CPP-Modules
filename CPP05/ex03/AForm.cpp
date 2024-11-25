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
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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
  if (isSigned == true)
    throw (FormAlreadySigned());
  if (B.getGrade() > getSignGrade())
    throw (GradeTooLowException());
  isSigned = true;
}

void  AForm::execute(Bureaucrat& B)
{
  if (isExecuted)
    throw (FormAlreadyExecuted());
  if (!isSigned)
    throw (FormNotSigned());
  if (B.getGrade() > getExecGrade())
    throw (GradeTooLowException());
  executeAction();
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

void  AForm::confirmExecution( void )
{
  isExecuted = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& F)
{
  os  << "Name : " <<  F.getName()
      << "\nSign grade : " << F.getSignGrade()
      << "\nExecution grade : " << F.getExecGrade()
      << "Is signed : \n" << std::boolalpha << F.getSignatureState()
      << std::endl;
  return (os);
}

AForm*  createPresidentialPardonForm(const std::string& _target)
{
  return new PresidentialPardonForm(_target);
}

AForm*  createShrubberyCreationForm(const std::string& _target)
{
  return new ShrubberyCreationForm(_target);
}

AForm*  createRobotomyRequestForm(const std::string& _target)
{
  return new RobotomyRequestForm(_target);
}