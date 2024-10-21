/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:54:17 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/21 14:48:18 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat default Constructor called\n";
    type = "Cat";
    brain = new Brain;
}

Cat::Cat(const Cat& C) : Animal(C)
{
    std::cout << "Cat Copy constructor called\n";
}

Cat& Cat::operator=(const Cat& C)
{
    if (this != &C)
    {
        std::cout << "Cat assignment copy constructor called\n";   
        Animal::operator=(C);
    }
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called\n";
}

void    Cat::makeSound() const
{
    std::cout << "*MEOOOOW*\n";
    delete brain;
}