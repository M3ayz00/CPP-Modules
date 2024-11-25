/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:52:22 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/25 16:40:44 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
  {
    Form simpleForm;
    Bureaucrat BC("M3ayz00", 130);
    BC.signForm(simpleForm);
  }
  std::cout << std::endl;
  {
    Form taxForm("Tax Form", 50, 30);
    Bureaucrat BC1("Ben", 10);
    Bureaucrat BC2("Roger", 100);
    BC2.signForm(taxForm);
    BC1.signForm(taxForm);
    BC1.signForm(taxForm);
    BC2.signForm(taxForm);
  }
  return (0);
}