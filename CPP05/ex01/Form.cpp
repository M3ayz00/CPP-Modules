/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:04:50 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/27 15:12:16 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char * Form::FormAlreadySigned::what() const throw()
{
  return "form is already signed\n";
}

Form::Form() : name("Default Form"), isSigned(false), signGrade(100), execGrade(50)
{
  std::cout << "Form default constructor called\n";
}

Form::Form(const Form& F) : name(F.name), isSigned(F.isSigned), signGrade(F.signGrade), execGrade(F.execGrade)
{
  std::cout << "Form copy constructor called\n";
}

Form::Form(const std::string& _name, const int _signGrade, const int _execGrade) : 
  name(_name), isSigned(false), signGrade(_signGrade), execGrade(_execGrade)
{
  std::cout << "Form constructor called\n";
  if (signGrade > 150)
    throw (GradeTooLowException());
  else if (signGrade < 1)
    throw (GradeTooHighException());
  if (execGrade > 150)
    throw (GradeTooLowException());
  else if (execGrade < 1)
    throw (GradeTooHighException());
}

Form& Form::operator=(const Form& F)
{
  std::cout << "Form assignment operator called\n";
  if (this != &F)
    isSigned = F.isSigned;
  return (*this);
}

Form::~Form()
{
  std::cout << "Form destructor called\n";
}

void  Form::beSigned(Bureaucrat& B)
{
  if (B.getGrade() > getSignGrade())
    throw (GradeTooLowException());
  if (isSigned == true)
    throw (FormAlreadySigned());
  isSigned = true;
}

const std::string&  Form::getName( void ) const
{
  return (name);
}

bool  Form::getSignatureState( void ) const
{
  return (isSigned);
}

int Form::getSignGrade( void ) const
{
  return (signGrade);
}

int Form::getExecGrade( void ) const
{
  return (execGrade);
}

std::ostream& operator<<(std::ostream& os, const Form& F)
{
  os  << "\n    Name : " <<  F.getName()
      << "\n    Sign grade : " << F.getSignGrade()
      << "\n    Execution grade : " << F.getExecGrade()
      << "\n    Is signed : ";
  if (F.getSignatureState() == true)
    os << "yes\n\n";
  else
    os << "no\n\n";
  return (os);
}
