/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:04:22 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/17 13:54:15 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <cstring>

class Contact
{
	private:
		std::string LastName, NickName,PhoneNumber, DarkestSecret;

	public:
		std::string FirstName;
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickName() const;
		std::string	getPhoneNumber() const;
		std::string getDarkestSecret() const;

		void setFirstName(std::string fn);
		void setLastName(std::string fn);
		void setNickName(std::string fn);
		void setPhoneNumber(std::string fn);
		void setDarkestSecret(std::string fn);
};

#endif
