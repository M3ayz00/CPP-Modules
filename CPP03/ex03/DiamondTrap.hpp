/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:39:49 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/15 17:16:44 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class   DiamondTrap : public FragTrap, public ScavTrap
{
    private :
        std::string    name;
    public  :
        DiamondTrap();
        DiamondTrap(const std::string& _name);
        DiamondTrap(const DiamondTrap& F);
        ~DiamondTrap();

        DiamondTrap&   operator=(const DiamondTrap& F);
        void        attack(const std::string& target);
        void        whoAmI(void) const;
};

#endif