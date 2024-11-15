/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:19:35 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/15 19:30:03 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap " + name + " is ready for action\n";
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap's EnergyPoints : " << std::to_string(energyPoints) << "\n";

}

ScavTrap::ScavTrap(const std::string& _name) : ClapTrap(_name)
{
    std::cout << "ScavTrap " + name + " is ready for action\n";
    energyPoints = 50;
    attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& S) : ClapTrap(S)
{
    std::cout << "ScavTrap " + name + " has been cloned (using copy constructor)\n";
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " + name + " is shutting down...\n";
}

ScavTrap&   ScavTrap::operator=(const ScavTrap& S)
{
    if (this == &S) return *this;
    name = S.name;
    energyPoints = S.energyPoints;
    hitPoints = S.hitPoints;
    attackDamage = S.attackDamage;
    std::cout << "ScavTrap " + name + " has been cloned (using assignment)\n";
    return (*this);
}

void    ScavTrap::guardGate() const
{
    std::cout << "ScavTrap " + name + " is in Gate Keeper mode!\n";
}

void        ScavTrap::attack(const std::string& target)
{
    if (hitPoints > 0)
    {
        if (energyPoints > 0)
        {
            std::cout << "ScavTrap " + name + " attacks " + target + " causing ";
            std::cout << attackDamage;
            std::cout << " points of damage!\n";
            energyPoints--;
        }
        else
            std::cout << "ScavTrap " + name + " has no energy points left!\n";
    }
    else
        std::cout << "ScavTrap " + name + " is dead\n";
}