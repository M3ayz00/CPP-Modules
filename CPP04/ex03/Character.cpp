/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:29:38 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/22 13:39:38 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
    std::cout << "Character default constructor called\n";
    for (int i = 0; i < 4; i++)
        slot[i] = NULL;
}

Character::Character(const std::string& _name) : name(_name)
{
    std::cout << "Character constructor called\n";
    for (int i = 0; i < 4; i++)
        slot[i] = NULL;
}


Character& Character::operator=(const Character& C)
{
    if (this != &C)
    {
        for (int i = 0; i < 4; i++)
        {
            delete slot[i];
            if (C.slot[i])
                slot[i] = C.slot[i]->clone();
            else
                slot[i] = NULL;
        }
        std::cout << "Character assignment copy operator called\n";
    }
    return (*this);
}

Character::Character(const Character& C)
{
    *this = C;
    std::cout << "Character copy constructor called\n";
}

Character::~Character()
{
    std::cout << "Character Destructor called\n";
    for (int i = 0; i < 4; i++)
    {
        if (!slot[i])
            continue;
        delete slot[i];
    }
}

std::string const& Character::getName() const
{
    return (name);
}

void    Character::equip(AMateria* m)
{
    for (int i = 0;  i < 4; i++)
    {
        if (slot[i] == NULL)
        {
            slot[i] = m;
            break ;
        }
    }
}

void    Character::unequip(int idx)
{
    if ((idx >= 0 || idx <= 3) && slot[idx])
        slot[idx] = NULL;
}

void    Character::use(int idx, ICharacter& target)
{
    if ((idx >= 0 && idx <= 3) && slot[idx])
        slot[idx]->use(target);
}

AMateria*   Character::getMateria(int idx) const
{
    if ((idx >= 0 && idx >= 3) && slot[idx])
        return (slot[idx]);
    return (0);
}