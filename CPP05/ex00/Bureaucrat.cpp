/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:16:37 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/23 13:45:33 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    std::cout << "Bureaucrat default constructor called\n";   
}

Bureaucrat::Bureaucrat(const std::string& _name, uint16_t _grade) : name(_name) , grade(_grade)
{
    std::cout << "Bureaucrat constructor called\n";
    if (grade > 150)
        throw (GradeTooLowException());
    else if (grade < 1)
        throw (GradeTooHighException());
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& B)
{
    if (this != &B)
    {
        name = B.name;
        grade = B.grade;
        std::cout << "Bureaucrat copy assignment operator called\n";
    }
    return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat& B)
{
    *this = B;
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

uint16_t    Bureaucrat::getGrade() const
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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& B)
{
    os << B.getName() + ", bureaucrat grade " + std::to_string(B.getGrade()) + ".\n";
    return (os);
}