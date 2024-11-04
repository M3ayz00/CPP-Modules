/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:15:32 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/22 16:38:38 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"

class Bureaucrat
{
    private:
        const std::string   name;
        uint16_t            grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string& _name, uint16_t _grade);
        Bureaucrat(const Bureaucrat& B);
        Bureaucrat& operator=(const Bureaucrat& B);
        ~Bureaucrat();

        const std::string&  getName() const;
        uint16_t            getGrade() const;
        void                incGrade();
        void                decGrade();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& B);



#endif