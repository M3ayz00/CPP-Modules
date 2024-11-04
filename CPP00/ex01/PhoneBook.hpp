/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:33:57 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/01 10:00:26 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>

#define LOG(a,b,c,d) std::cout << std::setw(10) << a << "|" << std::setw(10) << b << "|" << std::setw(10) << c << "|" << std::setw(10) << d << "|\n";
#define DISPLAY(a,b,c,d,e) std::cout << "First name : " << a << "\nLast name : " << b << "\nNickname : " << c << "\nPhone number : " << d << "\nDarkest secret : " << e << std::endl;

class PhoneBook
{
	private:
		Contact				myContacts[8];
		static int			i;
	public:
		void		addContact();
		int			checkIndex(const std::string &index);
		int			displayContacts();
		void		displayContact();
		int			showPrompt(const std::string& msg, int(*validate)(const std::string&), std::string& input);

};

int			validateName(const std::string &fn);
int			validateNickName(const std::string &fn);
int			validatePhoneNumber(const std::string &fn);

#endif
