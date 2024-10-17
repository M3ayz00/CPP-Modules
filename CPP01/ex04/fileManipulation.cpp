/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileManipulation.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:26:19 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/17 17:13:13 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fileHandling.hpp"

int	checkFile(const std::ifstream &File)
{
	if (!File)
	{
		std::cout << "Error : cannot open file.\n";
		return (0);
	}
	return (1);
}

void	replacing(std::ifstream& inFile, std::ofstream& outFile,
	const std::string &s1, const std::string& s2)
{
	std::string	line;
	while (std::getline(inFile, line))
	{
		
	}
	inFile.close();
	outFile.close();
}

