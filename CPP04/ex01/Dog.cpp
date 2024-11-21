/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:54:35 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/18 19:03:18 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog default Constructor called\n";
    setType("Dog");
    brain = new Brain;
}

Dog& Dog::operator=(const Dog& D)
{
    if (this != &D)
    {
        std::cout << "Dog assignment copy operator called\n";   
        setType(D.getType());
        delete brain;
        brain = new Brain(*(D.brain));
    }
    return (*this);
}

Dog::Dog(const Dog& D) : Animal(D)
{
    std::cout << "Dog Copy constructor called\n";
    setType(D.getType());
    brain = new Brain(*(D.brain));
}

Dog::~Dog() 
{
    delete brain;
    std::cout << "Dog Destructor called\n";
}

void    Dog::makeSound() const
{
    std::cout << "* WOOF WOOF *\n";
}

void    Dog::setIdea(const std::string& _idea, unsigned int idx)
{
    brain->setIdea(_idea, idx);
}

const std::string& Dog::getIdea(unsigned int idx) const
{
    return (brain->getIdea(idx));
}
