/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m3ayz00 <m3ayz00@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:20:29 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/10 23:18:03 by m3ayz00          ###   ########.fr       */
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
	if (this != &F)
	{
		std::cout << "Copy assignment operator called\n";
		fixedPointNum = F.fixedPointNum;
	}
	return *this;
}

std::ostream&	operator<<(std::ostream &os, const Fixed &F)
{
	os << F.toFloat();
	return (os);
}

Fixed	Fixed::operator/(const Fixed &F) const
{
	return (Fixed(toFloat() / F.toFloat()));
}

Fixed	Fixed::operator+(const Fixed &F) const
{
	return (Fixed(toFloat() + F.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &F) const
{
	return (Fixed(toFloat() - F.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &F) const
{
	return (Fixed(toFloat() * F.toFloat()));
}

bool	Fixed::operator==(const Fixed &F) const
{
	return (fixedPointNum == F.fixedPointNum);
}

bool	Fixed::operator>=(const Fixed &F) const
{
	return (fixedPointNum >= F.fixedPointNum);
}

bool	Fixed::operator<=(const Fixed &F) const
{
	return (fixedPointNum <= F.fixedPointNum);
}

bool	Fixed::operator!=(const Fixed &F) const
{
	return (fixedPointNum != F.fixedPointNum);
}

bool	Fixed::operator<(const Fixed &F) const
{
	return (fixedPointNum < F.fixedPointNum);
}

bool	Fixed::operator>(const Fixed &F) const
{
	return (fixedPointNum > F.fixedPointNum);
}

Fixed&	Fixed::operator++()
{
	fixedPointNum++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;
	fixedPointNum++;
	return (tmp);
}

Fixed&	Fixed::operator--()
{
	fixedPointNum--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;
	fixedPointNum--;
	return (tmp);
}

Fixed::Fixed(const Fixed &F) : fixedPointNum(F.fixedPointNum)
{
	std::cout << "Copy constructor called\n";
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

Fixed&		Fixed::min(Fixed& F1, Fixed& F2)
{
	return (F1 < F2 ? F1 : F2);
}

const Fixed&		Fixed::min(const Fixed& F1, const Fixed& F2)
{
	return (F1 < F2 ? F1 : F2);
}

Fixed&		Fixed::max(Fixed& F1, Fixed& F2)
{
	return (F1 > F2 ? F1 : F2);
}

const Fixed&		Fixed::max(const Fixed& F1, const Fixed& F2)
{
	return (F1 > F2 ? F1 : F2);
}

