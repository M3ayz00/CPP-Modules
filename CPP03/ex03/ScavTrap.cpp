/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:19:35 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/20 17:32:24 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "Default ScavTrap is ready for action\n";
}

ScavTrap::ScavTrap(const std::string& _name) : ClapTrap(_name)
{
    std::cout << "ScavTrap " + name + " is ready for action\n";
    hitPoints = 100;
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
    if (this != &S)
    {
        ClapTrap::operator=(S);
        std::cout << "ScavTrap " + name + " has been cloned\n";
    }
    return (*this);
}

void    ScavTrap::guardGate()
{
    std::cout << "ScavTrap " + name + " is in Gate Keeper mode!\n";
}