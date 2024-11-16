/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m3ayz00 <m3ayz00@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:12:39 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/16 01:15:00 by m3ayz00          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    {
        DiamondTrap DT1("idk"); 
        DiamondTrap DT2("pixou");
        DiamondTrap DT3 = DiamondTrap("lala");
        DT3.FragTrap::guardGate();
        DT1.whoAmI();
        DT2.whoAmI();
        DT1.attack("sfex"); 
        DT1.takeDamage(-1);
        DT2.ScavTrap::guardGate();
        DT1.beRepaired(-1);
        DT3.whoAmI();
    }
    {
        DiamondTrap DT;
        DT.whoAmI();
    }
}