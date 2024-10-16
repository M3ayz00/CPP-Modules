/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:01:32 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/17 13:47:11 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *zombies = zombieHorde(10, "a");
	for (int i = 0; i < 10; i++)
		zombies[i].announce();
	delete[] zombies;
}
