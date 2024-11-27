/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:52:22 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/27 15:18:47 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
  {
    try
    {
      Form simpleForm;
      Bureaucrat BC("M3ayz00", 130);
      std::cout << simpleForm;
      BC.signForm(simpleForm);
      std::cout << simpleForm;
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }
  }
  std::cout << std::endl;
  {
    try
    {
      Form taxForm("Tax Form", 50, 30);
      std::cout << taxForm;
      Bureaucrat BC1("Ben", 10);
      Bureaucrat BC2("Roger", 100);
      BC2.signForm(taxForm);
      std::cout << taxForm;
      BC1.signForm(taxForm);
      std::cout << taxForm;
      BC1.signForm(taxForm);
      BC2.signForm(taxForm);
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }
  }
  {
    try
    {
      Form form = Form("pixou", 170, 140);
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what();
    }
  }
  return (0);
}