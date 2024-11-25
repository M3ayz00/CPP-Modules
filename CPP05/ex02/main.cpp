/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:52:22 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/25 17:09:06 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
  {
    ShrubberyCreationForm simpleForm("home");
    Bureaucrat BC("M3ayz00", 130);
    BC.signForm(simpleForm);
    BC.executeForm(simpleForm);
  }
  {
    PresidentialPardonForm ppForm("cirminal");
    Bureaucrat BC1("Pixou", 1);
    Bureaucrat BC2("Samatchi", 100);
    BC1.signForm(ppForm);
    BC1.signForm(ppForm);
    BC1.executeForm(ppForm);
    BC1.executeForm(ppForm);
    BC2.executeForm(ppForm);
    BC2.signForm(ppForm);
    BC2.signForm(ppForm);
    BC2.executeForm(ppForm);
  }
  {
    RobotomyRequestForm rrForm("apah");
    Bureaucrat BC("atah", 2);
    BC.signForm(rrForm);
    BC.executeForm(rrForm);
  }
  return (0);
}