/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooLowException.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:38:43 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/22 16:07:29 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADETOOLOWEXCEPTION
#define GRADETOOLOWEXCEPTION

#include "Bureaucrat.hpp"
#include <iostream>

class GradeTooLowException : public std::exception
{
    public  :
        const char * what() const throw()
        {
            return ("Grade is too low.\n");
        }
};

#endif