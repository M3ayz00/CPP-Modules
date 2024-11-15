/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:59:25 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/05 18:05:56 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		Harl	harlito;
		harlito.complain(av[1]);
		return (0);
	}
	std::cout << "Usgae: ./Harl [INFO/DEBUG/WARNING/ERROR]\n";
	return (1);
}
