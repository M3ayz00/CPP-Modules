/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:54:17 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/18 19:08:02 by msaadidi         ###   ########.fr       */
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
    setType(C.getType());
    brain = new Brain(*(C.brain));
}

Cat& Cat::operator=(const Cat& C)
{
    if (this != &C)
    {
        std::cout << "Cat assignment copy operator called\n";
        setType(C.getType());
        delete brain;
        brain = new Brain(*(C.brain));
    }
    return (*this);
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat Destructor called\n";
}

void    Cat::makeSound() const
{
    std::cout << "* MEOOOOW *\n";
}

void    Cat::setIdea(const std::string& _idea, unsigned int idx)
{
    brain->setIdea(_idea, idx);
}

const std::string& Cat::getIdea(unsigned int idx) const
{
    return (brain->getIdea(idx));
}
