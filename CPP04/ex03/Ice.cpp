/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:22:29 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/22 11:03:58 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria()
{
    std::cout << "Ice default Constructor called\n";
    setType("ice");
}

Ice::Ice(const Ice& I) : AMateria(I)
{
    std::cout << "Ice copy constructor called\n";
    setType(I.getType());
}

Ice::~Ice()
{
    std::cout << "Ice destructor called\n";
}

Ice&   Ice::operator=(const Ice& I)
{
    if (this != &I)
    {
        setType(I.getType());
        std::cout << "Ice copy assignment operator called\n";
    }
    return (*this);
}

AMateria*   Ice::clone() const
{
    return (new Ice(*this));
}

void    Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " + target.getName() + " *\n";
}