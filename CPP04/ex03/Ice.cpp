/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:22:29 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/21 19:07:24 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria(), _type("ice")
{
    std::cout << "Ice default Constructor called\n";
}

Ice::Ice(const Ice& I) : AMateria(I)
{
    std::cout << "Ice copy constructor called\n";
}

Ice::~Ice()
{
    std::cout << "Ice destructor called\n";
}


Ice&   Ice::operator=(const Ice& I)
{
    if (this != &I)
    {
        AMateria::operator=(I);
        std::cout << "Ice copy assignment operator called\n"
    }
    return (*this);
}

AMateria*   Ice::clone() const
{
    AMateria* materia = new Ice();
    return (materia);
}

void    Ice::use(ICharacter& target)
{
    std::cout << "*shoots an ice bolt at " + target.getName() + " *\n";
}