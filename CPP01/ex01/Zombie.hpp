/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:44:17 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/04 15:49:34 by codespace        ###   ########.fr       */
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
		Zombie();
		Zombie(const std::string& n);
		~Zombie();

		void	setName(const std::string& n);
		void	announce(void);
};

Zombie* zombieHorde(int N, const std::string& name);

#endif
