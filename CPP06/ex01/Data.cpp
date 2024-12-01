/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:21:13 by msaadidi          #+#    #+#             */
/*   Updated: 2024/12/01 15:34:22 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : type("default"), size(1) {}

Data::Data(const Data& D) : type(D.getType()), size(D.getSize()) {}

Data::Data(const std::string& _type, size_t _size) : type(_type), size(_size) {}

Data::~Data() {}

Data& Data::operator=(const Data& D)
{
  if (this != &D)
  {
    setType(D.getType());
    setSize(D.getSize());
  }
  return (*this);
}


void  Data::setType(const std::string& _type)
{
  type = _type;
}

std::string  Data::getType( void ) const
{
  return (type);
}

void  Data::setSize(size_t _size)
{
  size = _size;
}

size_t  Data::getSize( void ) const
{
  return (size);
}
