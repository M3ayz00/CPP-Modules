/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:17:20 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/17 16:01:49 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string &_name, Weapon &_weapon) : name (_name), weapon(&_weapon) {}

void	HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon->getType() << "\n";
}

void	HumanA::setWeapon(Weapon &_weapon)
{
	weapon = &_weapon;
}
