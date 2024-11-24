/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:15:32 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/24 19:24:10 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <sstream>

class AForm;

class Bureaucrat
{
  private:
    const std::string   name;
    int            grade;
  public:
    class GradeTooHighException : public std::exception
    {
      public  :
      virtual const char * what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
      public  :
      virtual const char * what() const throw();
    };

    Bureaucrat();
    Bureaucrat(const std::string& _name, int _grade);
    Bureaucrat(const Bureaucrat& B);
    Bureaucrat& operator=(const Bureaucrat& B);
    ~Bureaucrat();

    void  signForm(AForm& F);

    const std::string&  getName() const;
    int                 getGrade() const;
    void                incGrade();
    void                decGrade();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& B);
std::ostream& operator<<(std::ostream& os, Bureaucrat* B);
std::string to_string(int nb);


#endif