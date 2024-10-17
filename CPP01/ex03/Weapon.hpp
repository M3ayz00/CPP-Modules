/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:16:03 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/17 14:40:27 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class	Weapon
{
	private	:
		std::string	type;

	public	:
		Weapon();
		Weapon(const std::string &_type);
		~Weapon();
		const std::string&	getType() const;
		void				setType(const std::string &_type);
};

#endif
