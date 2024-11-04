/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:17:32 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/04 16:36:05 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string &_name, Weapon &_weapon) : name (_name), weapon(&_weapon){}

HumanB::HumanB(const std::string &_name) : name(_name), weapon(NULL){}

void	HumanB::attack()
{
	if (!weapon)
		std::cout << name << " has no weapon\n";
	else
	{
		std::cout << name << " attacks with their " << weapon->getType() << "\n";
	}
}

void	HumanB::setWeapon(Weapon &_weapon)
{
	weapon = &_weapon;
}
