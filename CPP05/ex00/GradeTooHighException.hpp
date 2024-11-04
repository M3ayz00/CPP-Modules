/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:35:49 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/22 16:07:31 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADETOOHIGHEXCEPTION
#define GRADETOOHIGHEXCEPTION

#include <iostream>

class GradeTooHighException : public std::exception
{
    public  :
        const char * what() const throw()
        {
            return ("Grade is too high.\n");
        }
};

#endif