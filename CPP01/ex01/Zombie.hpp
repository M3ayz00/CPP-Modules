/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:44:17 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/05 15:16:31 by msaadidi         ###   ########.fr       */
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
		Zombie();
		Zombie(const std::string& n);
		~Zombie();

		void	setName(const std::string& n);
		void	announce(void);
};

Zombie* zombieHorde(int N, const std::string& name);

#endif
