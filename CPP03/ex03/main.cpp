/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:12:39 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/15 18:52:03 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    {
        DiamondTrap DT1("idk");
        DiamondTrap DT2("pixou");
        DT1.whoAmI();
        DT2.whoAmI();
        DT1.attack("sfex");
        DT1.takeDamage(-1);
        DT2.ScavTrap::guardGate();
        DT1.beRepaired(-1);
    }
}