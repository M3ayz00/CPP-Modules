/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:20:29 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/18 17:41:32 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointNum(0)
{
	std::cout << "Default Contructor called\n";
}
Fixed& Fixed::operator=(const Fixed &F)
{
	if (this != &F)
	{
		std::cout << "Copy assignment operator called\n";
		fixedPointNum = F.getRawBits() ;
	}
	return *this;
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
