/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:16:49 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/17 16:01:30 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class	HumanA
{
	private	:
		std::string	name;
		Weapon		*weapon;

	public	:
		HumanA(const std::string &_name, Weapon &_weapon);
		void	attack();
		void	setWeapon(Weapon &_weapon);
};

#endif
