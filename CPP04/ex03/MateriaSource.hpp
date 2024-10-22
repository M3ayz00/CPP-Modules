/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:53:13 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/22 10:40:02 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class   MateriaSource : public IMateriaSource
{
    private :
        AMateria*   materia[4];

    public  :
        MateriaSource();
        MateriaSource(const MateriaSource& M);
        ~MateriaSource();
        MateriaSource& operator=(const MateriaSource& M);
        
        void        learnMateria(AMateria* A);
        AMateria*   createMateria(std::string const & type);
    
};

#endif