/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:33:57 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/17 13:53:54 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <cctype>
#include <cstdlib>

#define LOG(a,b,c,d) std::cout << std::setw(10) << a << "|" << std::setw(10) << b << "|" << std::setw(10) << c << "|" << std::setw(10) << d << "|\n";
#define DISPLAY(a,b,c,d,e) std::cout << "First name : " << a << "\nLast name : " << b << "\nNickname : " << c << "\nPhone number : " << d << "\nDarkest secret : " << e << std::endl;

class PhoneBook
{
	private:
		Contact				myContacts[8];
		static int			i;
	public:
		void		addContact();
		int			validateName(const std::string &fn);
		int			validateNickName(const std::string &fn);
		int			validatePhoneNumber(const std::string &fn);
		int			checkIndex(const std::string &index);
		int			displayContacts();
		void		displayContact();
};


#endif
