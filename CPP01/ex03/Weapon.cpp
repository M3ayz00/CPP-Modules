/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:17:39 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/17 15:58:05 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(){}

Weapon::Weapon(const std::string &_type) : type(_type) {}

Weapon::~Weapon() {}

const std::string&	Weapon::getType() const
{
	return (type);
}

void	Weapon::setType(const std::string &_type)
{
	type = _type;
}


