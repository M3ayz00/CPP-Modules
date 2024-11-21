/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:29:38 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/08 18:10:21 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("default")
{
    std::cout << "Character default constructor called\n";
    for (int i = 0; i < 4; i++)
    {
        slot[i] = NULL;
        toRecover[i] = NULL;
    }
}

Character::Character(const std::string& _name) : name(_name)
{
    std::cout << "Character constructor called\n";
    for (int i = 0; i < 4; i++)
    {
        slot[i] = NULL;
        toRecover[i] = NULL;
    }
}


Character& Character::operator=(const Character& C)
{
    std::cout << "Character assignment copy operator called\n";
    if (this != &C)
    {
        name = C.name;
        for (int i = 0; i < 4; i++)
        {
            delete slot[i];
            if (C.slot[i])
                slot[i] = C.slot[i]->clone();
            else
                slot[i] = NULL;
            delete toRecover[i];
            if (C.toRecover[i])
                toRecover[i] = C.toRecover[i]->clone();
            else
                toRecover[i] = NULL;
        }
    }
    return (*this);
}

Character::Character(const Character& C) : name(C.name)
{
    std::cout << "Character copy constructor called\n";
    for (int i = 0; i < 4; i++)
    {
        if (C.slot[i])
            slot[i] = C.slot[i]->clone();
        else
            slot[i] = NULL;
        if (C.toRecover[i])
            toRecover[i] = C.toRecover[i]->clone();
        else
            toRecover[i] = NULL;
    }
}

Character::~Character()
{
    std::cout << "Character Destructor called\n";
    for (int i = 0; i < 4; i++)
    {
        delete slot[i];
        delete toRecover[i];
    }
}

std::string const& Character::getName() const
{
    return (name);
}

void    Character::equip(AMateria* m)
{
    if (m)
    {
        for (int i = 0;  i < 4; i++)
        {
            if (slot[i] == NULL)
            {
                if (inSlots(m))
                    slot[i] = m->clone();
                else
                    slot[i] = m;
                std::cout << "Materia " + m->getType() + " is equipped at index " << i << std::endl;
                return ;
            }
        }
        std::cout << "Can't equip materia : Materia's slots are full\n";
    }
    else
        std::cout << "Can't equip an invalid materia\n";
}

void    Character::unequip(int idx)
{
    if ((idx >= 0 && idx <= 3) && slot[idx])
    {
        std::cout << "Materia " + slot[idx]->getType() + " is unequipped at index " << idx << std::endl;
        toRecover[idx] = slot[idx];
        slot[idx] = NULL;
    }
    else if (idx < 0 || idx > 4)
        std::cout << "Can't equip a materia at an invalid index of " << idx << std::endl;
    else
        std::cout << "Can't unequip an unexisting materia\n";
}

void    Character::use(int idx, ICharacter& target)
{
    if ((idx >= 0 && idx <= 3) && slot[idx])
        slot[idx]->use(target);
    else if (idx < 0 || idx > 3)
        std::cout << "Can't use a materia at an invalid index of " << idx << std::endl;
    else
        std::cout << "Can't use an unexisting materia\n";
}

bool Character::inSlots(AMateria *a)
{
    for (int i = 0; i < 4; i++)
    {
        if (slot[i] == a)
            return (true);
    }
    return (false);
}