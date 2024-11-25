/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:52:22 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/25 16:14:42 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
  {
    Intern  someRandomIntern;
    AForm* form = someRandomIntern.makeForm("Some Other Form", "something");
    if (form)
    {
      Bureaucrat  Officer("Kevin", 149);
      Officer.signForm(*form);
      Officer.executeForm(*form);
      delete form;
    }
  }
  std::cout << std::endl;
  {
    Intern someRandomIntern;
    AForm* form = someRandomIntern.makeForm("presidential pardon", "Ted Bundy");
    if (form)
    {
      Bureaucrat executor("Maxwell", 5);
      executor.signForm(*form);
      executor.signForm(*form);
      executor.executeForm(*form);
      executor.executeForm(*form);
      delete form;
    }
  }
  std::cout << std::endl;
  {
    Intern someRandomIntern;
    AForm* form = someRandomIntern.makeForm("shrubbery creation", "home");
    if (form)
    {
      Bureaucrat executor("Sanchez", 110);
      executor.signForm(*form);
      executor.signForm(*form);
      executor.executeForm(*form);
      executor.executeForm(*form);
      delete form;
    }
  }
  return (0);
}