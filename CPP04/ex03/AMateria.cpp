/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:01:31 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/22 11:03:37 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
    std::cout << "AMateria default constructor called\n";
}

AMateria::AMateria(std::string const& type) : _type(type)
{
    std::cout << "AMateria constructor called\n";
}

    
AMateria&   AMateria::operator=(const AMateria& A)
{
    if (this != &A)
    {
        std::cout << "AMateria assignment copy operator called\n";
        _type = A._type;
    }
    return (*this);
}

AMateria::AMateria(const AMateria& A)
{
    *this = A;
    std::cout << "AMateria copy constructor called\n";
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor called\n";
}

void AMateria::use(ICharacter& target)
{
    std::cout << "...\n" + target.getName();
}

std::string const& AMateria::getType() const
{
    return (_type);
}
