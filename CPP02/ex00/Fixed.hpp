/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m3ayz00 <m3ayz00@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:13:32 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/10 14:42:42 by m3ayz00          ###   ########.fr       */
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
