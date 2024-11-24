/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:55:23 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/24 19:14:17 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

#include "Bureaucrat.hpp"

class Form
{
  private :
    const std::string name;
    bool              isSigned;
    const int         signGrade;
    const int         execGrade;

  public  :
    Form();
    Form(const Form& F);
    Form(const std::string& _name, const int _signGrade, const int _execGrade);
    Form& operator=(const Form& F);
    ~Form();

    class GradeTooHighException : public Bureaucrat::GradeTooHighException{};
    class GradeTooLowException : public Bureaucrat::GradeTooLowException{};
    
    void                beSigned(Bureaucrat& B);

    const std::string&  getName( void ) const;
    bool                getIsSigned( void ) const;
    int                 getSignGrade( void ) const;
    int                 getExecGrade( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Form& F);

#endif