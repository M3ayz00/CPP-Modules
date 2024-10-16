/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:05:26 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/16 15:35:39 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>


class	Zombie
{
	private	:
		std::string	name;
	public	:
		Zombie(std::string n) : name(n) {};
		~Zombie() { std::cout << name << std::endl; };
		void	announce(void);
};


Zombie*	newZombie( std::string name );
void	randomChump( std::string name );


#endif
