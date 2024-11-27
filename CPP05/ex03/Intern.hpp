/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:39:21 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/27 15:55:11 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
  public  :
    Intern();
    Intern(const Intern& I);
    ~Intern();
    Intern& operator=(const Intern& I);

    AForm*  makeForm(std::string formName, std::string formTarget);

    static AForm*       createShrubberyCreationForm(const std::string& _target);
    static AForm*       createRobotomyRequestForm(const std::string& _target);
    static AForm*       createPresidentialPardonForm(const std::string& _target);
};

#endif