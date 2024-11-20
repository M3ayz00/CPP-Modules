/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:52:07 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/18 19:09:03 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default Constructor called\n";
    for(int i = 0; i < 100; i++)
        setIdea("idea " + to_string(i + 1), i);
}

Brain&  Brain::operator=(const Brain& B)
{
    if (this != &B)
    {
        std::cout << "Brain assignment copy consytructor called\n";
        for(int i = 0; i < 100; i++)
            setIdea(B.getIdea(i), i);
    }
    return (*this);
}

Brain::Brain(const Brain& B)
{
    std::cout << "Brain copy constructor called\n";
    for(int i = 0; i < 100; i++)
        setIdea(B.getIdea(i), i);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called\n";
}

void    Brain::setIdea(const std::string& idea, unsigned int index)
{
    ideas[index] = idea;
}

const std::string& Brain::getIdea(unsigned int index) const
{
    return (ideas[index]);
}
