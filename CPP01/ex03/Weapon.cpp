/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:17:39 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/04 16:35:24 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() : type("hands") {}

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


