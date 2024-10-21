/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:52:07 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/21 14:58:36 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default Constructor called\n";
}


Brain&  Brain::operator=(const Brain& B)
{
    if (this != &B)
    {
        std::cout << "Brain assignment copy consytructor called\n";
        for(int i = 0; i < 100; i++)
            ideas[i] = B.ideas[i];
    }
    return (*this);
}

Brain::Brain(const Brain& B)
{
    *this = B;
    std::cout << "Brain copy constructor called\n";
}

Brain::~Brain()
{
    std::cout << "Brain destructor called\n";
}
