/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:13:20 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/21 19:48:33 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource default constructor called\n";
    materia = new AMateria[4];
    for (int i = 0; i < 4; i++)
        materia[i] = nullptr;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& M)
{
    if (this != &M)
    {
        for (int i = 0; i < 4; i++)
        {
            delete materia[i];
            if (M.materia[i])
                materia[i] = M.materia[i].clone()
            else
                materia[i] = nullptr;
        }
        std::cout << "MateriaSource assignment copy operator called\n";
    }
}

MateriaSource::MateriaSource(const MateriaSource& M)
{
    std::cout << "MateriaSource copy constructor called\n";
    *this = M;
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource Destructor called\n";
    for (int i = 0; i < 4; i++)
    {
        if (!materia[i])
            continue;
        delete materia[i];
    }
    delete[] materia;
}


void    MateriaSource::learnMateria(AMateria* A)
{
    for (int i = 0; (A && i < 4); i++)
    {
        if (materia[i])
            continue ;
        materia[i] = A;
        break ;
    }
}

AMateria*   MateriaSource::createMateria(std::string const & type)
{
    if (type.empty())
        return (0);

    AMateria*   M;
    for (int i = 3; i >= 0; i--)
    {
        if (materia[i].getType() == type)
            M = materia[i].clone();
        else
            return (0);
    }
}
