/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:12:39 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/15 15:45:45 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    {
        ClapTrap CT("CT");
        ScavTrap ST("ST"); 
        FragTrap FT("FT"); 
        ClapTrap CT1;
        CT1 = ScavTrap(ST);
        ClapTrap CT2(FT);
        CT.attack("ennemy_1");
        ST.attack("ennemy_2");
        FT.attack("ennemy_3");
        CT1.attack("ennemy_4");
        CT2.attack("ennemy_5");
    }
    {
        FragTrap FT = FragTrap("Pixou");
        ClapTrap CT = FragTrap(FT);
        FT.attack("ennemy_1");
        CT.attack("ennemy_2");
        FT.highFivesGuys();
        FT.takeDamage(-1);
        CT.beRepaired(-1);
    }
    {
        ClapTrap CT;
        CT = FragTrap("pixou"); 
        CT.attack("aili");
    }
    {
        ClapTrap CT(FragTrap("pixou"));
        CT.attack("aili");
    }
    {
        ClapTrap CT = FragTrap("pixou");
        CT.attack("aili");
    }
}