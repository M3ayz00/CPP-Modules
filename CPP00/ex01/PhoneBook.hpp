/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:33:57 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/14 15:55:17 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <cctype>
#include <cstdlib>

class PhoneBook
{
	private:
		Contact		myContacts[8];
		int	i = 0;
	public:
		void	addContact();
		int		validateName(std::string fn);
		int		validateNickName(std::string fn);
		int		validatePhoneNumber(std::string fn);
		void	displayContact();
};


#endif
