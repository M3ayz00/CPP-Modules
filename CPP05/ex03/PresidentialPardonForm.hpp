/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 02:28:38 by m3ayz00           #+#    #+#             */
/*   Updated: 2024/11/25 15:57:25 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESEDENTIALPARDONFORM_HPP
#define PRESEDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
  private :
    std::string target;

  public  :
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& PPF);
    ~PresidentialPardonForm();
    PresidentialPardonForm&  operator=(const PresidentialPardonForm& PPF);
    
    void  executeAction() const;
    
};

#endif