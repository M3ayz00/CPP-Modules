/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:48:01 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/18 18:32:03 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    protected   :
        std::string type;

    public      :
        WrongAnimal();
        WrongAnimal(const WrongAnimal& A);
        WrongAnimal& operator=(const WrongAnimal& A);
        virtual ~WrongAnimal();

        void        makeSound( void ) const;

        const std::string&  getType() const;
        void                setType(const std::string& _type);
};


#endif