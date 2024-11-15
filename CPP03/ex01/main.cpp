/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:12:39 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/15 15:29:06 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    // {
    //     ClapTrap CT1;
    //     ClapTrap CT2("CONSTANTINE"); 
    //     CT1 = CT2; 
    //     ClapTrap CT3(CT1); 
    //     CT1.attack("an ennemy"); 
    //     CT2.takeDamage(2); 
    //     CT3.beRepaired(3);
    // }
    // {
    //     ScavTrap ST1;
    //     ScavTrap ST2("PIXOU"); 
    //     ST1 = ST2; 
    //     ScavTrap ST3(ST2); 
    //     ClapTrap CT4(ST3); 
    //     CT4.takeDamage(99);
    //     CT4.beRepaired(-1);
    // }
    {
        ScavTrap ST = ScavTrap("M3ayz00");
        ClapTrap CT = ScavTrap("lalala");
        ST.guardGate();
        CT.attack("someone");
        ST.takeDamage(10);
    }
}