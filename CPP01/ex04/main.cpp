/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:02:59 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/18 12:59:06 by msaadidi         ###   ########.fr       */
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
			if (!checkInFile(inFile))
				return (1);
			std::ofstream	outFile(std::string(av[1]) + ".replace", std::ios::out | std::ios::trunc);
			if (!checkOutFile(outFile))
				return (1);
			replacing(inFile, outFile, std::string(av[2]), std::string(av[3]));
			return (0);
		}
		return (1);
	}
	std::cout << "Usage : ./Replace [filename] [to be replaced] [to replace].\n";
	return (1);
}
