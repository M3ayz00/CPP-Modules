/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:06:19 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/16 13:51:59 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::getFirstName() const
{
	return (FirstName);
}

std::string Contact::getLastName() const
{
	return (LastName);
}

std::string Contact::getNickName() const
{
	return (NickName);
}

std::string	Contact::getPhoneNumber() const
{
	return (PhoneNumber);
}

std::string Contact::getDarkestSecret() const
{
	return (DarkestSecret);
}

void	Contact::setFirstName(std::string fn)
{
	FirstName = fn;
}

void	Contact::setLastName(std::string ln)
{
	LastName = ln;
}

void	Contact::setNickName(std::string nn)
{
	NickName = nn;
}

void	Contact::setPhoneNumber(std::string pn)
{
	PhoneNumber = pn;
}

void	Contact::setDarkestSecret(std::string ds)
{
	DarkestSecret = ds;
}
