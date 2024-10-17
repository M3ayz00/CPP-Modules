/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:16:30 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/17 16:01:35 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class	HumanB
{
	private	:
		std::string	name;
		Weapon		*weapon;

	public	:
		HumanB(const std::string &_name, Weapon &_weapon);
		HumanB(const std::string &_name);
		void	attack();
		void	setWeapon(Weapon &_weapon);
};

#endif
