/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:13:32 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/19 15:18:19 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class	Fixed
{
	private	:
		int	fixedPointNum;
		const static int fractBits = 8;
	public	:
		Fixed();
		Fixed(const Fixed &F);
		~Fixed();
		Fixed& operator=(const Fixed&F);
		void	setRawBits(const int raw);
		int		getRawBits( void ) const;
};

#endif
