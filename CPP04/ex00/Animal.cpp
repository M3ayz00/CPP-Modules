/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:47:55 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/21 16:33:31 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal default Constructor called\n";
}

Animal& Animal::operator=(const Animal& A)
{
    if (this != &A)
    {
        std::cout << "Animal assignment copy operator called\n";
        type = A.type;
    }
    return (*this);
}

Animal::Animal(const Animal& A)
{
    std::cout << "Animal Copy constructor called\n";
    *this = A;
}


Animal::~Animal()
{
    std::cout << "Animal Destructor called\n";
}


void    Animal::makeSound() const
{
    std::cout << "* ANIMAL SOUNDS *\n";
}

const std::string& Animal::getType() const
{
    return (type);
}