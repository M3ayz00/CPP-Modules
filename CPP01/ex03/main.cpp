/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:18:06 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/04 16:35:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	{
		Weapon firegun = Weapon();
		HumanB mike("Mike");
		mike.attack();
		mike.setWeapon(firegun);
		firegun.setType("rifle");
		mike.attack();
	}
	{
		Weapon utensil = Weapon();
		HumanB jeff("Jeff", utensil);
		jeff.attack();
		utensil.setType("fork");
		jeff.attack();
	}
	return 0;
}
