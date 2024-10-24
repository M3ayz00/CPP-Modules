/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:12:39 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/20 17:23:26 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ScavTrap P("M3ayz00");
    ScavTrap L;
    ScavTrap M(P);
    M.attack("pixou");
    P.attack("Khokho Bla3");
    P.attack("Khokho Bla3");
    P.takeDamage(40);
    P.attack("Khokho Bla3");
    P.takeDamage(33);
    P.beRepaired(50);
    P.attack("Khokho Bla3");
    P.takeDamage(70);
    P.guardGate();
    P.attack("Khokho Bla3");
    P.beRepaired(30);

}