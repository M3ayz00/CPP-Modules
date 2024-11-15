/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:40:54 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/15 19:30:34 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : name("default")
{
    std::cout << "DiamondTrap " + name + " is ready for action\n";
    ClapTrap::name = name + "_clap_name";
    energyPoints = ScavTrap::energyPoints;
    hitPoints = FragTrap::hitPoints;
    attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap's EnergyPoints : " << std::to_string(energyPoints) << "\n";
}

DiamondTrap::DiamondTrap(const std::string& _name) : name(_name)
{
    std::cout << "DiamondTrap " + name + " is ready for action\n";
    ClapTrap::name = _name + "_clap_name";
    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;
}

DiamondTrap&   DiamondTrap::operator=(const DiamondTrap& F)
{
    if (this == &F) return (*this);
    name = F.name;
    std::cout << "DiamondTrap " + name + " has been cloned (using assignment)\n";
    ClapTrap::name = F.name + "_clap_name";
    hitPoints = F.FragTrap::hitPoints;
    energyPoints = F.ScavTrap::energyPoints;
    attackDamage = F.FragTrap::attackDamage;
    return (*this);
}

DiamondTrap::DiamondTrap(const DiamondTrap& F)
{
    std::cout << "DiamondTrap " + name + " has been cloned (using copy constructor)\n";
    *this = F;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " + name + " is shutting down...\n";
}

void    DiamondTrap::whoAmI(void) const
{
    std::cout << "My name is " + name + " and my Clap name is " + ClapTrap::name << std::endl;
}

void    DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}