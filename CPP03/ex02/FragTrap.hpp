/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:48:20 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/20 17:35:34 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class   FragTrap : public ClapTrap
{
    public  :
        FragTrap();
        FragTrap(const std::string& _name);
        FragTrap(const FragTrap& F);
        ~FragTrap();

        FragTrap&   operator=(const FragTrap& F);
        void        highFivesGuys(void);

};

#endif