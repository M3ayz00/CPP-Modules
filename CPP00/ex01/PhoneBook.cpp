/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:45:12 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/01 10:02:03 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	PhoneBook::i = 0;

int	validateName(const std::string &name)
{
	size_t	n;
	for (n = 0; n < name.length(); n++)
	{
		if (!isalpha(name[n]))
		{
			std::cerr << "Error : Name can only contain alphabetic characters." << std::endl;
			return (0);
		}
	}
	if (n < 2)
	{
		std::cerr << "Error : Name must be at least 2 characters long." << std::endl;
		return (0);
	}
	return (1);
}

int	validateNickName(const std::string &nickName)
{
	for (size_t n = 0; n < nickName.length(); n++)
	{
		if (!isalnum(nickName[n]))
		{
			std::cerr << "Error : This field can only contain alphanumeric characters." << std::endl;
			return (0);
		}
	}
	return (1);
}

int	validatePhoneNumber(const std::string &phoneNumber)
{
	size_t	n;
	for (n = 0; n < phoneNumber.length(); n++)
	{
		if (!isdigit(phoneNumber[n]))
		{
			std::cerr << "Error : Phone number can only contain numeric characters." << std::endl;
			return (0);
		}
	}
	if (n < 4)
	{
		std::cerr << "Error : Phone number must be at least 4 digits" << std::endl;
		return (0);
	}
	return (1);
}

int	PhoneBook::showPrompt(const std::string& msg, int(*validate)(const std::string&), std::string& input)
{
	do
	{
		std::cout << msg;
		if (!std::getline(std::cin, input))
			return (0);
	} while (input.empty() || !validate(input));
	return (1);
}

void	PhoneBook::addContact()
{
	std::string	input;

	if (!showPrompt("Enter first name : ", validateName, input))
		return ;
	myContacts[i].setFirstName(input);
	if (!showPrompt("Enter last name : ", validateName, input))
		return ;
	myContacts[i].setLastName(input);
	if (!showPrompt("Enter nickname : ", validateNickName, input))
		return ;
	myContacts[i].setNickName(input);
	if (!showPrompt("Enter phone number : ", validatePhoneNumber, input))
		return ;
	myContacts[i].setPhoneNumber(input);
	if (!showPrompt("Enter darkest secret : ", validateNickName, input))
		return ;
	myContacts[i].setDarkestSecret(input);
	i++;
	if (i > 7)
		i = 0;
}

std::string	truncAndDot(const std::string &str)
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
		if (myContacts[rIndex].getFirstName().empty())
		{
			std::cerr << "Contact not found at index : " << rIndex << "\n";
			rIndex = -1;
		}
	}
	return (rIndex);
}

int	PhoneBook::displayContacts()
{
	if (myContacts[0].getFirstName().empty())
	{
		std::cerr << "No contacts to be shown.\n";
		return (0);
	}
	LOG("index", "first name", "last name", "nickname");
	for (int n = 0; (n < 8 && !(myContacts[n].getFirstName().empty())); n++)
		LOG(n, truncAndDot(myContacts[n].getFirstName()),
			truncAndDot(myContacts[n].getLastName()),
			truncAndDot(myContacts[n].getNickName()));
	return (1);
}

void	PhoneBook::displayContact()
{
	std::string	input;
	int			index;

	if (!displayContacts())
		return ;
	do {
		std::cout << "Enter contact's index: ";
		if (!std::getline(std::cin, input))
			return ;
		index = checkIndex(input);
	} while (index == -1);
	DISPLAY(myContacts[index].getFirstName(),
		myContacts[index].getLastName(),
		myContacts[index].getNickName(),
		myContacts[index].getPhoneNumber(),
		myContacts[index].getDarkestSecret());

}
