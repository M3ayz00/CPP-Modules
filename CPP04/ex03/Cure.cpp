/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:16:48 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/22 11:04:15 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria()
{
    std::cout << "Cure default Constructor called\n";
    setType("cure");
}

Cure::Cure(const Cure& C) : AMateria(C)
{
    std::cout << "Cure copy constructor called\n";
    setType(C.getType());
}

Cure::~Cure()
{
    std::cout << "Cure destructor called\n";
}


Cure&   Cure::operator=(const Cure& C)
{
    std::cout << "Cure copy assignment operator called\n";
    if (this != &C)
        setType(C.getType());
    return (*this);
}

AMateria*   Cure::clone() const
{
    return (new Cure(*this));
}

void    Cure::use(ICharacter& target)
{
    std::cout << "* heals " + target.getName() + "'s wounds *\n";
}