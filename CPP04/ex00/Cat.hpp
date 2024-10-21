/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:49:49 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/21 14:36:33 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
    public  :
        Cat();
        Cat(const Cat& A);
        Cat& operator=(const Cat& A);
        ~Cat();
        
        void    makeSound( void ) const;
};

#endif