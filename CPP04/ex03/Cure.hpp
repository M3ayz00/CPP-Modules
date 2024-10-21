/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:07:32 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/21 19:08:02 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "Character.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        Cure(const Cure& C);
        ~Cure();
        Cure&       operator=(const Cure& C);


        AMateria*   clone() const;
        void        use(ICharacter& target);
};

#endif