/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:12:39 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/20 17:54:47 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap P("M3ayz00");
    P.attack("Khokho Bla3");
    P.attack("Khokho Bla3");
    P.takeDamage(40);
    P.attack("Khokho Bla3");
    P.takeDamage(33);
    P.beRepaired(50);
    P.attack("Khokho Bla3");
    std::cout << "CIRITCAL HIT : ";
    P.takeDamage(70);
    P.attack("Khokho Bla3");
    P.beRepaired(30);
    P.whoAmI();

}