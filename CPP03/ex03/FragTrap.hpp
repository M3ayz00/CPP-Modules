/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m3ayz00 <m3ayz00@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:48:20 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/16 00:00:18 by m3ayz00          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class   FragTrap : virtual public ClapTrap
{
    public  :
        FragTrap();
        FragTrap(const std::string& _name);
        FragTrap(const FragTrap& F);
        ~FragTrap();

        FragTrap&   operator=(const FragTrap& F);
        void        attack(const std::string& target);
        void        highFivesGuys(void) const;
        void        guardGate() const;

        unsigned int    getHp(void) const;
        unsigned int    getAd(void) const;
};

#endif