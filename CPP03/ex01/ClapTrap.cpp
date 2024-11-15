/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:40:35 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/15 16:29:59 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& _name) : name(_name), hitPoints(100), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " + name + " is ready for action\n";
}

ClapTrap::ClapTrap() : name("default"), hitPoints(100), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " + name + " is ready for action\n";
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " + name + " is shutting down...\n";
}

ClapTrap::ClapTrap(const ClapTrap& C)
{
    std::cout << "ClapTrap " + C.name + " has been cloned (using copy constructor)\n";
    *this = C;
}

ClapTrap&   ClapTrap::operator=(const ClapTrap& C)
{
    if (this == &C) return *this;
    std::cout << "ClapTrap " + C.name + " has been cloned (using assignment)\n";
    name = C.name;
    attackDamage = C.attackDamage;
    hitPoints = C.hitPoints;
    energyPoints = C.energyPoints;
    return (*this);
}

void        ClapTrap::attack(const std::string& target)
{
    if (hitPoints > 0)
    {
        if (energyPoints > 0)
        {
            std::cout << "ClapTrap " + name + " attacks " + target + " causing ";
            std::cout << attackDamage;
            std::cout << " points of damage!\n";
            energyPoints--;
        }
        else
            std::cout << "ClapTrap " + name + " has no energy points left!\n";
    }
    else
        std::cout << "ClapTrap " + name + " is dead\n";
}

void        ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints > 0)
    {
        std::cout << "ClapTrap " + name + " has been attacked receiving ";
        if (amount > hitPoints)
        {
            std::cout << hitPoints;
            hitPoints = 0;
        }
        else
        {
            std::cout << amount;
            hitPoints -= amount;
        }
        std::cout << " points of damage\n";
    }
    else
        std::cout << "ClapTrap " + name + " is dead\n";
}

void        ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints == 100)
    {   
        std::cout << "ClapTrap " + name + "'s HP (hit points) is full\n";
        return ;
    }
    if (hitPoints > 0)
    {
        if (energyPoints > 0)
        {        
            std::cout << "ClapTrap " + name + " has repaired itself gaining ";
            if (amount > 100 - hitPoints)
            {
                std::cout << 100 - hitPoints;   
                hitPoints = 100;
            }
            else
            {
                std::cout << amount;
                hitPoints += amount;
            }
            std::cout << " points of health\n";
            energyPoints--;
        }
        else
            std::cout << "ClapTrap " + name + " has no energy points left!\n";
    }
    else
        std::cout << "ClapTrap " + name + " is dead\n";
}
