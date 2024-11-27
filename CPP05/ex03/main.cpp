/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:52:22 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/27 15:57:18 by msaadidi         ###   ########.fr       */
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
      std::cout << *form;
      Bureaucrat  Officer("Kevin", 149);
      Officer.signForm(*form);
      std::cout << *form;
      Officer.executeForm(*form);
      std::cout << *form;
      delete form;
    }
  }
  std::cout << std::endl;
  {
    Intern someRandomIntern;
    AForm* form = someRandomIntern.makeForm("presidential pardon", "Ted Bundy");
    if (form)
    {
      std::cout << *form;
      Bureaucrat executor("Maxwell", 5);
      executor.signForm(*form);
      std::cout << *form;
      executor.signForm(*form);
      executor.executeForm(*form);
      std::cout << *form;
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
      std::cout << *form;
      Bureaucrat executor("Sanchez", 110);
      executor.signForm(*form);
      std::cout << *form;
      executor.signForm(*form);
      executor.executeForm(*form);
      std::cout << *form;
      Bureaucrat beginner("Yoshi", 150);
      beginner.executeForm(*form);
      delete form;
    }
  }
  return (0);
}