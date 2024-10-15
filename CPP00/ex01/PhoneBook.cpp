/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:45:12 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/14 18:24:35 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>


int	PhoneBook::validateName(std::string name)
{
	int	i;
	for (i = 0; i < name.length(); i++)
	{
		if (!isalpha(name[i]))
		{
			std::cerr << "Error : name can only contain alphabetic characters." << std::endl;
			return (0);
		}
	}
	if (i < 2)
	{
		std::cerr << "Error : Name must be at least 2 characters long." << std::endl;
		return (0);
	}
	return (1);
}

int	PhoneBook::validateNickName(std::string nickName)
{
	for (char c : nickName)
	{
		if (!isalnum(c))
		{
			std::cerr << "Error : nickname can only contain alphanumeric characters." << std::endl;
			return (0);
		}
	}
	return (1);
}

int	PhoneBook::validatePhoneNumber(std::string phoneNumber)
{
	int	i;
	for (i = 0; i < phoneNumber.length(); i++)
	{
		if (!isdigit(phoneNumber[i]))
		{
			std::cerr << "Error : phone number can only contain numeric characters." << std::endl;
			return (0);
		}
	}
	if (i < 4)
	{
		std::cerr << "Error : phone number must be at least 4 digits" << std::endl;
		return (0);
	}
	return (1);
}

void	PhoneBook::addContact()
{
	std::string	input;

	do
	{
		std::cout << "Enter first name : ";
		std::getline(std::cin, input);
	} while (input.empty() || !validateName(input));
	myContacts[i].setFirstName(input);
	do
	{
		std::cout << "Enter last name : ";
		std::getline(std::cin, input);
	} while (input.empty() || !validateName(input));
	myContacts[i].setLastName(input);
	do
	{
		std::cout << "Enter nickname : ";
		std::getline(std::cin, input);
	} while (input.empty() || !validateNickName(input));
	myContacts[i].setNickName(input);
	do
	{
		std::cout << "Enter phone number : ";
		std::getline(std::cin, input);
	} while (!validatePhoneNumber(input));
	myContacts[i].setPhoneNumber(input);
	do
	{
		std::cout << "Enter darkest secret : ";
		std::getline(std::cin, input);
	} while (input.empty());
	myContacts[i].setDarkestSecret(input);
	i++;
	if (i > 7)
		i = 0;
}

std::string	truncatingAndDotting(const std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

int	checkIndex(std::string index)
{
	if (index.length() == 1 && (index[0] >= '0' && index[0] <= '7'))
		return (atoi(index.c_str()));
	return (-1);
}

void	PhoneBook::displayContact()
{
	std::string	input;
	int			index;

	do {
		std::cout << "Enter contact's index: ";
		std::getline(std::cin, input);
		index = checkIndex(input);
		if (index == -1)
			std::cerr << "index must be numeric (0 <= index <= 7)" << std::endl;
	} while (index == -1);

	std::cout << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "nickname" << "|" << std::endl;

	std::cout << std::setw(10) << index << "|";
	std::cout << std::setw(10) << truncatingAndDotting(myContacts[index].getFirstName()) << "|";
	std::cout << std::setw(10) << truncatingAndDotting(myContacts[index].getLastName()) << "|";
	std::cout << std::setw(10) << truncatingAndDotting(myContacts[index].getNickName()) << std::endl;
}
