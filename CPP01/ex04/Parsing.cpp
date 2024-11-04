/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:27:45 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/04 16:36:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fileHandling.hpp"

int	checkArguments(char **av)
{
	if (std::string(av[1]).empty()
			|| std::string(av[2]).empty()
			|| std::string(av[3]).empty())
	{
		std::cout << "Usage : ./Replace [filename] [to be replaced] [to replace].\n";
		return (0);
	}
	return (1);
}
