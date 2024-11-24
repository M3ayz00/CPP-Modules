/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:55:23 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/24 19:14:17 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

#include "Bureaucrat.hpp"

class AForm
{
  private :
    const std::string name;
    bool              isSigned;
    const int         signGrade;
    const int         execGrade;

  public  :
    AForm();
    AForm(const AForm& F);
    AForm(const std::string& _name, const int _signGrade, const int _execGrade);
    AForm& operator=(const AForm& F);
    ~AForm();

    class GradeTooHighException : public Bureaucrat::GradeTooHighException{};
    class GradeTooLowException : public Bureaucrat::GradeTooLowException{};
    
    virtual void        beSigned(Bureaucrat& B) = 0;

    const std::string&  getName( void ) const;
    bool                getIsSigned( void ) const;
    int                 getSignGrade( void ) const;
    int                 getExecGrade( void ) const;
};

std::ostream& operator<<(std::ostream& os, const AForm& F);

#endif