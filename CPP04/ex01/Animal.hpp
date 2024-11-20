/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:48:01 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/18 19:01:41 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <sstream>

class Animal
{
    protected   :
        std::string type;

    public      :
        Animal();
        Animal(const Animal& A);
        Animal& operator=(const Animal& A);
        virtual ~Animal();

        virtual void        makeSound( void ) const;

        const std::string&  getType() const;
        void                setType(const std::string& _type);
};

std::string to_string(int nb);


#endif