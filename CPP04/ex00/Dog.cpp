/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:54:35 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/18 18:28:36 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    type = "Dog";
    std::cout << "Dog default Constructor called\n";
}

Dog::Dog(const Dog& D) : Animal(D)
{
    std::cout << "Dog Copy constructor called\n";
}

Dog& Dog::operator=(const Dog& D)
{
    if (this != &D)
    {
        std::cout << "Dog assignment copy operator called\n";   
        setType(D.getType());
    }
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called\n";
}

void    Dog::makeSound() const
{
    std::cout << "* WOOF WOOF *\n";
}