/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:40:54 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/20 18:01:20 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap()
{
    std::cout << "Default DiamondTrap is ready for action\n";
}

DiamondTrap::DiamondTrap(const std::string& _name) : ClapTrap(_name + "_clap_name")
{
    DiamondTrap::name = _name;
    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& F) : ClapTrap(F)
{
    std::cout << "DiamondTrap " + DiamondTrap::name + " has been cloned (using copy constructor)\n";
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " + DiamondTrap::name + " is shutting down...\n";
}


DiamondTrap&   DiamondTrap::operator=(const DiamondTrap& F)
{
    if (this != &F)
    {
        ClapTrap::operator=(F);
        std::cout << "DiamondTrap " + DiamondTrap::name + " hasb een cloned (using assignment)\n";
    }
    return (*this);
}

void    DiamondTrap::whoAmI()
{
    std::cout << "My name is " + name + " and my Clap name is " + ClapTrap::name << std::endl;
}