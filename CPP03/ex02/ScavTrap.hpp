/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:19:17 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/20 16:27:24 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public  :
        ScavTrap();
        ScavTrap(const std::string& _name);
        ScavTrap(const ScavTrap& S);
        ~ScavTrap();

        ScavTrap&   operator=(const ScavTrap &S);
        void        guardGate();
};

#endif