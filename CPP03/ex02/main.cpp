/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:12:39 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/20 17:37:10 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    FragTrap P("M3ayz00");
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
    P.highFivesGuys();

}