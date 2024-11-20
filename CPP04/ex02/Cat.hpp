/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:49:49 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/21 14:47:27 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private :
        Brain   *brain;
    public  :
        Cat();
        Cat(const Cat& A);
        Cat& operator=(const Cat& A);
        ~Cat();
        
        void    makeSound( void ) const;

        void                setIdea(const std::string& _idea, unsigned int idx);
        const std::string&  getIdea(unsigned int idx) const;
};

#endif