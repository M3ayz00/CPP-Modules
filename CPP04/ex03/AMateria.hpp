/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:55:46 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/22 11:03:41 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class   ICharacter;

class   AMateria
{
    protected   :
        std::string _type;

    public      :
        AMateria();
        AMateria(std::string const& type);
        AMateria(const AMateria& A);
        
        AMateria&           operator=(const AMateria& A);

        std::string const&  getType() const;
        
        virtual             ~AMateria();
        virtual AMateria*   clone() const = 0;
        virtual void        use(ICharacter& target);
};


#endif