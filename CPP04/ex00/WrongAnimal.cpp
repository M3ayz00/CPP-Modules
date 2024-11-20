/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:47:55 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/18 18:26:23 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "WrongAnimal default Constructor called\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& A)
{
    if (this != &A)
    {
        std::cout << "WrongAnimal assignment copy operator called\n";
        setType(A.getType());
    }
    return (*this);
}

WrongAnimal::WrongAnimal(const WrongAnimal& A)
{
    std::cout << "WrongAnimal Copy constructor called\n";
    setType(A.getType());
}


WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called\n";
}


void    WrongAnimal::makeSound() const
{
    std::cout << "* WRONG ANIMAL SOUNDS *\n";
}

const std::string& WrongAnimal::getType() const
{
    return (type);
}

void    WrongAnimal::setType(const std::string& _type)
{
    type = _type;
}