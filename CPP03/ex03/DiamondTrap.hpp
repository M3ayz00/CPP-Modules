/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:39:49 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/20 17:58:41 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class   DiamondTrap : public ScavTrap, public FragTrap
{
    private :
        std::string    name;
    public  :
        DiamondTrap();
        DiamondTrap(const std::string& _name);
        DiamondTrap(const DiamondTrap& F);
        ~DiamondTrap();

        DiamondTrap&   operator=(const DiamondTrap& F);
        void        whoAmI(void);

};

#endif