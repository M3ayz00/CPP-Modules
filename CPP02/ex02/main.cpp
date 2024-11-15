/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:22:03 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/12 15:31:41 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	// std::cout << ++b << std::endl;
	// std::cout << b++ << std::endl;
	// std::cout << "b : " << b << std::endl;
	// std::cout << "a : " << a << std::endl;
	// std::cout << "b + a : " << b + a << std::endl;
	// std::cout << "b - a : " << b - a << std::endl;
	// std::cout << "b * a : " << b * a << std::endl;
	// std::cout << "b / a : " << b / a << std::endl;
	// std::cout << "a + b : " << a + b << std::endl;
	// std::cout << "a - b : " << a - b << std::endl;
	// std::cout << "a * b : " << a * b << std::endl;
	// std::cout << "a / b : " << a / b << std::endl;
	return 0;
}
