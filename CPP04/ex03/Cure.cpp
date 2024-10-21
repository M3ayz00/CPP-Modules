/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:16:48 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/21 19:07:19 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria(), _type("cure")
{
    std::cout << "Cure default Constructor called\n";
}

Cure::Cure(const Cure& C) : AMateria(C)
{
    std::cout << "Cure copy constructor called\n";
}

Cure::~Cure()
{
    std::cout << "Cure destructor called\n";
}


Cure&   Cure::operator=(const Cure& C)
{
    if (this != &C)
    {
        AMateria::operator=(C);
        std::cout << "Cure copy  called\n"
    }
    return (*this);
}

AMateria*   Cure::clone() const
{
    AMateria* materia = new Cure();
    return (materia);
}

void    Cure::use(ICharacter& target)
{
    std::cout << "*heals " + target.getName() + "'s wounds*\n";
}