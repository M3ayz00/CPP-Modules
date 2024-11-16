/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m3ayz00 <m3ayz00@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:50:30 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/16 00:22:50 by m3ayz00          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap " + name + " is ready for action\n";
    energyPoints = 100;
    attackDamage = 30;
}

FragTrap::FragTrap(const std::string& _name) : ClapTrap(_name)
{
    std::cout << "FragTrap " + name + " is ready for action\n";
    energyPoints = 100;
    attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& F) : ClapTrap(F)
{
    std::cout << "FragTrap " + name + " has been cloned (using copy constructor)\n";
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " + name + " is shutting down...\n";
}

FragTrap&   FragTrap::operator=(const FragTrap& F)
{
    if (this == &F) return (*this);
    name = F.name;
    energyPoints = F.energyPoints;
    hitPoints = F.hitPoints;
    attackDamage = F.attackDamage;
    std::cout << "FragTrap " + name + " has been cloned (using assignment)\n";
    return (*this);
}

void    FragTrap::highFivesGuys() const
{
    std::cout << "FragTrap : \"Who wants a HIGH FIVE?! Oh yeah! Bring it in! 💥🖐️💥\"\n";
}

void    FragTrap::guardGate() const
{
    std::cout << "FragTrap " + name + " is in Gate Keeper mode!\n";
}

void        FragTrap::attack(const std::string& target)
{
    if (hitPoints > 0)
    {
        if (energyPoints > 0)
        {
            std::cout << "FragTrap " + name + " attacks " + target + " causing ";
            std::cout << attackDamage;
            std::cout << " points of damage!\n";
            energyPoints--;
        }
        else
            std::cout << "FragTrap " + name + " has no energy points left!\n";
    }
    else
        std::cout << "FragTrap " + name + " is dead\n";
}

unsigned int    FragTrap::getHp(void) const
{
    return (100);
}

unsigned int    FragTrap::getAd(void) const
{
    return (30);
}

