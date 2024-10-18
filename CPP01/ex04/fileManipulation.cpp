/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileManipulation.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:26:19 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/18 12:48:06 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fileHandling.hpp"

int	checkInFile(const std::ifstream &inFile)
{
	if (!inFile)
	{
		std::cout << "Error : cannot open file.\n";
		return (0);
	}
	return (1);
}

int	checkOutFile(const std::ofstream &outFile)
{
	if (!outFile)
	{
		std::cout << "Error : cannot create file.\n";
		return (0);
	}
	return (1);
}

void	actualReplacing(std::string &line, const std::string &s1, const std::string &s2)
{
	size_t pos = line.find(s1);
	while (pos != std::string::npos)
	{
		line.erase(pos, s1.length());
		line.insert(pos, s2);
		pos = line.find(s1, pos + s2.length());
	}
}

void	replacing(std::ifstream& inFile, std::ofstream& outFile,
	const std::string &s1, const std::string& s2)
{
	std::string	line;
	while (std::getline(inFile, line))
	{
		if (line.find(s1) != std::string::npos)
			actualReplacing(line, s1, s2);
		outFile << line << '\n';
	}
	inFile.close();
	outFile.close();
}

