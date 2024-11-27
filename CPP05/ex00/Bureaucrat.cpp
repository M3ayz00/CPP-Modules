/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:16:37 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/25 18:25:12 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
  return "Grade is too high.\n";
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
  return "Grade is too low.\n";
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

Bureaucrat::Bureaucrat(const Bureaucrat& B) : name(B.name), grade(B.grade)
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

std::string to_string(int nb)
{
  std::ostringstream ss;
  ss << nb;
  return ss.str();
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& B)
{
  os << B.getName() << ", bureaucrat grade " << to_string(B.getGrade()) + ".\n";
  return (os);
}
