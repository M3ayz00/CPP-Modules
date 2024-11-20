/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:49:49 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/18 18:27:16 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public  :
        WrongCat();
        WrongCat(const WrongCat& A);
        WrongCat& operator=(const WrongCat& A);
        ~WrongCat();
        
        void    makeSound( void ) const;
};

#endif