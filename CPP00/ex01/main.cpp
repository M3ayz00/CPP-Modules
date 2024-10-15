/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 18:49:47 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/14 15:50:36 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook	phoneBook;
	std::string	prompt;

	do
	{
		std::cout << "Enter prompt (ADD/SEARCH/EXIT) : ";
		std::getline(std::cin, prompt);
		if (prompt == "ADD")
			phoneBook.addContact();
		else if (prompt == "SEARCH")
			phoneBook.displayContact();
	} while (prompt != "EXIT");
	return (0);
}
