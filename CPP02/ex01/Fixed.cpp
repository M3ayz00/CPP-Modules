/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:20:29 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/11 12:30:01 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointNum(0)
{
	std::cout << "Default Contructor called\n";
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called\n";
	fixedPointNum = num << fractBits;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called\n";
	fixedPointNum = roundf(num * (1 << fractBits));
}

Fixed& Fixed::operator=(const Fixed &F)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &F) return *this;
	fixedPointNum = F.fixedPointNum;
	return *this;
}

std::ostream&	operator<<(std::ostream &os, const Fixed &F)
{
	os << F.toFloat();
	return (os);
}

Fixed::Fixed(const Fixed &F)
{
	std::cout << "Copy constructor called\n";
	*this = F;
}


Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

void	Fixed::setRawBits(int const raw)
{
	fixedPointNum = raw;
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return (fixedPointNum);
}

float	Fixed::toFloat( void ) const
{
	return (fixedPointNum / static_cast<float>(1 << fractBits));
}

int		Fixed::toInt( void ) const
{
	return (roundf(fixedPointNum / static_cast<float>(1 << fractBits)));
}
