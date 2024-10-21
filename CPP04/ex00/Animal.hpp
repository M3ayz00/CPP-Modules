/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:48:01 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/21 14:43:12 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected   :
        std::string type;

    public      :
        Animal();
        Animal(const Animal& A);
        Animal& operator=(const Animal& A);
        ~Animal();

        const std::string&  getType() const;

        virtual void        makeSound( void ) const;
};


#endif