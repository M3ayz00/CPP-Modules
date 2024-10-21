/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:54:35 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/21 16:33:31 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog default Constructor called\n";
    type = "Dog";
    brain = new Brain;
}

Dog& Dog::operator=(const Dog& D)
{
    if (this != &D)
    {
        std::cout << "Dog assignment copy operator called\n";   
        Animal::operator=(D);
    }
    return (*this);
}

Dog::Dog(const Dog& D) : Animal(D)
{
    std::cout << "Dog Copy constructor called\n";
}


Dog::~Dog() 
{
    std::cout << "Dog Destructor called\n";
    delete brain;
}

void    Dog::makeSound() const
{
    std::cout << "*RUFF RUFF*\n";
}