/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:40:35 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/20 13:14:12 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& _name) : name(_name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " + name + " is created\n";
}

ClapTrap::ClapTrap() : name(""), hitPoints(10),  energyPoints(10),attackDamage(0)
{
    std::cout << "Default ClapTrap is created\n";
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " + name + " is destroyed\n";
}

ClapTrap::ClapTrap(const ClapTrap& C)
{
    std::cout << "ClapTrap " + C.name + " has been cloned\n";
    *this = C;
}

ClapTrap&   ClapTrap::operator=(const ClapTrap& C)
{
    std::cout << "ClapTrap " + C.name + " has been cloned\n";
    if (this != &C)
    {
        name = C.name;
        attackDamage = C.attackDamage;
        hitPoints = C.hitPoints;
        energyPoints = C.energyPoints;
    }
    return (*this);
}

void        ClapTrap::attack(const std::string& target)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        std::cout << "ClapTrap " + name + " attacks " + target + " causing ";
        std::cout << attackDamage;
        std::cout << " points of damage!\n";
        energyPoints--;
    }
}

void        ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints > 0)
    {
        std::cout << "ClapTrap " + name + " has been attacked causing ";
        std::cout << amount;
        std::cout << " points of damage\n";
        hitPoints -= amount;
    }
}

void        ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints > 0 && hitPoints > 0)
    {        
        std::cout << "ClapTrap " + name + " has repaired itself gaining ";
        std::cout << amount;
        std::cout << " points of health\n";
        energyPoints--;
        hitPoints += amount;
    }
}
