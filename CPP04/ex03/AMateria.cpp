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

AMateria::AMateria() : type("default")
{
    std::cout << "AMateria default constructor called\n";
}

AMateria::AMateria(std::string const& _type) : type(_type)
{
    std::cout << "AMateria constructor called\n";
}
    
AMateria&   AMateria::operator=(const AMateria& A)
{
    if (this != &A)
    {
        std::cout << "AMateria assignment copy operator called\n";
        setType(A.getType());
    }
    return (*this);
}

AMateria::AMateria(const AMateria& A)
{
    std::cout << "AMateria copy constructor called\n";
    setType(A.getType());
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor called\n";
}

void AMateria::use(ICharacter& target)
{
    (void) target;
    std::cout << "...\n";
}

const std::string& AMateria::getType() const
{
    return (type);
}

void    AMateria::setType( std::string const& _type)
{
    type = _type;
}
