/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:04:22 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/28 12:39:31 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <cstring>

class Contact
{
	private:
		std::string FirstName, LastName, NickName,PhoneNumber, DarkestSecret;

	public:
		Contact();
		
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickName() const;
		std::string	getPhoneNumber() const;
		std::string getDarkestSecret() const;

		void setFirstName(const std::string& fn);
		void setLastName(const std::string& ln);
		void setNickName(const std::string& nn);
		void setPhoneNumber(const std::string& pn);
		void setDarkestSecret(const std::string& ds);
};

#endif
