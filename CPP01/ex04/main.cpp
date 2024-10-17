/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:02:59 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/17 17:09:48 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fileHandling.hpp"

int main(int ac, char **av)
{
	if (ac == 4)
	{
		if (checkArguments(av))
		{
			std::ifstream	inFile(av[1]);
			if (!checkFile(inFile))
				return (1);
			std::ofstream	outFile(av[1] + ".replace", std::ios::out | std::ios::trunc);
			if (!checkFile(outFile))
				return (1);
			
		}
	}
	else
	{
		std::cout << "Usage : ./appah [filename] [to be replaced] [to replace].\n";
		return (1);
	}
	return (0);
}
