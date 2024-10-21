/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:29:38 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/21 19:11:59 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
    std::cout << "Character default constructor called\n";
}

Character::Character(const std::string& _name) : name(_name)
{
    std::cout << "Character constructor called\n";
    slot = new AMateria[4];
    for (int i = 0; i < 4; i++)
        inventory[i] = nullptr;
}


Character& Character::operator=(const Character& C)
{
    if (this != &I)
    {
        for (int i = 0; i < 4; i++)
        {
            delete slot[i];
            if (C.slot[i])
                slot[i] = C.slot[i].clone();
            else
                slot[i] = nullptr;
        }
        std:::cout << "Character assignment copy operator called\n";
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
    delete[] slot;
}

std::string const& Character::getName() const
{
    return (name);
}

void    Character::equip(AMateria* m)
{
    for (int i = 0; (m && i < 4); i++)
    {
        if (slot[i])
            continue ;
        slot[i] = m;
        break ;
    }
}

void    Character::unequip(int idx)
{
    if ((idx >= 0 || idx <= 3) && (slot && slot[idx]))
        slot[idx] = nullptr;
}

void    Character::use(int idx, ICharacter& target)
{
    slot[idx].use(target);
    AMateria::use(target);
}
