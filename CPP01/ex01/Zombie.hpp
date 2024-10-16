/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:44:17 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/16 16:02:11 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

class	Zombie
{
	private	:
		std::string	name;
	public	:
		Zombie() {};
		Zombie(std::string n) : name(n) {};
		~Zombie() { std::cout << name << std::endl; };
		void	setName(std::string n) { name = n;};
		void	announce(void);
};

Zombie* zombieHorde( int N, std::string name );

#endif
