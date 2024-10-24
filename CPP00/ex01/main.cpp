/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 18:49:47 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/16 13:05:15 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(int ac, char **av)
{
	(void)av;
	PhoneBook	phoneBook;
	std::string	prompt;

	if (ac == 1)
	{
		do
		{
			if (std::cin.fail())
				break ;
			std::cout << "Enter prompt (ADD/SEARCH/EXIT) : ";
			if (!std::getline(std::cin, prompt))
				break ;
			if (prompt == "ADD")
				phoneBook.addContact();
			else if (prompt == "SEARCH")
				phoneBook.displayContact();
		} while (prompt != "EXIT");
		return (0);
	}
	return (1);
}
