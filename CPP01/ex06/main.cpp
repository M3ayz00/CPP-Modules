/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:32:57 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/04 18:20:05 by msaadidi         ###   ########.fr       */
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
	std::cout << "Usage: ./harlFilter [DEBUG/INFO/WARNING/ERROR]\n";
	return (1);
}
