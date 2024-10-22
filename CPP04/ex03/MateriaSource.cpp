/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:13:20 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/22 12:47:16 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource default constructor called\n";
    for (int i = 0; i < 4; i++)
        materia[i] = NULL;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& M)
{
    if (this != &M)
    {
        for (int i = 0; i < 4; i++)
        {
            delete materia[i];
            if (M.materia[i])
                materia[i] = M.materia[i]->clone();
            else
                materia[i] = NULL;
        }
        std::cout << "MateriaSource assignment copy operator called\n";
    }
    return (*this);
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
        if (materia[i] != NULL)
            delete materia[i];
    }
}


void    MateriaSource::learnMateria(AMateria* A)
{
    for (int i = 0; (A && i < 4); i++)
    {
        if (materia[i] != NULL)
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
    M = 0;
    for (int i = 3; i >= 0; i--)
    {
        if (materia[i] != NULL && materia[i]->getType() == type)
        {
            M = materia[i]->clone();
            return (M);
        }
    }
    return (0);
}

