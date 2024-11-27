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
    bool              isExecuted;
    const int         signGrade;
    const int         execGrade;

  protected :
    virtual void  executeAction() const = 0;
  public  :
    AForm();
    AForm(const AForm& F);
    AForm(const std::string& _name, const int _signGrade, const int _execGrade);
    AForm& operator=(const AForm& F);
    virtual   ~AForm();

    class GradeTooHighException : public Bureaucrat::GradeTooHighException{};
    class GradeTooLowException : public Bureaucrat::GradeTooLowException{};
    class FormNotSigned : public std::exception
    {
      public  :
        virtual const char * what() const throw();
    };
    class FormAlreadySigned : public std::exception
    {
      public  :
        virtual const char * what() const throw();
    };
    class FormAlreadyExecuted : public std::exception
    {
      public  :
        virtual const char * what() const throw();
    };

    void        execute(Bureaucrat& executor);
    void        beSigned(Bureaucrat& executor);

    const std::string&  getName( void ) const;
    bool                getSignatureState( void ) const;
    bool                getExecutionState( void ) const;
    int                 getSignGrade( void ) const;
    int                 getExecGrade( void ) const;
};

std::ostream& operator<<(std::ostream& os, const AForm& F);

#endif