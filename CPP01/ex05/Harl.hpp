/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:59:22 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/18 13:01:17 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class	Harl
{
	private	:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );

	public	:
		void	complain(std::string level);

};

#endif
