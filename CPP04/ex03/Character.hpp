/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:14:30 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/22 12:55:36 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria*   slot[4];
        AMateria*   toRecover[4];

    public:
        Character();
        Character(const std::string& _name);
        Character(const Character& C);
        Character&  operator=(const Character& C);
        ~Character();
        void                equip(AMateria* m);
        void                unequip(int idx);
        void                use(int idx, ICharacter& target);
        std::string const&  getName() const;

        bool inSlots(AMateria *a);
};



#endif