/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m3ayz00 <m3ayz00@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:19:17 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/15 23:47:27 by m3ayz00          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public  :
        ScavTrap();
        ScavTrap(const std::string& _name);
        ScavTrap(const ScavTrap& S);
        ~ScavTrap();

        ScavTrap&   operator=(const ScavTrap &S);

        void        attack(const std::string& target);
        void        guardGate() const;

        unsigned int getEp(void) const;
};

#endif