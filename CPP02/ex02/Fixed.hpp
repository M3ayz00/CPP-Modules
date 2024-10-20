/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:13:32 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/20 11:40:18 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

#define EPSILON(x) (float)(1 / pow(2, x))

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

		Fixed&			operator=(const Fixed &F);
		Fixed			operator/(const Fixed &F) const;
		Fixed			operator+(const Fixed &F) const;
		Fixed			operator-(const Fixed &F) const;
		Fixed			operator*(const Fixed &F) const;

		bool			operator==(const Fixed &F) const;
		bool			operator>=(const Fixed &F) const;
		bool			operator<=(const Fixed &F) const;
		bool			operator!=(const Fixed &F) const;
		bool			operator<(const Fixed &F) const;
		bool			operator>(const Fixed &F) const;

		Fixed			operator++(int);
		Fixed			operator--(int);
		Fixed&			operator++();
		Fixed&			operator--();

		void			setRawBits(const int raw);
		int				getRawBits( void ) const;

		float			toFloat( void ) const;
		int				toInt( void ) const;

		static Fixed&			min(Fixed& F1, Fixed& F2);
		static const Fixed&		min(const Fixed& F1, const Fixed& F2);
		static Fixed&			max(Fixed& F1, Fixed& F2);
		static const Fixed&		max(const Fixed& F1, const Fixed& F2);
};

std::ostream&	operator<<(std::ostream &os, const Fixed &F);


#endif
