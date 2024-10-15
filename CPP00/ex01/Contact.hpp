/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:04:22 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/15 17:18:19 by msaadidi         ###   ########.fr       */
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
		int			index;

	public:
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickName() const;

		void setFirstName(std::string &fn);
		void setLastName(std::string &fn);
		void setNickName(std::string &fn);
		void setPhoneNumber(std::string &fn);
		void setDarkestSecret(std::string &fn);
};

#endif
