/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:47:55 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/18 19:01:50 by msaadidi         ###   ########.fr       */
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
        setType(A.getType());
    }
    return (*this);
}

Animal::Animal(const Animal& A)
{
    std::cout << "Animal Copy constructor called\n";
    setType(A.getType());
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

void    Animal::setType(const std::string& _type)
{
    type = _type;
}

std::string to_string(int nb)
{
    std::ostringstream ss;
    ss << nb;
    return ss.str();
}