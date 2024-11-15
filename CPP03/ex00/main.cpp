/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:12:39 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/15 14:45:34 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap P("M3ayz00");
    ClapTrap T(P);
    P.attack("Khokho Bla3");
    T.takeDamage(9);
    P.beRepaired(-1);
    T.beRepaired(-1);
    T.takeDamage(-1);
    P.attack("Khokho Bla3");
    P.takeDamage(2);
    P.beRepaired(1);
    T.beRepaired(-1);
}