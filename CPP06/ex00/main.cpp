/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:04:30 by msaadidi          #+#    #+#             */
/*   Updated: 2024/12/02 17:18:45 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalarconverter.hpp"

int main(int ac, char **av)
{
  if (ac != 2)
  {
    std::cerr << "Usage : ./convert [parameter]\n";
    return (1);
  }
  ScalarConverter::convert(std::string(av[1]));
  return 0;
}
