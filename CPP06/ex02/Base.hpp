/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:15:34 by msaadidi          #+#    #+#             */
/*   Updated: 2024/12/01 16:39:30 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

class Base
{
  public:
    Base();
    virtual ~Base();
};

class A : public Base {
  public  :
    A();
};
class B : public Base {
  public  :
    B();
};class C : public Base {
  public  :
    C();
};
Base* generate(void);
void  identify(Base* p);
void  identify(Base& p);

#endif