/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:45:12 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/16 14:44:13 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <array>



int	PhoneBook::validateName(const std::string &name)
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

int	PhoneBook::validateNickName(const std::string &nickName)
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

int	PhoneBook::validatePhoneNumber(const std::string &phoneNumber)
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
		if (std::cin.fail())
			break ;
		std::cout << "Enter first name : ";
		if (!std::getline(std::cin, input))
			break ;
	} while (input.empty() || !validateName(input));
	myContacts[i].setFirstName(input);
	do
	{
		if (std::cin.fail())
			break ;
		std::cout << "Enter last name : ";
		if (!std::getline(std::cin, input))
			break ;
	} while (input.empty() || !validateName(input));
	myContacts[i].setLastName(input);
	do
	{
		if (std::cin.fail())
			break ;
		std::cout << "Enter nickname : ";
		if (!std::getline(std::cin, input))
			break ;
	} while (input.empty() || !validateNickName(input));
	myContacts[i].setNickName(input);
	do
	{
		if (std::cin.fail())
			break ;
		std::cout << "Enter phone number : ";
		if (!std::getline(std::cin, input))
			break ;
	} while (!validatePhoneNumber(input));
	myContacts[i].setPhoneNumber(input);
	do
	{
		if (std::cin.fail())
			break ;
		std::cout << "Enter darkest secret : ";
		if (!std::getline(std::cin, input))
			break ;
	} while (input.empty());
	myContacts[i].setDarkestSecret(input);
	i++;
	if (i > 7)
		i = 0;
}

std::string	truncatingAndDotting(const std::string &str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

int	PhoneBook::checkIndex(const std::string &index)
{
	int	rIndex = -1;
	if (index.length() == 1 && (index[0] >= '0' && index[0] <= '7'))
		rIndex = atoi(index.c_str());
	if (rIndex == -1)
		std::cerr << "Index must be numeric (0 <= index <= 7)\n";
	else
	{
		if (myContacts[rIndex].FirstName.empty())
		{
			std::cerr << "Contact not found at index : " << rIndex << "\n";
			rIndex = -1;
		}
	}
	return (rIndex);
}

int	PhoneBook::displayContacts()
{
	if (myContacts[0].FirstName.empty())
	{
		std::cerr << "No contacts to be shown.\n";
		return (0);
	}
	LOG("index", "first name", "last name", "nickname");
	for (int n = 0; n < 8; n++)
	{
		if (myContacts[n].FirstName.empty())
			break ;
		LOG(n, truncatingAndDotting(myContacts[n].getFirstName()),
			truncatingAndDotting(myContacts[n].getLastName()),
			truncatingAndDotting(myContacts[n].getNickName()));
	}
	return (1);
}

void	PhoneBook::displayContact()
{
	std::string	input;
	int			index;

	if (!displayContacts())
		return ;
	do {
		if (std::cin.fail())
			return ;
		std::cout << "Enter contact's index: ";
		if (!std::getline(std::cin, input))
			return ; ;
		index = checkIndex(input);
	} while (index == -1);

	if (!std::cin.fail())
	{
		DISPLAY(myContacts[index].getFirstName(),
			myContacts[index].getLastName(),
			myContacts[index].getNickName(),
			myContacts[index].getPhoneNumber(),
			myContacts[index].getDarkestSecret());
	}
}
