/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:45:52 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/04 15:46:55 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(const std::string& n) : name(n) {}

Zombie::Zombie() : name("UNNAMED") {}

Zombie::~Zombie()
{
	std::cout << name << std::endl;
}

void	Zombie::setName(const std::string& _name)
{
	name = _name;
}
void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

