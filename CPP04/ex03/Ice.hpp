/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:23:12 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/21 19:07:51 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "Character.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice(const Ice& I);
        ~Ice();
        Ice&        operator=(const Ice& I);
        
        AMateria*   clone() const;
        void        use(ICharacter& target);
};

#endif