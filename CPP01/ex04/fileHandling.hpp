/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileHandling.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:26:17 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/05 18:01:25 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEHANDLING_HPP
#define FILEHANDLING_HPP

#include <iostream>
#include <fstream>
#include <string>

int		checkArguments(char **av);
int		checkInFile(const std::ifstream &inFile);
int		checkOutFile(const std::ofstream &outFile);
void	replacing(std::ifstream& inFile, std::ofstream& outFile,
            const std::string &s1, const std::string& s2);
void	actualReplacing(std::string &line, const std::string &s1, const std::string &s2);


#endif
