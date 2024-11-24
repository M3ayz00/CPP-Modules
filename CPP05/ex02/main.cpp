/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:52:22 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/24 19:24:10 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
  {
    AForm simpleForm;
    Bureaucrat BC("M3ayz00", 130);
    BC.signForm(simpleForm);
  }
  {
    AForm taxForm("Tax Form", 50, 30);
    Bureaucrat BC1("Pixou", 10);
    Bureaucrat BC2("Samatchi", 100);
    BC1.signForm(taxForm);
    BC1.signForm(taxForm);
    BC2.signForm(taxForm);
    BC2.signForm(taxForm);
  }
  return (0);
}