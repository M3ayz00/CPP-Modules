/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:50:30 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/20 17:33:43 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "Default FragTrap is ready for action\n";
}

FragTrap::FragTrap(const std::string& _name) : ClapTrap(_name)
{
    std::cout << "FragTrap " + name + " is ready for action\n";
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
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
    if (this != &F)
    {
        ClapTrap::operator=(F);
        std::cout << "FragTrap " + name + " has been cloned\n";
    }
    return (*this);
}

void    FragTrap::highFivesGuys()
{
    std::cout << "FragTrap : \"Who wants a HIGH FIVE?! Oh yeah! Bring it in! 💥🖐️💥\"\n";
}