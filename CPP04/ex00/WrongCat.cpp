/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:54:17 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/18 18:28:33 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    type = "WrongCat";
    std::cout << "WrongCat default Constructor called\n";
}

WrongCat::WrongCat(const WrongCat& C) : WrongAnimal(C)
{
    std::cout << "WrongCat Copy constructor called\n";
}

WrongCat& WrongCat::operator=(const WrongCat& C)
{
    if (this != &C)
    {
        std::cout << "WrongCat assignment copy operator called\n";   
        setType(C.getType());
    }
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called\n";
}

void    WrongCat::makeSound() const
{
    std::cout << "* WRONG MEOOOOW *\n";
}