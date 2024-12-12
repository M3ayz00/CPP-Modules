/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:34:49 by msaadidi          #+#    #+#             */
/*   Updated: 2024/12/03 10:37:05 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
  private:
    T             *ptr;
    size_t        arrSize;
  public:
    Array();
    Array(unsigned int _size);
    Array(const Array& arr);
    ~Array();
    Array& operator=(const Array& arr);
    const T& operator[](unsigned int index) const;
    T& operator[](unsigned int index);

    size_t  size( void ) const;
    
};

#include "Array.tpp"

#endif