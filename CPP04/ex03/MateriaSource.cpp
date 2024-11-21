/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:13:20 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/04 18:17:27 by msaadidi         ###   ########.fr       */
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
    std::cout << "MateriaSource assignment copy operator called\n";
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
    }
    return (*this);
}

MateriaSource::MateriaSource(const MateriaSource& M)
{
    std::cout << "MateriaSource copy constructor called\n"; 
    for (int i = 0; i < 4; i++)
    {
        if (M.materia[i])
            materia[i] = M.materia[i]->clone();
        else
            materia[i] = NULL;
    }
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource Destructor called\n";
    for (int i = 0; i < 4; i++)
        delete materia[i];
}


void    MateriaSource::learnMateria(AMateria* A)
{
    for (int i = 0; (A && i < 4); i++)
    {
        if (materia[i] == NULL)
        {
            if (inSlots(A))
                materia[i] = A->clone();
            else
                materia[i] = A;
            break ;
        }
    }
}

AMateria*   MateriaSource::createMateria(std::string const & type)
{
    for (int i = 3; i >= 0; i--)
    {
        if (materia[i] != NULL && materia[i]->getType() == type)
            return (materia[i]->clone());
    }
    return (0);
}

bool MateriaSource::inSlots(AMateria *a)
{
    for (int i = 0; i < 4; i++)
    {
        if (materia[i] == a)
            return (true);
    }
    return (false);
}