/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:16:37 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/26 14:01:22 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
  return "grade is too high.\n";
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
  return "grade is too low.\n";
}

Bureaucrat::Bureaucrat() : name("default"), grade(50)
{
  std::cout << "Bureaucrat default constructor called\n";   
}

Bureaucrat::Bureaucrat(const std::string& _name, int _grade) : name(_name) , grade(_grade)
{
  std::cout << "Bureaucrat constructor called\n";
  if (grade > 150)
    throw (GradeTooLowException());
  else if (grade < 1)
    throw (GradeTooHighException());
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& B)
{
  std::cout << "Bureaucrat copy assignment operator called\n";
  if (this != &B)
    grade = B.grade;
  return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat& B) : name (B.name), grade(B.grade)
{
  std::cout << "Bureaucrat copy constructor called\n";
}

Bureaucrat::~Bureaucrat()
{
  std::cout << "Bureaucrat detructor called\n";
}

const std::string&  Bureaucrat::getName() const
{
  return (name);
}

int    Bureaucrat::getGrade() const
{
  return (grade);
}

void    Bureaucrat::incGrade()
{
  if (grade - 1 < 1)
    throw (GradeTooHighException());
  grade--;
}

void    Bureaucrat::decGrade()
{
  if (grade + 1 > 150)
    throw (GradeTooLowException());
  grade++;
}

void  Bureaucrat::signForm(AForm& form)
{
  try
  {
    form.beSigned(*this);
    std::cout << getName() << " signed " << form.getName() << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << getName() << " couldn't sign " << form.getName() << " because " <<  e.what();
  }
}

void  Bureaucrat::executeForm(AForm& form)
{
  try
  {
    form.execute(*this);
    std::cout << getName() << " executed " << form.getName() << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << getName() << " couldn't execute " << form.getName() << " because " <<  e.what();
  }
}

std::string to_string(int nb)
{
  std::ostringstream oss;
  oss << nb;
  return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& B)
{
  os << B.getName() << ", bureaucrat grade " << to_string(B.getGrade()) + ".\n";
  return (os);
}

std::ostream& operator<<(std::ostream& os, Bureaucrat* B)
{
  os << B->getName() << ", bureaucrat grade " << to_string(B->getGrade()) + ".\n";
  return (os);
}