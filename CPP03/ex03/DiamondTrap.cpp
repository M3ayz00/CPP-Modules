/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m3ayz00 <m3ayz00@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:40:54 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/16 00:42:39 by m3ayz00          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
    name = "default";
    ClapTrap::name = name + "_clap_name";
    energyPoints = ScavTrap::getEp();
    hitPoints = FragTrap::getHp();
    attackDamage = FragTrap::getAd();
    std::cout << "DiamondTrap " + name + " is ready for action\n";
}

DiamondTrap::DiamondTrap(const std::string& _name) : name(_name), ClapTrap(_name), FragTrap(_name), ScavTrap(_name)
{
    std::cout << "DiamondTrap " + name + " is ready for action\n";
    ClapTrap::name = _name + "_clap_name";
    hitPoints = FragTrap::getHp();
    energyPoints = ScavTrap::getEp();
    attackDamage = FragTrap::getAd();
}

DiamondTrap&   DiamondTrap::operator=(const DiamondTrap& D)
{
    if (this == &D) return (*this);
    name = D.name;
    std::cout << "DiamondTrap " + name + " has been cloned (using assignment)\n";
    ClapTrap::name = D.name + "_clap_name";
    hitPoints = D.FragTrap::getHp();
    energyPoints = D.ScavTrap::getEp();
    attackDamage = D.FragTrap::getAd();
    return (*this);
}

DiamondTrap::DiamondTrap(const DiamondTrap& D) : ClapTrap(D), ScavTrap(D), FragTrap(D)
{
    name = D.name;
    ClapTrap::name = D.name + "_clap_name";
    hitPoints = D.hitPoints;
    energyPoints = D.energyPoints;
    attackDamage = D.attackDamage;
    std::cout << "DiamondTrap " + name + " has been cloned (using copy constructor)\n";
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