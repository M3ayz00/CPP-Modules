/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:13:32 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/19 16:56:29 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
	private	:
		const static int	fractBits = 8;
		int					fixedPointNum;
	public	:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed &F);
		~Fixed();
		Fixed&			operator=(const Fixed&F);
		void			setRawBits(const int raw);
		int				getRawBits( void ) const;
		float			toFloat( void ) const;
		int				toInt( void ) const;
};

std::ostream&	operator<<(std::ostream &os, const Fixed &F);


#endif
