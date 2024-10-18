/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:59:19 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/18 14:23:00 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void	Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}

void	Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month.\n";
}

void	Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void	Harl::complain(std::string level)
{
	void		(Harl::*ptrFunc[4])() = {&Harl::debug, &Harl::warning, &Harl::info, &Harl::error};
	std::string	levels[4] = {"INFO", "DEBUG", "ERROR", "WARNING"};
	int			i;

	for (i = 0; i < 4; i++)
	{
		if (!level.compare(levels[i]))
		{
			(this->*ptrFunc[i])();
			break ;
		}
	}
	if (i == 4)
		std::cout << "there is no complaint of that level\n";
}
